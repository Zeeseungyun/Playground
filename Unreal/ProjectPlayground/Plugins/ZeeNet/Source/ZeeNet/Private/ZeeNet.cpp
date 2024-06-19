// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZeeNet.h"
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Chat.h"
#include "ZeeNet/Private/ZeeNetMessageSerializer.h"
#include "ZeeNet/Public/Interface/Handler/Request/Chat.h"
#include "ZeeNet/Public/Interface/Handler/Notify/Chat.h"

#define LOCTEXT_NAMESPACE "FZeeNetModule"

DEFINE_LOG_CATEGORY(LogZeeNet)

struct TempHandler : public IZeeNetRequestHandler_Chat
{
	[[nodiscard]] EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetChatSpeak>& InMessage) override {
		InResponser->Response(InMessage);
		return EZeeNetRequestHandlerResponse::ResponseDirectly;
	}

	[[nodiscard]] EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetChatSpeak1>& InMessage) override {
		return EZeeNetRequestHandlerResponse::NoResponse;
	}
};

struct TempHandler2 : public IZeeNetNotifyHandler_Chat
{
	virtual void OnNotify(const FZeeNetChatSpeak& InMessage) 
	{ 
		UE_LOG(LogZeeNet, Warning, TEXT("OnNotify is not impl: 'FZeeNetChatSpeak'")); 
	}

	virtual void OnNotify(const FZeeNetChatSpeak1& InMessage) 
	{ 
		UE_LOG(LogZeeNet, Warning, TEXT("OnNotify is not impl: 'FZeeNetChatSpeak1' %s "), *InMessage.Content);
	}
};

void FZeeNetModule::StartupModule()
{
	FZeeNetPacketSerializerMap::GetSerializerMap().BuildPacketSerializer();
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FZeeNetModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FZeeNetPacketSerializerMap::GetSerializerMap().DefaultSerializers.Empty();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FZeeNetModule, ZeeNet)
