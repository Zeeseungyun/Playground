////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "ZeeNet.h"
#include "ZeeNet/Public/Messages/Dedicate.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h"

struct ZEENET_API IZeeNetRequestHandler_Dedicate 
	: public IZeeNetRequestHandler 
{
	const FString& GetHandlerName() const final { static FString Name = TEXT("Request_Dedicate"); return Name; } 

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetDedicateLogin>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetDedicateMove>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetDedicateLeave>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

};
