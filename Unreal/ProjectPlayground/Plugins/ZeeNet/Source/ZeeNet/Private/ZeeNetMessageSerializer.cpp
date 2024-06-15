#include "ZeeNetMessageSerializer.h"

FZeeNetPacketSerializer::FZeeNetPacketSerializer()
{
	BuildDefaultPackets();
}

TSharedPtr<FZeeNetPacketBase> FZeeNetPacketSerializer::CreatePacket(int32 Point)
{
	return GetDefaultSerializer().DefaultMessages[Point]->Clone();
}

TSharedPtr<FZeeNetPacketBase> FZeeNetPacketSerializer::CreatePacketFromBuffer(int32 Point, const uint8* OutBuffer, int32 InSize)
{
	TSharedPtr<FZeeNetPacketBase> Packet = CreatePacket(Point);
	Packet->Deserialize(OutBuffer, InSize);
	return Packet;
}

const FZeeNetPacketSerializer& FZeeNetPacketSerializer::GetDefaultSerializer()
{
	static FZeeNetPacketSerializer Ret;
	return Ret;
}
