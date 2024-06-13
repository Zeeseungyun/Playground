// Fill out your copyright notice in the Description page of Project Settings.


#include "ZeeNetClient.h"
#include "Networking.h"

/*static*/ TSharedPtr<FZeeNetClient> FZeeNetClient::MakeClient(const FString& InEndPoint)
{
	return TSharedPtr<FZeeNetClient>(new FZeeNetClient());
}

FZeeNetClient::FZeeNetClient()
	: Buffer{}
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
	int32 BytesRead = 0;
	if (Socket->Recv(Buffer, BufferSize, BytesRead))
	{
		//Packet 처리.
	}
}

void FZeeNetClient::Send_Impl()
{
	uint8 buffer[BufferSize];
	int32 SentsByte;
	if (Socket->Send(buffer, 100, SentsByte))
	{

	}
}
