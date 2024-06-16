// Fill out your copyright notice in the Description page of Project Settings.


#include "ZeeNetClient.h"
#include "Networking.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializer.h"

#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"

/*static*/ TSharedPtr<FZeeNetClient> FZeeNetClient::MakeClient(const FString& InEndPoint)
{
	return TSharedPtr<FZeeNetClient>(new FZeeNetClient());
}

FZeeNetClient::FZeeNetClient()
	: InBuffer {}
	, OutBuffer {}
{
	Thread = TUniquePtr<FRunnableThread>(FRunnableThread::Create(this, *ClientName));
}

FZeeNetClient::~FZeeNetClient()
{
}

void FZeeNetClient::TryConnect(const FString& InEndPoint)
{
	FScopeLock Lock(&Mtx);
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
		FScopeLock Lock(&Mtx);
		bSuccess = Socket->Connect(*EndPointv4.ToInternetAddr());
	}
	
	if (!bSuccess)
	{
		FScopeLock Lock(&Mtx);
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
		FScopeLock Lock(&Mtx);
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

	using PacketHeaderType = FZeeNetPacket<TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point>;
	PacketHeaderType PacketHeader;
	PacketHeader.Deserialize(InBuffer, Offset);
	
	if (!Socket->Recv(InBuffer + Offset, PacketHeader.Header.PacketSize, BytesRead))
	{
		check(0);
		return;
	}

	check(PacketHeader.Header.PacketSize == BytesRead);

	TSharedPtr<FZeeNetPacketSerializerBase> Packet = FZeeNetPacketSerializerMap::CreateSerializer(PacketHeader.Header.Point);
	Packet->Header = PacketHeader.Header;

	Packet->Deserialize(InBuffer + Offset, BytesRead);

	switch (Packet->GetPacketType())
	{
	case EZeeNetPacketType::Response:
		{
			TFunction<void(const void*)>* Found = CallbackMaps.Find(Packet->GetSequence());
			check(Found != nullptr);
			(*Found)(Packet->GetMessage());
			CallbackMaps.Remove(Packet->GetSequence());
		}
		break;

	case EZeeNetPacketType::Notify:
		{
			//TODO:: INotifyHandler
		}
		break;

	case EZeeNetPacketType::Request:
		{
			//TODO:: IRequestHandler
		}
		break;

	default:
		check(0);
		break;
	}
}

void FZeeNetClient::Send_Impl(int32 InPoint, int32 InSequence, EZeeNetPacketType InPacketType, const void* InData)
{
	TSharedPtr<FZeeNetPacketSerializerBase> Packet = FZeeNetPacketSerializerMap::CreateSerializer(InPoint);
	Packet->SetMessageInternal(InData);
	Packet->SetSequence(InSequence);
	Packet->SetPacketType(InPacketType);
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
