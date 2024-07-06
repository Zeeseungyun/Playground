// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZeeNet.h"
#include "ZeeNetClient.h"
#include "ZeeNet/Private/ZeeNetMessageSerializer.h"

#define LOCTEXT_NAMESPACE "FZeeNetModule"

DEFINE_LOG_CATEGORY(LogZeeNet)

void FZeeNetModule::StartupModule()
{
	FZeeNetPacketSerializerMap::GetSerializerMap().BuildPacketSerializer();
}

void FZeeNetModule::ShutdownModule()
{
	FZeeNetPacketSerializerMap::GetSerializerMap().DefaultSerializers.Empty();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FZeeNetModule, ZeeNet)
