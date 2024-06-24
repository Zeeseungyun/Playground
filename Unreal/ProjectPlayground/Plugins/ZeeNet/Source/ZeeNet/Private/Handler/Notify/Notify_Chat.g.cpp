////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Private/Handler/NotifyDef.h"
#include "ZeeNet/Public/Interface/Handler/Notify/Chat.h" 

FZeeNetNotifyHandlerArray* FindNotifyHandler_Chat(int32 Point, TMap<FString, FZeeNetNotifyHandlerArray>& NotifyHandlers) { 
	switch (Point) { 
	case TZeeNetPacketTraits<FZeeNetChatSpeak1>::Point: [[fallthrough]]; 
	case TZeeNetPacketTraits<FZeeNetChatSpeak>::Point: 
		return NotifyHandlers.Find(TEXT("Notify_Chat")); 
	default: break; 
	}

	return nullptr; 
}

bool ConsumeNotifyMessage_Chat(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers) { 
	const int32 PacketPoint = Packet->GetHeader().Point; 
	switch (PacketPoint) { 
		ZEENET_CASE_CONSUME_NOTIFY(Chat, Speak1);
		ZEENET_CASE_CONSUME_NOTIFY(Chat, Speak);
	default: break; 
	} 

	return false; 
}

