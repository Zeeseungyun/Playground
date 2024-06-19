#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"
#include "ZeeNet/Public/Messages/Packet.h"

struct FZeeNetPacketSerializerBase
	: public TSharedFromThis<FZeeNetPacketSerializerBase>
{
	virtual ~FZeeNetPacketSerializerBase() = default;

	//return read bytes.
	virtual int32 Deserialize(const uint8* InBuffer, int32 InBufferSize) = 0;

	//return written bytes.
	virtual int32 Serialize(uint8* OutBuffer, int32 InBufferSize) const = 0;
	virtual TSharedPtr<FZeeNetPacketSerializerBase> Clone() const = 0;

	template<CZeeNetPacketMessage T>
	const T& GetCastMessage() const
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == GetHeader().Point);
		return *reinterpret_cast<const T*>(GetMessage());
	}

	template<CZeeNetPacketMessage T>
	void SetCastMessage(const T& InMessage) 
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == GetHeader().Point);
		SetMessageInternal(&InMessage);
		return;
	}

	template<CZeeNetPacketMessage T>
	T& GetCastMutableMessage() 
	{
		return const_cast<T&>(GetCastMessage<T>());
	}

	template<CZeeNetPacketMessage T>
	const FZeeNetPacket<T>& GetCastPacket() const
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == GetHeader().Point);
		return *reinterpret_cast<const FZeeNetPacket<T>*>(GetPacket());
	}

	template<CZeeNetPacketMessage T>
	FZeeNetPacket<T>& GetCastMutablePacket()
	{
		return const_cast<FZeeNetPacket<T>&>(GetCastPacket<T>());
	}

	virtual void* GetMessage() const = 0;
	virtual void* GetPacket() const = 0;

protected:
	template<typename T>
	static int32 ReadBuffer(const uint8*& Buffer, T& Value)
	{	
		Value = *reinterpret_cast<const T*>(Buffer);
		return sizeof(T);
	}

	template<typename T>
	static int32 WriteBuffer(uint8*& Buffer, const T& Value)
	{
		*reinterpret_cast<T*>(Buffer) = Value;
		return sizeof(T);
	}

	virtual void SetMessageInternal(const void* InMessagePtr) = 0;

protected:
	friend class FZeeNetClient;
	template<int32 MessagePoint> friend struct FZeeNetPacketSerializer;

public:
	virtual FZeeNetPacketHeader& GetHeader() const = 0;

};

struct FZeeNetPacketSerializerMap
{
private:
	friend class FZeeNetModule;

	TMap<int32 /*Point*/, TSharedPtr<FZeeNetPacketSerializerBase>> DefaultSerializers;

	void BuildPacketSerializer();

	FZeeNetPacketSerializerMap() = default;

public:
	template<CZeeNetPacketMessage T>
	static TSharedPtr<FZeeNetPacketSerializerBase>
		CreateSerializerFromMessage(const T& InMessage)
	{
		TSharedPtr<FZeeNetPacketSerializerBase> Ret = CreateSerializer(TZeeNetMapping_UnrealToPoint<T>::Point);
		Ret->SetCastMessage(InMessage);
		return Ret;
	}

	template<CZeeNetPacketMessage T>
	static TSharedPtr<FZeeNetPacketSerializerBase>
		CreateSerializer()
	{
		return CreateSerializer(TZeeNetMapping_UnrealToPoint<T>::Point);
	}

	static TSharedPtr<FZeeNetPacketSerializerBase> CreateSerializer(int32 Point);
	static TSharedPtr<FZeeNetPacketSerializerBase> CreateSerializerFromBuffer(int32 Point, const uint8* OutBuffer, int32 InSize);

private:
	static FZeeNetPacketSerializerMap& GetSerializerMap();
};
