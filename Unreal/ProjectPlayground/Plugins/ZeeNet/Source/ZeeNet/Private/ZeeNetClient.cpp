// Fill out your copyright notice in the Description page of Project Settings.


#include "ZeeNetClient.h"
#include "Networking.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetNotifyHandler.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h"

/*static*/ TSharedPtr<FZeeNetClient> FZeeNetClient::MakeClient(const FString& InEndPoint)
{
	return TSharedPtr<FZeeNetClient>(new FZeeNetClient());
}

FZeeNetClient::FZeeNetClient()
	: InBuffer {}
	, OutBuffer {}
{
	if (ValidNotifyHandlerNames.Num() == 0)
	{
		BuildValidNotifyHandlerNames();
	}

	if (ValidRequestHandlerNames.Num() == 0)
	{
		BuildValidRequestHandlerNames();
	}

	Thread = TUniquePtr<FRunnableThread>(FRunnableThread::Create(this, *ClientName));
}

FZeeNetClient::~FZeeNetClient()
{
}

void FZeeNetClient::TryConnect(const FString& InEndPoint)
{
	FScopeLock Lock(&MtxSocket);
	if (Socket && Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected)
	{
		OnConnected().Broadcast(FString::Printf(TEXT("already connected [%s]"), *ClientName));
		return;
	}

	EndPoint = InEndPoint;
	ClientName = FString::Printf(TEXT("FZeeNetClient(%s)"), *EndPoint);

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateUniqueSocket(NAME_Stream, *ClientName);
}

void FZeeNetClient::ExecuteConnectEvent(const FString& InMessage)
{
	AsyncTask(ENamedThreads::Type::GameThread, [=, StrongThis = AsShared()]()
		{
			StrongThis->OnConnected().Broadcast(InMessage);
		}
	);
}

//~begin FRunnable Interface

bool FZeeNetClient::Init()
{
	return true;
}
// 
// std::string error_to_str(
// 	int error_code,
// 	int languageid = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
// {
// 	std::string ret = "";
// 	HLOCAL hLocal = NULL;
// 	FormatMessageA(
// 		FORMAT_MESSAGE_FROM_SYSTEM
// 		| FORMAT_MESSAGE_ALLOCATE_BUFFER,   // flags
// 		nullptr,
// 		error_code,
// 		languageid,
// 		reinterpret_cast<LPSTR>(&hLocal),
// 		0,
// 		NULL
// 	);
// 
// 	ret = reinterpret_cast<const LPSTR>(hLocal);
// 	LocalFree(hLocal);
// 	return ret;
// }

uint32 FZeeNetClient::Run()
{
	//TryConnect 함수 호출을 통해 해당 Socket이 생성되기 전까지 대기.
	while (!Socket)
	{
		FPlatformProcess::Sleep(1.0f);
	}

	bool bSuccess = false;
	FIPv4Endpoint EndPointv4;
	if (FIPv4Endpoint::Parse(EndPoint, EndPointv4))
	{
		FScopeLock Lock(&MtxSocket);
		bSuccess = Socket->Connect(*EndPointv4.ToInternetAddr());
	}

	if (!bSuccess)
	{
		FScopeLock Lock(&MtxSocket);
		Socket->Close();
		Socket = nullptr;
		ExecuteConnectEvent(TEXT("connection failed."));
		return -1;
	}

	ExecuteConnectEvent(TEXT(""));
	while (!bIsStop)
	{
		Recv();
	}

	{
		FScopeLock Lock(&MtxSocket);
		Socket->Shutdown(ESocketShutdownMode::ReadWrite);
		Socket->Close();
		Socket = nullptr;
	}

	return 0;
}

void FZeeNetClient::Stop()
{
	bIsStop = true;
}

void FZeeNetClient::Exit()
{
	Stop();
}

//~end FRunnable Interface

bool FZeeNetClient::RegisterNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& NewHandler)
{
	CheckNotifyHandlers();

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

	checkf(ValidNotifyHandlerNames.Contains(InHandler->GetHandlerName()), TEXT("invalid notify handler name. %s"), *InHandler->GetHandlerName());

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

void FZeeNetClient::CheckNotifyHandlers()
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

bool FZeeNetClient::RegisterRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& NewHandler)
{
	CheckRequestHandlers();

	if (!NewHandler.IsValid())
	{
		return false;
	}

	if (IsInRequestHandler(NewHandler))
	{
		return true;
	}

	//TODO:: 정렬시켜서 삽입해야함.
	// RequestHandlers.FindOrAdd(NewHandler->GetHandlerName()).Add(NewHandler);
	
	return true;
}

void FZeeNetClient::UnregisterRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& NewHandler)
{
	bool bWasRemoved = false;
	if (!NewHandler.IsValid())
	{
		return;
	}

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

	checkf(ValidRequestHandlerNames.Contains(InHandler->GetHandlerName()), TEXT("invalid Request handler name. %s"), *InHandler->GetHandlerName());

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

TSet<FString> FZeeNetClient::ValidRequestHandlerNames;

void FZeeNetClient::CheckRequestHandlers()
{
	// TODO:: 우선순위 기준 정렬
	// RequestHandlers
}


void FZeeNetClient::Recv()
{
	int32 HeaderSize = 0, BytesRead = 0, Offset = 0;
	if (!Socket->Recv(InBuffer, sizeof(HeaderSize), BytesRead))
	{
		check(0);
		return;
	}
	check(sizeof(HeaderSize) == BytesRead);
	Offset += BytesRead;

	if (!Socket->Recv(InBuffer + Offset, HeaderSize, BytesRead))
	{
		check(0);
		return;
	}
	check(HeaderSize == BytesRead);
	Offset += BytesRead;

	using PacketHeaderSerializerType = FZeeNetPacketSerializer<TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point>;
	PacketHeaderSerializerType PacketHeaderSerializer;
	PacketHeaderSerializer.Deserialize(InBuffer, Offset);
	
	if (!Socket->Recv(InBuffer + Offset, PacketHeaderSerializer.GetHeader().PacketSize, BytesRead))
	{
		check(0);
		return;
	}

	check(PacketHeaderSerializer.GetHeader().PacketSize == BytesRead);

	TSharedPtr<FZeeNetPacketSerializerBase> Packet = FZeeNetPacketSerializerMap::CreateSerializer(PacketHeaderSerializer.GetHeader().Point);
	Packet->GetHeader() = PacketHeaderSerializer.GetHeader();

	Packet->Deserialize(InBuffer + Offset, BytesRead);
	
	// {
	// 	FScopeLock Lock(&MtxPendingPackets);
	// 	PendingPackets.Add(Packet);
	// }
	//TODO:: 아랫 쪽 윗 주석 없애서 게임스레드에서 호출되도록 구현해야함.
	switch (Packet->GetHeader().PacketType)
	{
	case EZeeNetPacketType::Response:
		{
			TFunction<void(const void*)>* Found = CallbackMaps.Find(Packet->GetHeader().Sequence);
			check(Found != nullptr);
			(*Found)(Packet->GetMessage());
			CallbackMaps.Remove(Packet->GetHeader().Sequence);
		}
		break;

	case EZeeNetPacketType::Notify:
		{
			//is not game thread..
			ConsumeNotifyMessage(Packet);
		}
		break;

	case EZeeNetPacketType::Request:
		{
			switch (ConsumeRequestMessage(Packet))
			{
			case EZeeNetRequestHandlerResponse::NoResponse:
				{
					Response_Impl(Packet->GetPacket());
				}
				break;

			case EZeeNetRequestHandlerResponse::ResponseDirectly:
				{
					//do nothing..
				}
				break;

			case EZeeNetRequestHandlerResponse::ResponsePending:
				{
					FScopeLock Lock(&MtxRequestPendingPackets);
					RequestPendingPackets.Add(Packet);
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

void FZeeNetClient::Send(int32 InPoint, int32 InSequence, EZeeNetPacketType InPacketType, const void* InMessageRawPtr)
{
	TSharedPtr<FZeeNetPacketSerializerBase> Packet = FZeeNetPacketSerializerMap::CreateSerializer(InPoint);
	Packet->SetMessageInternal(InMessageRawPtr);
	Packet->GetHeader().Sequence = InSequence;
	Packet->GetHeader().PacketType = InPacketType;

	const int32 BytesWrote = Packet->Serialize(OutBuffer, BufferSize);
	int32 BytesSent = 0;
	if (!Socket->Send(OutBuffer, BytesWrote, BytesSent))
	{
		//접속 끊김?
		//TODO:: Shutdown 이후 Close 처리.
		return;
	}
	check(BytesSent == BytesWrote);
}

EZeeNetReponseType FZeeNetClient::Response_Impl(const void* InPacketRawPtr) /* final */
{
	if (!Socket.IsValid())
	{
		return EZeeNetReponseType::SocketError;
	}

	if (Socket->GetConnectionState() != ESocketConnectionState::SCS_Connected)
	{
		return EZeeNetReponseType::SocketError;
	}

	const FZeeNetPacketHeader* HeaderPtr = reinterpret_cast<const FZeeNetPacketHeader*>(InPacketRawPtr);
	check(HeaderPtr->PacketType == EZeeNetPacketType::Request);

	const int32 MsgPoint = HeaderPtr->Point;
	const int32 MsgSequence = HeaderPtr->Sequence;
	check(HeaderPtr->Point != TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point); //must not be packet header.
	HeaderPtr++; //offset move.

	Send(MsgPoint, MsgSequence, EZeeNetPacketType::Response, HeaderPtr /*maybe message ptr.*/);
	return EZeeNetReponseType::Succeess;
}
