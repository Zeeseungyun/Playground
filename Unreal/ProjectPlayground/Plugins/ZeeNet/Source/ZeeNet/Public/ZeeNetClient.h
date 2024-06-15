// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HAL/PlatformProcess.h"
#include "HAL/Runnable.h"
#include "SocketSubsystem.h"
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetMessageSerializer.h"

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

	template<typename T>
	void Notify(const T& Msg)
	{
		TSharedPtr<FZeeNetPacketBase> Packet = FZeeNetPacketSerializer::CreatePacketFromMessage(Msg);
		Send_Impl(Packet);
	}

	template<typename T>
	void Send(const T& Msg, TFunction<void(const T&)>&& Callback)
	{
		check(IsInGameThread());
		const int32 CurSequence = IncrementSequence();

		CallbackMaps.Add(CurSequence, [Callback_ = MoveTemp(Callback)](const void* Data)
			{
				Callback_(*(const T*) Data);
			}
		);

		TSharedPtr<FZeeNetPacketBase> Packet = FZeeNetPacketSerializer::CreatePacketFromMessage(Msg);
		Packet->Sequence = CurSequence;
		Packet->bIsRespond = true;
		Send_Impl(Packet);
	}

	template<typename T>
	void Send(const T& Msg, TWeakObjectPtr<UObject> ObjectPtr, TFunction<void(const T&)> Callback)
	{
		check(IsInGameThread());
		const int32 CurSequence = IncrementSequence();

		CallbackMaps.Add(CurSequence, [ObjectPtr, Callback_ = MoveTemp(Callback)](const void* Data)
			{
				if (ObjectPtr.IsValid())
				{
					Callback_(*(const T*)Data);
				}
			}
		);

		TSharedPtr<FZeeNetPacketBase> Packet = FZeeNetPacketSerializer::CreatePacketFromMessage(Msg);
		Packet->Sequence = CurSequence;
		Packet->bIsRespond = true;
		Send_Impl(Packet);
	}

	template<typename T, typename Y>
	void Send(const T& Msg, TSharedPtr<Y> SharedPtr, TFunction<void(const T&)> Callback)
	{
		check(IsInGameThread());
		const int32 CurSequence = IncrementSequence();

		TWeakPtr<Y> WeakPtr = SharedPtr;
		CallbackMaps.Add(CurSequence, [WeakPtr, Callback_ = MoveTemp(Callback)](const void* Data)
			{
				if (WeakPtr.IsValid())
				{
					Callback_(*(const T*)Data);
				}
			}
		);

		TSharedPtr<FZeeNetPacketBase> Packet = FZeeNetPacketSerializer::CreatePacketFromMessage(Msg);
		Packet->Sequence = CurSequence;
		Packet->bIsRespond = true;
		Send_Impl(Packet);
	}

	void Response(const TSharedPtr<FZeeNetPacketBase>& InPacket);

private:
	void ExecuteConnectEvent(const FString& Message);
	FOnConnected EventConnected;

public: //TODO:: to private.
	FZeeNetClient();

private:
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
	void Send_Impl(const TSharedPtr<FZeeNetPacketBase>& InPacket);

private:
	mutable FCriticalSection Mtx;

	bool bIsStop = false;
	uint8 InBuffer[BufferSize];
	uint8 OutBuffer[BufferSize];
	TUniquePtr<class FRunnableThread> Thread;
	FUniqueSocket Socket;

	FString EndPoint;
	FString ClientName;
	int32 Sequence = 1;
	int32 IncrementSequence()
	{
		int32 Return = Sequence++;
		if (Return == 0)
		{
			Return = Sequence++;
		}

		return Return;
	}

	TMap<int32 /*Sequence*/, TFunction<void(const void*)>> CallbackMaps;
};
