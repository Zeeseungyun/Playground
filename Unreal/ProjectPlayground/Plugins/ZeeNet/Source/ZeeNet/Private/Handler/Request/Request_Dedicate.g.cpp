////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Private/Handler/RequestDef.h"

#include "ZeeNet/Public/Interface/Handler/Request/Dedicate.h" 

FZeeNetRequestHandlerArray* FindRequestHandler_Dedicate(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers) { 
	switch (Point) { 
	case TZeeNetPacketTraits<FZeeNetDedicateLogin>::Point: [[fallthrough]]; 
	case TZeeNetPacketTraits<FZeeNetDedicateMove>::Point: [[fallthrough]]; 
	case TZeeNetPacketTraits<FZeeNetDedicateLeave>::Point: 
		return RequestHandlers.Find(TEXT("Request_Dedicate")); 
	default: break; 
	}

	return nullptr; 
}

EZeeNetRequestHandlerResponse ConsumeRequestMessage_Dedicate(TSharedPtr<IZeeNetResponser> Responser
	, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet
	, FZeeNetRequestHandlerArray& RequestHandlers) { 
	const int32 PacketPoint = Packet->GetHeader().Point; 
	switch (PacketPoint) { 
		ZEENET_CASE_CONSUME_REQUEST(Dedicate, Login);
		ZEENET_CASE_CONSUME_REQUEST(Dedicate, Move);
		ZEENET_CASE_CONSUME_REQUEST(Dedicate, Leave);
	default: break; 
	} 

	return EZeeNetRequestHandlerResponse::NoResponse; 
}

