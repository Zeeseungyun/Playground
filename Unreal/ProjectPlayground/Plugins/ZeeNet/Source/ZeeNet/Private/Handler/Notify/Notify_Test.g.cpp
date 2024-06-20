////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Private/Handler/NotifyDef.h"
#include "ZeeNet/Public/Interface/Handler/Notify/Test.h" 

FZeeNetNotifyHandlerArray* FindNotifyHandler_Test(int32 Point, TMap<FString, FZeeNetNotifyHandlerArray>& NotifyHandlers) { 
	switch (Point) { 
	case TZeeNetMapping_UnrealToPoint<FZeeNetTestTestMessage>::Point: 
		return NotifyHandlers.Find(TEXT("Notify_Test")); 
	default: break; 
	}

	return nullptr; 
}

bool ConsumeNotifyMessage_Test(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers) { 
	const int32 PacketPoint = Packet->GetHeader().Point; 
	switch (PacketPoint) { 
		ZEENET_CASE_CONSUME_NOTIFY(Test, TestMessage);
	default: break; 
	} 

	return false; 
}
