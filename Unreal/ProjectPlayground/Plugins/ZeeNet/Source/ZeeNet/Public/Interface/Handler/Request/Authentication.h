////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "ZeeNet.h"
#include "ZeeNet/Public/Messages/Authentication.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h"

struct ZEENET_API IZeeNetRequestHandler_Authentication 
	: public IZeeNetRequestHandler 
{
	const FString& GetHandlerName() const final { static FString Name = TEXT("Request_Authentication"); return Name; } 

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetAuthenticationLogin>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetAuthenticationLogout>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

};

