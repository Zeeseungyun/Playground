// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HAL/PlatformProcess.h"
#include "HAL/Runnable.h"
#include "SocketSubsystem.h"
#include "CoreMinimal.h"

class ZEENET_API FZeeNetClient
	: public TSharedFromThis<FZeeNetClient>
	, public FRunnable
{
public:
	static constexpr size_t BufferSize = 1024;
	static TSharedPtr<FZeeNetClient> MakeClient(const FString& InEndPoint);

public:
	~FZeeNetClient();

	void TryConnect(const FString& InEndPoint);
	DECLARE_EVENT_OneParam(FZeeNetClient, FOnConnected, const FString& /*message if empty is success.*/);
	FOnConnected& OnConnected() { return EventConnected; }

	void SendMessage();

private:
	void ExecuteConnectEvent(const FString& Message);
	FOnConnected EventConnected;

private:
	FZeeNetClient();

	FZeeNetClient(const FZeeNetClient&) = delete;
	FZeeNetClient(FZeeNetClient&&) = delete;
	FZeeNetClient& operator=(const FZeeNetClient&) = delete;
	FZeeNetClient& operator=(FZeeNetClient&&) = delete;

	//~begin FRunnable Interface

	bool Init() override;
	uint32 Run() override;
	void Stop() override;
	void Exit() override;

	//~end FRunnable Interface

private:
	void Recv();
	void Send_Impl();

private:
	mutable FCriticalSection Mtx;

	bool bIsStop = false;
	uint8 Buffer[BufferSize];
	TUniquePtr<class FRunnableThread> Thread;
	FUniqueSocket Socket;

	FString EndPoint;
	FString ClientName;
};
