#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"

template<CZeeNetPacketMessage T>
struct ZEENET_API FZeeNetPacket
{
private:
	template<int32 MessagePoint> friend struct FZeeNetPacketSerializer;
	friend class FZeeNetClient;

	FZeeNetPacketHeader Header;

public:
	FZeeNetPacket()
	{
		Header.Point = TZeeNetMapping_UnrealToPoint<T>::Point;
	}

	T Message;
};

template<>
struct ZEENET_API FZeeNetPacket<FZeeNetPacketHeader>
{
private:
	template<int32 MessagePoint> friend struct FZeeNetPacketSerializer;
	friend class FZeeNetClient;

	FZeeNetPacketHeader Header;

public:
	FZeeNetPacket()
	{
		Header.Point = TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point;
	}
};
