////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Private/Handler/NotifyDef.h"
#include "ZeeNet/Public/Interface/Handler/Notify/Dedicate.h" 

FZeeNetNotifyHandlerArray* FindNotifyHandler_Dedicate(int32 Point, TMap<FString, FZeeNetNotifyHandlerArray>& NotifyHandlers) { 
	switch (Point) { 
	case TZeeNetPacketTraits<FZeeNetDedicateLogin>::Point: [[fallthrough]]; 
	case TZeeNetPacketTraits<FZeeNetDedicateMove>::Point: [[fallthrough]]; 
	case TZeeNetPacketTraits<FZeeNetDedicateLeave>::Point: 
		return NotifyHandlers.Find(TEXT("Notify_Dedicate")); 
	default: break; 
	}

	return nullptr; 
}

bool ConsumeNotifyMessage_Dedicate(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers) { 
	const int32 PacketPoint = Packet->GetHeader().Point; 
	switch (PacketPoint) { 
		ZEENET_CASE_CONSUME_NOTIFY(Dedicate, Login);
		ZEENET_CASE_CONSUME_NOTIFY(Dedicate, Move);
		ZEENET_CASE_CONSUME_NOTIFY(Dedicate, Leave);
	default: break; 
	} 

	return false; 
}

