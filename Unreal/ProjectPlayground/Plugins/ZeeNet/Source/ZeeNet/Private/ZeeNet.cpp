// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZeeNet.h"
#include "ZeeNetClient.h"
#include "ZeeNet/Public/Messages/Chat.h"
#include "ZeeNet/Private/ZeeNetMessageSerializer.h"

#define LOCTEXT_NAMESPACE "FZeeNetModule"

DEFINE_LOG_CATEGORY(LogZeeNet)

void FZeeNetModule::StartupModule()
{
	FZeeNetPacketSerializerMap::GetSerializerMap().BuildPacketSerializer();

	Temp = FZeeNetClient::MakeClient(TEXT(""));
	Temp->OnConnected().AddLambda([this](const FString& InMessage)
		{
			FZeeNetChatSpeak Msg;
			Msg.Content = TEXT("hi");

		}
	);
	Temp->TryConnect(TEXT("127.0.0.1:20500"));
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
