////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetClient.h"
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h"
#include "ZeeNet/Private/Handler/RequestDef.h"

#include "ZeeNet/Public/Interface/Handler/Request/Authentication.h" 
#include "ZeeNet/Public/Interface/Handler/Request/Authentication.h" 

FZeeNetRequestHandlerArray* FindRequestHandler_Authentication(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers) { 
	switch (Point) { 
	case TZeeNetMapping_UnrealToPoint<FZeeNetAuthenticationLogin>::Point: [[fallthrough]]; 
	case TZeeNetMapping_UnrealToPoint<FZeeNetAuthenticationLogout>::Point: 
		return RequestHandlers.Find(TEXT("Request_Authentication")); 
	default: break; 
	}

	return nullptr; 
}

EZeeNetRequestHandlerResponse ConsumeRequestMessage_Authentication(TSharedPtr<IZeeNetResponser> Responser
	, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet
	, FZeeNetRequestHandlerArray& RequestHandlers) { 
	const int32 PacketPoint = Packet->GetHeader().Point; 
	switch (PacketPoint) { 
		ZEENET_CASE_CONSUME_REQUEST(Authentication, Login);
		ZEENET_CASE_CONSUME_REQUEST(Authentication, Logout);
	default: break; 
	} 

	return EZeeNetRequestHandlerResponse::NoResponse; 
}

