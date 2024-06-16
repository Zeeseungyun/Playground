#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"
#include "ZeeNet/Public/Messages/Packet.h"

struct ZEENET_API FZeeNetPacketSerializerBase
	: public TSharedFromThis<FZeeNetPacketSerializerBase>
{
	virtual ~FZeeNetPacketSerializerBase() = default;

	//return read bytes.
	virtual int32 Deserialize(const uint8* InBuffer, int32 InBuffetSize) = 0;

	//return written bytes.
	virtual int32 Serialize(uint8* OutBuffer, int32 InBuffetSize) const = 0;
	virtual TSharedPtr<FZeeNetPacketSerializerBase> Clone() const = 0;

	template<typename T>
	typename TEnableIf<TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint, const T&>::Type
		GetCastMessage() const
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == GetPoint());
		return *reinterpret_cast<const T*>(GetMessage());
	}

	template<typename T>
	typename TEnableIf<TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint>::Type
		SetCastMessage(const T& InMessage) 
	{
		check(TZeeNetMapping_UnrealToPoint<T>::Point == GetPoint());
		SetMessageInternal(&InMessage);
		return;
	}

	template<typename T>
	typename TEnableIf<TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint, const T&>::Type
		GetCastMutableMessage() 
	{
		return const_cast<T&>(GetCastMessage<T>());
	}

	virtual const void* GetMessage() const = 0;

protected:
	template<typename T>
	static int32 ReadBuffer(const uint8*& Buffer, T& Value)
	{	
		Value = *reinterpret_cast<const T*>(Buffer);
		Buffer += sizeof(T);
		return sizeof(T);
	}

	template<typename T>
	static int32 WriteBuffer(uint8*& Buffer, const T& Value)
	{
		*reinterpret_cast<T*>(Buffer) = Value;
		Buffer += sizeof(T);
		return sizeof(T);
	}

	virtual void SetMessageInternal(const void* InMessagePtr) = 0;

protected:
	friend class FZeeNetClient;
	template<int32 MessagePoint> friend struct FZeeNetPacket;
	mutable FZeeNetPacketHeader Header;

public:
	int32 GetPoint() const { return Header.Point; }

	int32 GetSequence() const { return Header.Point; }
	void SetSequence(int32 NewSequence) { Header.Sequence = NewSequence; }

	EZeeNetPacketType GetPacketType() const { return Header.PacketType; }
	void SetPacketType(EZeeNetPacketType NewType) { Header.PacketType = NewType; }
};

struct ZEENET_API FZeeNetPacketSerializerMap
{
private:
	friend class FZeeNetModule;

	TMap<int32 /*Point*/, TSharedPtr<FZeeNetPacketSerializerBase>> DefaultSerializers;

	void BuildPacketSerializer();

	FZeeNetPacketSerializerMap();
public:
	template<typename T>
	static typename TEnableIf<TZeeNetIsValidMapping<T>::Value, TSharedPtr<FZeeNetPacketSerializerBase>>::Type
		CreateSerializerFromMessage(const T& InMessage)
	{
		TSharedPtr<FZeeNetPacketSerializerBase> Ret = CreateSerializer(TZeeNetMapping_UnrealToPoint<T>::Point);
		Ret->SetCastMessage(InMessage);
		return Ret;
	}

	template<typename T>
	static typename TEnableIf<TZeeNetIsValidMapping<T>::Value, TSharedPtr<FZeeNetPacketSerializerBase>>::Type
		CreateSerializer()
	{
		return CreateSerializer(TZeeNetMapping_UnrealToPoint<T>::Point);
	}

	static TSharedPtr<FZeeNetPacketSerializerBase> CreateSerializer(int32 Point);
	static TSharedPtr<FZeeNetPacketSerializerBase> CreateSerializerFromBuffer(int32 Point, const uint8* OutBuffer, int32 InSize);

private:
	static FZeeNetPacketSerializerMap& GetSerializerMap();
};
