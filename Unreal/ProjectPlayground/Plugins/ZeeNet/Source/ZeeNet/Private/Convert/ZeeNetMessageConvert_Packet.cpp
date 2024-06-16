#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Packet.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Packet::Header& InFrom, FZeeNetPacketHeader& OutTo)
{
	OutTo.PacketSize = To<int32>(InFrom.packetsize()); 
	OutTo.Point = To<int32>(InFrom.point()); 
	OutTo.Sequence = To<int32>(InFrom.sequence()); 
	OutTo.PacketType = To<EZeeNetPacketType>(InFrom.packettype()); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetPacketHeader& InFrom, Zee::Proto::Packet::Header& OutTo)
{
	OutTo.set_packetsize(To<int32>(InFrom.PacketSize)); 
	OutTo.set_point(To<int32>(InFrom.Point)); 
	OutTo.set_sequence(To<int32>(InFrom.Sequence)); 
	OutTo.set_packettype(To<Zee::Proto::Packet::Type>(InFrom.PacketType)); 
}

