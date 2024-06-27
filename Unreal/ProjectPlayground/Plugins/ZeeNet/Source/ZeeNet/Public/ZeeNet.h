// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogZeeNet, Log, All);

class FZeeNetModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	TArray<TSharedPtr<class FZeeNetClient>> ManagedClients;
	TArray<TSharedPtr<class FZeeNetClient>> PendingKillClients;
	
};
