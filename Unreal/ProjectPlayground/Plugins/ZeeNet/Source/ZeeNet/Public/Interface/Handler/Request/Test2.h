////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "ZeeNet.h"
#include "ZeeNet/Public/Messages/Test2.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h"

struct ZEENET_API IZeeNetRequestHandler_Test2 
	: public IZeeNetRequestHandler 
{
	const FString& GetHandlerName() const final { static FString Name = TEXT("Request_Test2"); return Name; } 

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetTest2TestMessage2>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetTest2TestMessage3>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetTest2TestMessage4>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

	[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetTest2TestMessage5>& InPacket) { 
		return EZeeNetRequestHandlerResponse::NoResponse; 
	}

};



