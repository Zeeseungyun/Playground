// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HAL/PlatformProcess.h"
#include "HAL/Runnable.h"
#include "SocketSubsystem.h"
#include "CoreMinimal.h"
#include "ZeeNet/Public/Interface/ZeeNetResponser.h"

enum class EZeeNetRequestHandlerResponse : uint8;

class ZEENET_API FZeeNetClient
	: public FRunnable
	, public IZeeNetResponser
	, public TSharedFromThis<FZeeNetClient>
{
public:
	static constexpr size_t BufferSize = 1024;
	[[nodiscard]] static TSharedPtr<FZeeNetClient> MakeClient(const FString& InEndPoint);

public: //TODO:: to private. only use sharedptr
	FZeeNetClient();
	~FZeeNetClient();

	void TryConnect(const FString& InEndPoint);
	DECLARE_EVENT_OneParam(FZeeNetClient, FOnConnected, const FString& /*message if empty is success.*/);
	FOnConnected& OnConnected() { return EventConnected; }
	//TODO:: Disconnected.
	//FOnConnected& OnDisconnected() { return EventDisconnected; }
	//FOnConnected EventDisconnected;

private:
	void ExecuteConnectEvent(const FString& Message);
	FOnConnected EventConnected;

private:
	FZeeNetClient(const FZeeNetClient&) = delete;
	FZeeNetClient(FZeeNetClient&&) = delete;
	FZeeNetClient& operator=(const FZeeNetClient&) = delete;
	FZeeNetClient& operator=(FZeeNetClient&&) = delete;

private:
	//~begin FRunnable Interface

	bool Init() override;
	uint32 Run() override;
	void Stop() override;
	void Exit() override;

	//~end FRunnable Interface
public:
	template<CZeeNetPacketMessage T>
	bool Notify(const T& Msg)
	{
		return Send(TZeeNetMapping_UnrealToPoint<T>::Point, 0, EZeeNetPacketType::Notify, &Msg);
	}

	template<CZeeNetPacketMessage T>
	bool Request(const T& Msg, TFunction<void(const T&)>&& Callback)
	{
		const int32 CurSequence = IncrementSequence();
		
		{
			FScopeLock Lock(&MtxCallbackMaps);
			CallbackMaps.Add(CurSequence, [Callback_ = MoveTemp(Callback)](const void* Data)
				{
					Callback_(*reinterpret_cast<const T*>(Data));
				}
			);
		}

		return Send(TZeeNetMapping_UnrealToPoint<T>::Point, CurSequence, EZeeNetPacketType::Request, &Msg);
	}

	template<CZeeNetPacketMessage T>
	bool Request(const T& Msg, TWeakObjectPtr<UObject> ObjectPtr, TFunction<void(const T&)>&& Callback)
	{
		const int32 CurSequence = IncrementSequence();

		{
			FScopeLock Lock(&MtxCallbackMaps);
			CallbackMaps.Add(CurSequence, [ObjectPtr, Callback_ = MoveTemp(Callback)](const void* Data)
				{
					if (ObjectPtr.IsValid())
					{
						Callback_(*reinterpret_cast<const T*>(Data));
					}
				}
			);
		}

		return Send(TZeeNetMapping_UnrealToPoint<T>::Point, CurSequence, EZeeNetPacketType::Request, &Msg);
	}

	template<CZeeNetPacketMessage T, typename U>
	bool Request(const T& Msg, TSharedPtr<U> SharedPtr, TFunction<void(const T&)>&& Callback)
	{
		const int32 CurSequence = IncrementSequence();

		{
			TWeakPtr<U> WeakPtr = SharedPtr;
			FScopeLock Lock(&MtxCallbackMaps);
			CallbackMaps.Add(CurSequence, [WeakPtr, Callback_ = MoveTemp(Callback)](const void* Data)
				{
					if (WeakPtr.IsValid())
					{
						Callback_(*reinterpret_cast<const T*>(Data));
					}
				}
			);
		}

		return Send(TZeeNetMapping_UnrealToPoint<T>::Point, CurSequence, EZeeNetPacketType::Request, &Msg);
	}
	
	////////////////////////////
	// begin NotifyHandler
	////////////////////////////
public:
	bool RegisterNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& NewHandler);
	void UnregisterNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& NewHandler);
	bool IsInNotifyHandler(const TSharedPtr<struct IZeeNetNotifyHandler>& InHandler) const;

private:
	TMap<FString, TArray<TWeakPtr<struct IZeeNetNotifyHandler>>> NotifyHandlers;
	static TSet<FString> ValidNotifyHandlerNames;

	void CheckNotifyHandlers();
	//implemented in Private/Handler/Notify.g.cpp
	bool ConsumeNotifyMessage(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet);
	//implemented in Private/Handler/Notify.g.cpp
	void BuildValidNotifyHandlerNames();

	////////////////////////////
	// end NotifyHandler
	////////////////////////////

	////////////////////////////
	// begin RequestHandler
	////////////////////////////
public:
	bool RegisterRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& NewHandler);
	void UnregisterRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& NewHandler);
	bool IsInRequestHandler(const TSharedPtr<struct IZeeNetRequestHandler>& InHandler) const;

	float GetRequestTimeoutSec() const { return RequestTimeoutSec; }
	
	//TODO:: 요청타임아웃 설정시키고.. 타임아웃이 지나면 자동 리스폰스
	void SetRequestTimeoutSec(float NewRequestTimeoutSec) { }

private:
	void OnBeginFrame();
	FDelegateHandle BeginFrameDelegate;

private:
	TMap<FString, TArray<TWeakPtr<struct IZeeNetRequestHandler>>> RequestHandlers;
	static TSet<FString> ValidRequestHandlerNames;
	float RequestTimeoutSec = 10.0f;

	void CheckRequestHandlers();

	//TODO:: 누가 소비했는지 반환하도록 해야함.
	//implemented in Private/Handler/Request.g.cpp
	EZeeNetRequestHandlerResponse ConsumeRequestMessage(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet);
	//implemented in Private/Handler/Request.g.cpp
	void BuildValidRequestHandlerNames();

	////////////////////////////
	// end RequestHandler
	////////////////////////////

private:
	void Recv();
	bool Send(int32 InPoint, int32 InSequecne, EZeeNetPacketType InPacketType, const void* InMessageRawPtr);
	EZeeNetReponseType Response_Impl(const void* InPacketRawPtr) final;

private:
	uint8 InBuffer[BufferSize];
	uint8 OutBuffer[BufferSize];

	TUniquePtr<class FRunnableThread> Thread;
	TAtomic<bool> bIsStop = false;

	mutable FCriticalSection MtxSocket;
	FUniqueSocket Socket;
	
	FString EndPoint;
	FString ClientName;
	TAtomic<int32> Sequence = 1;

	int32 IncrementSequence()
	{
		return Sequence++;
	}

	mutable FCriticalSection MtxCallbackMaps;
	TMap<int32 /*Sequence*/, TFunction<void(const void*)>> CallbackMaps;

	struct FPendingPacket
	{
		int64 TimeTick = 0;
		TSharedRef<struct FZeeNetPacketSerializerBase> Packet;
	};

	mutable FCriticalSection MtxRequestPendingPackets;
	TArray<FPendingPacket> RequestPendingPackets;

	mutable FCriticalSection MtxPendingPackets;
	TArray<FPendingPacket> PendingPackets;
	
	TOptional<int32> ResponseDirectylySequenceCheck;
};
