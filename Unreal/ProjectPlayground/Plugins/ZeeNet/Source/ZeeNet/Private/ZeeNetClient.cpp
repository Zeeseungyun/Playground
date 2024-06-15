// Fill out your copyright notice in the Description page of Project Settings.


#include "ZeeNetClient.h"
#include "Networking.h"

/*static*/ TSharedPtr<FZeeNetClient> FZeeNetClient::MakeClient(const FString& InEndPoint)
{
	return TSharedPtr<FZeeNetClient>(new FZeeNetClient());
}

FZeeNetClient::FZeeNetClient()
	: InBuffer{}
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

void FZeeNetClient::Response(const TSharedPtr<FZeeNetPacketBase>& InPacket)
{
	TSharedPtr<FZeeNetPacketBase> Clone = InPacket->Clone();
	Clone->bIsRespond = false;
	Send_Impl(Clone);
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
	//TryConnect �Լ� ȣ���� ���� �ش� Socket�� �����Ǳ� ������ ���.
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
	int32 BytesRead = 0;
	
	{
		int32 Offset = 0;
		if (!Socket->Recv(InBuffer + Offset, sizeof(int32), BytesRead))
		{
			check(0);
			return;
		}

		check(BytesRead == sizeof(int32));
		const int32 TotalSize = *(int32*)InBuffer;
		Offset += sizeof(int32);
		if (!Socket->Recv(InBuffer + Offset, sizeof(int32), BytesRead))
		{
			check(0);
			return;
		}

		check(BytesRead == sizeof(int32));
		const int32 Point = *(int32*)InBuffer;
		Offset += sizeof(int32);
		//������ ���δ� �о����.
		if (!Socket->Recv(InBuffer + Offset, TotalSize - Offset, BytesRead))
		{
			check(0);
			return;
		}

		TSharedPtr<FZeeNetPacketBase> Packet = FZeeNetPacketSerializer::CreatePacketFromBuffer(Point, InBuffer, TotalSize);
		//������ �ٶ�� �޽����� ����.
		if (Packet->bIsRespond)
		{

		}
		else if(Packet->Sequence != 0) //���� �޽�������.
		{
			TFunction<void(const void*)>* Found = CallbackMaps.Find(Packet->Sequence);
			check(Found != nullptr);
			(*Found)(Packet->GetMessage());
			CallbackMaps.Remove(Packet->Sequence);
		}
	}
}

void FZeeNetClient::Send_Impl(const TSharedPtr<FZeeNetPacketBase>& InPacket)
{
	const int32 BytesWrote = InPacket->Serialize(OutBuffer, BufferSize);
	int32 BytesSent = 0;
	if (!Socket->Send(OutBuffer, BytesWrote, BytesSent))
	{
		//���� ����?
	}
	else
	{
		check(BytesSent == BytesWrote);
	}
}
