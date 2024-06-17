////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Packet.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h"
#include "ZeeNet/Private/Handler/RequestDef.h"

extern FZeeNetRequestHandlerArray* FindRequestHandler_Authentication(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers); 
extern EZeeNetRequestHandlerResponse ConsumeRequestMessage_Authentication(
	TSharedPtr<IZeeNetResponser> Responser
	, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet
	, FZeeNetRequestHandlerArray& RequestHandlers
); 
extern FZeeNetRequestHandlerArray* FindRequestHandler_Chat(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers); 
extern EZeeNetRequestHandlerResponse ConsumeRequestMessage_Chat(
	TSharedPtr<IZeeNetResponser> Responser
	, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet
	, FZeeNetRequestHandlerArray& RequestHandlers
); 
extern FZeeNetRequestHandlerArray* FindRequestHandler_Test(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers); 
extern EZeeNetRequestHandlerResponse ConsumeRequestMessage_Test(
	TSharedPtr<IZeeNetResponser> Responser
	, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet
	, FZeeNetRequestHandlerArray& RequestHandlers
); 
extern FZeeNetRequestHandlerArray* FindRequestHandler_Test2(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers); 
extern EZeeNetRequestHandlerResponse ConsumeRequestMessage_Test2(
	TSharedPtr<IZeeNetResponser> Responser
	, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet
	, FZeeNetRequestHandlerArray& RequestHandlers
); 

EZeeNetRequestHandlerResponse FZeeNetClient::ConsumeRequestMessage(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet) { 
	CheckRequestHandlers(); 
	FZeeNetRequestHandlerArray* Found = nullptr; 
	TSharedPtr<IZeeNetResponser> Responser = StaticCastSharedPtr<IZeeNetResponser>(AsShared().ToSharedPtr()); 

	Found = FindRequestHandler_Authentication(Packet->GetHeader().Point, RequestHandlers); 
	if (Found) { 
		if (Found->Num() > 0) return ConsumeRequestMessage_Authentication(Responser, Packet, *Found); 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	Found = FindRequestHandler_Chat(Packet->GetHeader().Point, RequestHandlers); 
	if (Found) { 
		if (Found->Num() > 0) return ConsumeRequestMessage_Chat(Responser, Packet, *Found); 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	Found = FindRequestHandler_Test(Packet->GetHeader().Point, RequestHandlers); 
	if (Found) { 
		if (Found->Num() > 0) return ConsumeRequestMessage_Test(Responser, Packet, *Found); 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	Found = FindRequestHandler_Test2(Packet->GetHeader().Point, RequestHandlers); 
	if (Found) { 
		if (Found->Num() > 0) return ConsumeRequestMessage_Test2(Responser, Packet, *Found); 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	return EZeeNetRequestHandlerResponse::NoResponse;
}

void FZeeNetClient::BuildValidRequestHandlerNames() {
	ValidRequestHandlerNames.Add(TEXT("Request_Authentication")); 
	ValidRequestHandlerNames.Add(TEXT("Request_Chat")); 
	ValidRequestHandlerNames.Add(TEXT("Request_Test")); 
	ValidRequestHandlerNames.Add(TEXT("Request_Test2")); 

}

