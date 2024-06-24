#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"

template<CZeeNetPacketMessage T>
struct ZEENET_API FZeeNetPacket
{
private:
	template<CZeeNetPacketMessage> friend struct FZeeNetPacketSerializer;
	friend class FZeeNetClient;

	FZeeNetPacketHeader Header;

public:
	FZeeNetPacket()
	{
		Header.Point = TZeeNetPacketTraits<T>::Point;
	}

	T Message;
};

template<>
struct ZEENET_API FZeeNetPacket<FZeeNetPacketHeader>
{
private:
	template<CZeeNetPacketMessage> friend struct FZeeNetPacketSerializer;
	friend class FZeeNetClient;

	FZeeNetPacketHeader Header;

public:
	FZeeNetPacket()
	{
		Header.Point = TZeeNetPacketTraits<FZeeNetPacketHeader>::Point;
	}
};
