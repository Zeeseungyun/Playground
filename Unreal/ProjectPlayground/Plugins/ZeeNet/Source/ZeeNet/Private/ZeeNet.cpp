// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZeeNet.h"

#define LOCTEXT_NAMESPACE "FZeeNetModule"
#include "google/protobuf/map.h"
#include "ZeeNet/Private/Messages/Chat.pb.h"

DEFINE_LOG_CATEGORY(LogZeeNet)

void FZeeNetModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	Zee::Proto::Chat::ReturnCode RC = Zee::Proto::Chat::ReturnCode::RC_SUCCESSS;
	
}

void FZeeNetModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FZeeNetModule, ZeeNet)
