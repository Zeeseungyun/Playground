////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetNotifyHandler.h"
#include "ZeeNet/Private/Handler/NotifyDef.h"

extern FZeeNetNotifyHandlerArray* FindNotifyHandler_Authentication(int32 Point, TMap<const TCHAR*, FZeeNetNotifyHandlerArray>& NotifyHandlers); 
extern bool ConsumeNotifyMessage_Authentication(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers); 
extern FZeeNetNotifyHandlerArray* FindNotifyHandler_Chat(int32 Point, TMap<const TCHAR*, FZeeNetNotifyHandlerArray>& NotifyHandlers); 
extern bool ConsumeNotifyMessage_Chat(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers); 
extern FZeeNetNotifyHandlerArray* FindNotifyHandler_Test(int32 Point, TMap<const TCHAR*, FZeeNetNotifyHandlerArray>& NotifyHandlers); 
extern bool ConsumeNotifyMessage_Test(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers); 
extern FZeeNetNotifyHandlerArray* FindNotifyHandler_Test2(int32 Point, TMap<const TCHAR*, FZeeNetNotifyHandlerArray>& NotifyHandlers); 
extern bool ConsumeNotifyMessage_Test2(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers); 

EZeeNetRequestHandlerResponse FZeeNetClient::ConsumeNotifyMessage(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet) {
	CheckNotifyHandlers(); 
	FZeeNetNotifyHandlerArray* Found = nullptr; 

	Found = FindNotifyHandler_Authentication(Packet->GetHeader().Point, NotifyHandlers); 
	if (Found) { if(Found->Num() > 0) ConsumeNotifyMessage_Authentication(Packet, *Found); return; } 

	Found = FindNotifyHandler_Chat(Packet->GetHeader().Point, NotifyHandlers); 
	if (Found) { if(Found->Num() > 0) ConsumeNotifyMessage_Chat(Packet, *Found); return; } 

	Found = FindNotifyHandler_Test(Packet->GetHeader().Point, NotifyHandlers); 
	if (Found) { if(Found->Num() > 0) ConsumeNotifyMessage_Test(Packet, *Found); return; } 

	Found = FindNotifyHandler_Test2(Packet->GetHeader().Point, NotifyHandlers); 
	if (Found) { if(Found->Num() > 0) ConsumeNotifyMessage_Test2(Packet, *Found); return; } 

}

void FZeeNetClient::BuildValidNotifyHandlerNames() {
	ValidNotifyHandlerNames.Add(TEXT("Notify_Authentication")); 
	ValidNotifyHandlerNames.Add(TEXT("Notify_Chat")); 
	ValidNotifyHandlerNames.Add(TEXT("Notify_Test")); 
	ValidNotifyHandlerNames.Add(TEXT("Notify_Test2")); 

}
