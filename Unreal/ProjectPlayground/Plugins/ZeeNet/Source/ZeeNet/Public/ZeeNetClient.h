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

private:
	void ExecuteConnectEvent(const FString& Message);
	FOnConnected EventConnected;

public:
	template<typename T>
	typename TEnableIf<TZeeNetIsValidMapping<T>::Value>::Type
		Notify(const T& Msg)
	{
		Send_Impl(TZeeNetMapping_UnrealToPoint<T>::Point, 0, EZeeNetPacketType::Notify, &Msg);
	}

	template<typename T>
	typename TEnableIf<TZeeNetIsValidMapping<T>::Value>::Type
		Request(const T& Msg, TFunction<void(const T&)>&& Callback)
	{
		check(IsInGameThread());
		const int32 CurSequence = IncrementSequence();

		CallbackMaps.Add(CurSequence, [Callback_ = MoveTemp(Callback)](const void* Data)
			{
				Callback_(*reinterpret_cast<const T*>(Data));
			}
		);
		
		Send_Impl(TZeeNetMapping_UnrealToPoint<T>::Point, CurSequence, EZeeNetPacketType::Request, &Msg);
	}

	template<typename T>
	typename TEnableIf<TZeeNetIsValidMapping<T>::Value>::Type
		Request(const T& Msg, TWeakObjectPtr<UObject> ObjectPtr, TFunction<void(const T&)> Callback)
	{
		check(IsInGameThread());
		const int32 CurSequence = IncrementSequence();

		CallbackMaps.Add(CurSequence, [ObjectPtr, Callback_ = MoveTemp(Callback)](const void* Data)
			{
				if (ObjectPtr.IsValid())
				{
					Callback_(*reinterpret_cast<const T*>(Data));
				}
			}
		);

		Send_Impl(TZeeNetMapping_UnrealToPoint<T>::Point, CurSequence, EZeeNetPacketType::Request, &Msg);
	}

	template<typename T, typename Y>
	typename TEnableIf<TZeeNetIsValidMapping<T>::Value>::Type
		Request(const T& Msg, TSharedPtr<Y> SharedPtr, TFunction<void(const T&)> Callback)
	{
		check(IsInGameThread());
		const int32 CurSequence = IncrementSequence();

		TWeakPtr<Y> WeakPtr = SharedPtr;
		CallbackMaps.Add(CurSequence, [WeakPtr, Callback_ = MoveTemp(Callback)](const void* Data)
			{
				if (WeakPtr.IsValid())
				{
					Callback_(*reinterpret_cast<const T*>(Data));
				}
			}
		);

		Send_Impl(TZeeNetMapping_UnrealToPoint<T>::Point, CurSequence, EZeeNetPacketType::Request, &Msg);
	}

public: //TODO:: to private. only use sharedptr
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
	void Send_Impl(int32 InPoint, int32 InSequecne, EZeeNetPacketType InPacketType, const void* InData);

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
