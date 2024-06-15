#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"

struct ZEENET_API FZeeNetPacketBase
	: public TSharedFromThis<FZeeNetPacketBase>
{
	virtual ~FZeeNetPacketBase() = default;
	virtual int32 Deserialize(const uint8* InBuffer, int32 InSize) = 0;
	virtual int32 Serialize(uint8* OutBuffer, int32 InBound) const = 0;
	int32 GetMessagePoint() const { return Point; }
	virtual TSharedPtr<FZeeNetPacketBase> Clone() const = 0;

	template<typename T>
	typename TEnableIf<TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint, const T&>::Type
		GetCastMessage() const
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == Point);
		return *(const T*)GetMessage();
	}

	template<typename T>
	typename TEnableIf<TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint>::Type
		SetCastMessage(const T& InMessage) 
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == Point);
		SetMessageInternal(&InMessage);
		return;
	}

	virtual const void* GetMessage() const = 0;

protected:
	virtual void SetMessageInternal(const void* InMessagePtr) = 0;
	int32 Point = ZeeNetInvalidMessagePoint;

public:
	int32 Sequence = 0;
	uint8 bIsRespond = 0;

private:
	uint8 padd[3];
};

struct ZEENET_API FZeeNetPacketSerializer
{
private:
	TMap<int32 /*Point*/, TSharedPtr<FZeeNetPacketBase>> DefaultMessages;

	void BuildDefaultPackets();

	FZeeNetPacketSerializer();
public:

	template<typename MessageT>
		typename TEnableIf<TZeeNetIsValidMapping<MessageT>::Value, int32>::Type
		Serialize(const MessageT& InMessage, uint8* OutBuffer, int32 InBound) const
	{
		const TSharedPtr<FZeeNetPacketBase>& DefaultMessage = DefaultMessages[TZeeNetMapping_UnrealToPoint<MessageT>::Point];
		DefaultMessage->SetMessageInternal(&InMessage);
		return DefaultMessage->Serialize(OutBuffer, InBound);
	}

	TSharedPtr<FZeeNetPacketBase> Deserialize(int32 Point, const uint8* OutBuffer, int32 InSize) const
	{
		TSharedPtr<FZeeNetPacketBase> Ret = DefaultMessages[Point]->Clone();
		Ret->Deserialize(OutBuffer, InSize);
		return Ret;
	}

	template<typename T>
	static TSharedPtr<FZeeNetPacketBase> CreatePacketFromMessage(const T& InMessage)
	{
		TSharedPtr<FZeeNetPacketBase> Ret = CreatePacket(TZeeNetMapping_UnrealToPoint<T>::Point);
		Ret->SetCastMessage(InMessage);
		return Ret;
	}

	static TSharedPtr<FZeeNetPacketBase> CreatePacket(int32 Point);
	static TSharedPtr<FZeeNetPacketBase> CreatePacketFromBuffer(int32 Point, const uint8* OutBuffer, int32 InSize);

private:
	static const FZeeNetPacketSerializer& GetDefaultSerializer();
};
