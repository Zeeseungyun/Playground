// Fill out your copyright notice in the Description page of Project Settings.


#include "ZeeNetClient.h"
#include "Networking.h"
#include "Algo/BinarySearch.h"
#include "Misc/CoreDelegates.h"
#include "Misc/App.h"
#include "Misc/ScopeExit.h"

#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetNotifyHandler.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h"

/*static*/ TSharedPtr<FZeeNetClient> FZeeNetClient::MakeClient()
{
	return TSharedPtr<FZeeNetClient>(new FZeeNetClient());
}

FZeeNetClient::FZeeNetClient()
	: InBuffer {}
	, OutBuffer {}
{
	bIsDeadThis = false;
	bIsThreadDone = true;
	if (ValidNotifyHandlerNames.Num() == 0)
	{
		BuildValidNotifyHandlerNames();
	}

	if (ValidRequestHandlerNames.Num() == 0)
	{
		BuildValidRequestHandlerNames();
	}

}

FZeeNetClient::~FZeeNetClient()
{
	bIsDeadThis = true;
	Shutdown();
	if (Thread.IsValid())
	{
		Thread->WaitForCompletion();
	}
}

void FZeeNetClient::TryConnect(const FString& InEndPoint)
{
	if (!bIsThreadDone)
	{
		ExecuteConnectEvent(FString::Printf(TEXT("working.[%s]"), *ClientName));
		return;
	}

	bIsThreadDone = false;
	EndPoint = InEndPoint;
	ClientName = FString::Printf(TEXT("FZeeNetClient(%s)"), *EndPoint);
	Thread = TUniquePtr<FRunnableThread>(FRunnableThread::Create(this, *ClientName));
}

void FZeeNetClient::ExecuteDisconnectedEvent()
{
	UE_LOG(LogZeeNet, Log, TEXT("ExecuteDisconnectEvent called."));
	if (IsInGameThread())
	{
		OnDisconnected().Broadcast();
	}
	else
	{
		TWeakPtr<FZeeNetClient> WeakThisPtr = AsShared();
		AsyncTask(ENamedThreads::Type::GameThread, [WeakThisPtr]()
			{
				TSharedPtr<FZeeNetClient> StrongThis = WeakThisPtr.Pin();
				if (StrongThis.IsValid())
				{
					StrongThis->OnDisconnected().Broadcast();
				}
			}
		);
	}
}

bool FZeeNetClient::IsConnected() const
{
	FScopeLock Lock(&MtxSocket);
	return Thread.IsValid() && Socket.IsValid() && Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected;
}

void FZeeNetClient::ExecuteConnectEvent(const FString& InMessage)
{
	UE_LOG(LogZeeNet, Log, TEXT("ExecuteConnectEvent called. [%s]"), *InMessage);

	if (IsInGameThread())
	{
		OnConnected().Broadcast(InMessage);
	}
	else
	{
		TWeakPtr<FZeeNetClient> WeakThisPtr = AsShared();
		AsyncTask(ENamedThreads::Type::GameThread, [WeakThisPtr, Message = InMessage]()
			{
				TSharedPtr<FZeeNetClient> StrongThis = WeakThisPtr.Pin();
				if (StrongThis.IsValid())
				{
					StrongThis->OnConnected().Broadcast(Message);
				}
			}
		);
	}

}

void FZeeNetClient::Shutdown()
{
	if (Socket.IsValid())
	{
		Socket->Shutdown(ESocketShutdownMode::ReadWrite);
		Socket->Close();
	}
}

void FZeeNetClient::ShutdownSocket()
{
	UE_LOG(LogTemp, Warning, TEXT("ZeeLog, Last Socket Error[%s]"), ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetSocketError());
	Shutdown();
}

//~begin FRunnable Interface

bool FZeeNetClient::Init()
{
	UE_LOG(LogZeeNet, Warning, TEXT("Init called."));
	return true;
}

uint32 FZeeNetClient::Run()
{
	FString TempClientName = ClientName;
	UE_LOG(LogZeeNet, Warning, TEXT("worker thread function begin[%s]."), *TempClientName);
	ON_SCOPE_EXIT
	{
		UE_LOG(LogZeeNet, Warning, TEXT("worker thread function end[%s]."), *TempClientName);
	};

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateUniqueSocket(NAME_Stream, *TempClientName);

	if (!BeginFrameDelegate.IsValid())
	{
		BeginFrameDelegate = FCoreDelegates::OnBeginFrame.AddThreadSafeSP(AsShared(), &FZeeNetClient::ConsumeMessages);
	}

	bool bSuccess = false;
	FIPv4Endpoint EndPointv4;
	if (FIPv4Endpoint::Parse(EndPoint, EndPointv4))
	{
		bSuccess = Socket->Connect(*EndPointv4.ToInternetAddr());
	}

	if (bSuccess)
	{
		ExecuteConnectEvent(TEXT(""));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ZeeLog, Last Socket Error[%s]"), ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetSocketError());
		if (BeginFrameDelegate.IsValid())
		{
			FCoreDelegates::OnBeginFrame.Remove(BeginFrameDelegate);
			BeginFrameDelegate.Reset();
		}

		Socket->Close();
		Socket = nullptr;
		ExecuteConnectEvent(TEXT("connection failed."));
		return -1;
	}

	while (IsConnected())
	{
		DoRecv();
	}

	if (BeginFrameDelegate.IsValid())
	{
		FCoreDelegates::OnBeginFrame.Remove(BeginFrameDelegate);
		BeginFrameDelegate.Reset();
	}

	{
		FScopeLock Lock(&MtxSocket);
		ShutdownSocket();
		Socket = nullptr;
	}

	if (!bIsDeadThis)
	{
		ExecuteDisconnectedEvent();
	}

	return 0;
}

void FZeeNetClient::Stop()
{
	Shutdown();
}

void FZeeNetClient::Exit()
{
	bIsThreadDone = true;
}

//~end FRunnable Interface

bool FZeeNetClient::RegisterNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& NewHandler)
{
	ValidateNotifyHandlers();

	if (!NewHandler.IsValid())
	{
		return false;
	}

	if (IsInNotifyHandler(NewHandler))
	{
		return true;
	}

	NotifyHandlers.FindOrAdd(NewHandler->GetHandlerName()).Add(NewHandler);
	return true;
}

void FZeeNetClient::UnregisterNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& NewHandler)
{
	bool bWasRemoved = false;
	if (!NewHandler.IsValid())
	{
		return;
	}

	checkf(ValidNotifyHandlerNames.Contains(NewHandler->GetHandlerName()), TEXT("invalid handler name. %s"), *NewHandler->GetHandlerName());

	TArray<TWeakPtr<struct IZeeNetNotifyHandler>>* const FoundHandlers = NotifyHandlers.Find(NewHandler->GetHandlerName());
	if (!FoundHandlers)
	{
		return;
	}

	TArray<TWeakPtr<struct IZeeNetNotifyHandler>>& Handlers = *FoundHandlers;
	for (int32 i = 0; i != Handlers.Num();)
	{
		if (!Handlers[i].IsValid())
		{
			Handlers.RemoveAt(i);
		}
		else if(Handlers[i].Pin() == NewHandler)
		{
			Handlers.RemoveAt(i);
			return;
		}
		else
		{
			++i;
		}
	}
}

bool FZeeNetClient::IsInNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& InHandler) const
{
	if (!InHandler.IsValid())
	{
		return false;
	}

	checkf(ValidNotifyHandlerNames.Contains(InHandler->GetHandlerName()), TEXT("invalid handler name. %s"), *InHandler->GetHandlerName());

	const TArray<TWeakPtr<struct IZeeNetNotifyHandler>>* const FoundHandlers = NotifyHandlers.Find(InHandler->GetHandlerName());
	if (!FoundHandlers)
	{
		return false;
	}

	for (const TWeakPtr<struct IZeeNetNotifyHandler>& Elem : *FoundHandlers)
	{
		if (!Elem.IsValid())
		{
			continue;
		}

		if (Elem.Pin() == InHandler)
		{
			return true;
		}
	}

	return false;
}

TSet<FString> FZeeNetClient::ValidNotifyHandlerNames;

void FZeeNetClient::ValidateNotifyHandlers()
{
	for (auto& Elem : NotifyHandlers)
	{
		TArray<TWeakPtr<struct IZeeNetNotifyHandler>>& Handlers = Elem.Value;
		for (int32 i = 0; i < Handlers.Num();)
		{
			if (!Handlers[i].IsValid())
			{
				Handlers.RemoveAt(i);
			}
			else
			{
				++i;
			}
		}
	}
}

static bool RequestHandlersPredicate(const TWeakPtr<struct IZeeNetRequestHandler>& Lhs, const TWeakPtr<struct IZeeNetRequestHandler>& Rhs)
{
	return Lhs.Pin()->GetPriority() < Rhs.Pin()->GetPriority();
}

bool FZeeNetClient::RegisterRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& NewHandler)
{
	ValidateRequestHandlers();

	if (!NewHandler.IsValid())
	{
		return false;
	}

	if (IsInRequestHandler(NewHandler))
	{
		return true;
	}

	TArray<TWeakPtr<struct IZeeNetRequestHandler>>& Handlers = RequestHandlers.FindOrAdd(NewHandler->GetHandlerName());
	static auto Proj = [](const TWeakPtr<struct IZeeNetRequestHandler>& Elem) { return Elem; };
	const int32 Index = Algo::UpperBoundBy(Handlers, NewHandler.ToWeakPtr(), Proj, &RequestHandlersPredicate);
	if (Index == INDEX_NONE)
	{
		Handlers.Add(NewHandler);
	}
	else
	{
		Handlers.Insert(NewHandler, Index);
	}

	return true;
}

void FZeeNetClient::UnregisterRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& NewHandler)
{
	bool bWasRemoved = false;
	if (!NewHandler.IsValid())
	{
		return;
	}

	checkf(ValidRequestHandlerNames.Contains(NewHandler->GetHandlerName()), TEXT("invalid handler name. %s"), *NewHandler->GetHandlerName());

	TArray<TWeakPtr<struct IZeeNetRequestHandler>>* const FoundHandlers = RequestHandlers.Find(NewHandler->GetHandlerName());
	if (!FoundHandlers)
	{
		return;
	}

	TArray<TWeakPtr<struct IZeeNetRequestHandler>>& Handlers = *FoundHandlers;
	for (int32 i = 0; i != Handlers.Num();)
	{
		if (!Handlers[i].IsValid())
		{
			Handlers.RemoveAt(i);
		}
		else if (Handlers[i].Pin() == NewHandler)
		{
			Handlers.RemoveAt(i);
			return;
		}
		else
		{
			++i;
		}
	}
}

bool FZeeNetClient::IsInRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& InHandler) const
{
	if (!InHandler.IsValid())
	{
		return false;
	}

	checkf(ValidRequestHandlerNames.Contains(InHandler->GetHandlerName()), TEXT("invalid handler name. %s"), *InHandler->GetHandlerName());

	const TArray<TWeakPtr<struct IZeeNetRequestHandler>>* const FoundHandlers = RequestHandlers.Find(InHandler->GetHandlerName());
	if (!FoundHandlers)
	{
		return false;
	}

	for (const TWeakPtr<struct IZeeNetRequestHandler>& Elem : *FoundHandlers)
	{
		if (!Elem.IsValid())
		{
			continue;
		}

		if (Elem.Pin() == InHandler)
		{
			return true;
		}
	}

	return false;
}

void FZeeNetClient::ConsumeMessages()
{
	// check request pending packets
	{
		for (int32 i = 0; i < RequestPendingPackets.Num();)
		{
			const FDateTime PacketTime = RequestPendingPackets[i].TimeTick;
			TSharedRef<struct FZeeNetPacketSerializerBase>& Packet = RequestPendingPackets[i].Packet;
			const FTimespan Timespan = FDateTime::Now() - PacketTime;
			if (Timespan.GetTotalSeconds() > GetRequestTimeoutSec())
			{
				UE_LOG(LogZeeNet, Warning, TEXT("request message timeout."));
				Packet->GetHeader().PacketType = EZeeNetPacketType::ResponseTimeout;
				Response_Impl(Packet->GetPacket());
				RequestPendingPackets.RemoveAt(i);
			}
			else
			{
				++i;
			}
		}
	}

	// consume pending packets..
	TArray<FPendingPacket> TempPendingPackets;
	{
		FScopeLock Lock(&MtxPendingPackets);
		TempPendingPackets = MoveTemp(PendingPackets);
	}

	for (FPendingPacket& Elem : TempPendingPackets)
	{
		TSharedRef<struct FZeeNetPacketSerializerBase>& Packet = Elem.Packet;
		switch (Packet->GetHeader().PacketType)
		{
		case EZeeNetPacketType::Response:
		{
			FScopeLock Lock(&MtxCallbackMaps);
			TFunction<void(const void*)>* Found = CallbackMaps.Find(Packet->GetHeader().Sequence);
			check(Found != nullptr);
			(*Found)(Packet->GetMessage());
			CallbackMaps.Remove(Packet->GetHeader().Sequence);
		}
		break;

		case EZeeNetPacketType::Notify:
		{
			if (!ConsumeNotifyMessage(Packet))
			{
				UE_LOG(LogZeeNet, Warning, TEXT("message not consumed."));
			}
		}
		break;

		case EZeeNetPacketType::Request:
		{
			const int32 BeginResponseDirectylySequenceCheck = Packet->GetHeader().Sequence;
			//TODO:: 누가 소비했는지 반환하도록 해야함.
			switch (ConsumeRequestMessage(Packet))
			{
			case EZeeNetRequestHandlerResponse::NoResponse:
			{
				Packet->GetHeader().PacketType = EZeeNetPacketType::NoResponse;
				Response_Impl(Packet->GetPacket());
			}
			break;

			case EZeeNetRequestHandlerResponse::ResponseDirectly:
			{
				//ResponseDirectly으로 반환하는 경우 바로 Response를 호출해야함.
				checkf(ResponseDirectylySequenceCheck.IsSet() && BeginResponseDirectylySequenceCheck == ResponseDirectylySequenceCheck
				, TEXT("handler must be called directly response when return 'ResponseDirectly'"));
			}
			break;

			case EZeeNetRequestHandlerResponse::ResponsePending:
			{
				RequestPendingPackets.Add({ FDateTime::Now().GetTicks(), Packet});
			}
			break;

			default:
				break;
			}
		}
		break;

		default:
			check(0);
			break;
		}
	}
}

TSet<FString> FZeeNetClient::ValidRequestHandlerNames;

void FZeeNetClient::ValidateRequestHandlers()
{
	for (auto& Elem : RequestHandlers)
	{
		TArray<TWeakPtr<struct IZeeNetRequestHandler>>& Handlers = Elem.Value;
		for (int32 i = 0; i < Handlers.Num();)
		{
			if (!Handlers[i].IsValid())
			{
				Handlers.RemoveAt(i);
			}
			else
			{
				++i;
			}
		}
		
		Handlers.Sort(&RequestHandlersPredicate);
	}
}

void FZeeNetClient::DoRecv()
{
	int32 HeaderSize = 0, BytesRead = 0, Offset = 0;
	if (!Socket->Recv(InBuffer, sizeof(HeaderSize), BytesRead))
	{
		ShutdownSocket();
		return;
	}

	check(sizeof(HeaderSize) == BytesRead);
	Offset += BytesRead;

	HeaderSize = *reinterpret_cast<int32*>(InBuffer);
	if (!Socket->Recv(InBuffer + Offset, HeaderSize, BytesRead))
	{
		ShutdownSocket();
		return;
	}
	check(HeaderSize == BytesRead);

	using PacketHeaderSerializerType = FZeeNetPacketSerializer<FZeeNetPacketHeader>;
	PacketHeaderSerializerType Header;
	Header.Deserialize(InBuffer /*+ Offset 내부에서 HeaderSize를 따로 읽음.*/, BytesRead);
	Offset += BytesRead;

	TSharedPtr<FZeeNetPacketSerializerBase> Packet = FZeeNetPacketSerializerMap::CreateSerializer(Header.GetHeader().Point);
	Packet->GetHeader() = Header.GetHeader();

	if (Header.GetHeader().PacketSize > 0)
	{
		if (!Socket->Recv(InBuffer + Offset, Header.GetHeader().PacketSize, BytesRead))
		{
			ShutdownSocket();
			return;
		}
		check(Header.GetHeader().PacketSize == BytesRead);

		Packet->Deserialize(InBuffer + Offset, BytesRead);
	}
	
	{
		FScopeLock Lock(&MtxPendingPackets);
		PendingPackets.Add({ FDateTime::Now().GetTicks(), Packet.ToSharedRef()});
	}
}

bool FZeeNetClient::Send(int32 InPoint, int32 InSequence, EZeeNetPacketType InPacketType, const void* InMessageRawPtr)
{
	TSharedPtr<FZeeNetPacketSerializerBase> Packet = FZeeNetPacketSerializerMap::CreateSerializer(InPoint);
	Packet->SetMessageInternal(InMessageRawPtr);
	Packet->GetHeader().Sequence = InSequence;
	Packet->GetHeader().PacketType = InPacketType;
	
	int32 BytesSent = 0 , BytesWritten = 0;
	{
		BytesWritten = Packet->Serialize(OutBuffer, BufferSize);
		if (!IsConnected())
		{
			return false;
		}

		FScopeLock Lock(&MtxSocket);
		if (!Socket.IsValid())
		{
			return false;
		}

		if (!Socket->Send(OutBuffer, BytesWritten, BytesSent))
		{
			ShutdownSocket();
			return false;
		}
	}

	check(BytesSent == BytesWritten);
	return true;
}

EZeeNetReponseType FZeeNetClient::Response_Impl(const void* InPacketRawPtr) /* final */
{
	const FZeeNetPacketHeader* HeaderPtr = reinterpret_cast<const FZeeNetPacketHeader*>(InPacketRawPtr);
	check( HeaderPtr->PacketType == EZeeNetPacketType::Request 
		|| HeaderPtr->PacketType == EZeeNetPacketType::ResponseTimeout
		|| HeaderPtr->PacketType == EZeeNetPacketType::NoResponse
	);

	if (HeaderPtr->PacketType == EZeeNetPacketType::Request)
	{
		const_cast<FZeeNetPacketHeader*>(HeaderPtr)->PacketType = EZeeNetPacketType::Response;
	}

	const EZeeNetPacketType ResponseType = HeaderPtr->PacketType;
	const int32 MsgPoint = HeaderPtr->Point;
	const int32 MsgSequence = HeaderPtr->Sequence;
	check(HeaderPtr->Point != TZeeNetPacketTraits<FZeeNetPacketHeader>::Point); //must not be packet header.
	++HeaderPtr; //offset move.

	ResponseDirectylySequenceCheck = MsgSequence;

	if (!Send(MsgPoint, MsgSequence, ResponseType, HeaderPtr /*maybe message ptr.*/))
	{
		return EZeeNetReponseType::SocketError;
	}

	return EZeeNetReponseType::Succeess;
}
