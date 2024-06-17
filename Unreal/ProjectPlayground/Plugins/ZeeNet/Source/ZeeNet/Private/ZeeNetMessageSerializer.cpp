#include "ZeeNetMessageSerializer.h"

TSharedPtr<FZeeNetPacketSerializerBase> FZeeNetPacketSerializerMap::CreateSerializer(int32 Point)
{
	checkf(GetSerializerMap().DefaultSerializers.Num() == 0, TEXT("ZeeNet module not loaded."));
	check(GetSerializerMap().DefaultSerializers.Contains(Point));
	return GetSerializerMap().DefaultSerializers[Point]->Clone();
}

TSharedPtr<FZeeNetPacketSerializerBase> FZeeNetPacketSerializerMap::CreateSerializerFromBuffer(int32 Point, const uint8* OutBuffer, int32 InSize)
{
	TSharedPtr<FZeeNetPacketSerializerBase> Packet = CreateSerializer(Point);
	Packet->Deserialize(OutBuffer, InSize);
	return Packet;
}

FZeeNetPacketSerializerMap& FZeeNetPacketSerializerMap::GetSerializerMap()
{
	static FZeeNetPacketSerializerMap Ret;
	return Ret;
}
