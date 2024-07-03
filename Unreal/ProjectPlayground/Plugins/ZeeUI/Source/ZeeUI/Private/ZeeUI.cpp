// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZeeUI.h"
#include "ZeeUI/Public/ZeeUISlateStyles.h"

#define LOCTEXT_NAMESPACE "FZeeUIModule"

void FZeeUIModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FZeeUISlateStyles::Initialize();
}

void FZeeUIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FZeeUISlateStyles::Shutdown();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FZeeUIModule, ZeeUI)