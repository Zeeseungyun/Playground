////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "ZeeNet.h"
#include "ZeeNet/Public/Messages/UserCharacter.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetNotifyHandler.h"

struct ZEENET_API IZeeNetNotifyHandler_UserCharacter 
	: public IZeeNetNotifyHandler 
{
	const FString& GetHandlerName() const final { static FString Name = TEXT("Notify_UserCharacter"); return Name; } 

	virtual void OnNotify(const FZeeNetUserCharacterCreate& InMessage) { UE_LOG(LogZeeNet, Warning, TEXT("OnNotify is not impl: 'FZeeNetUserCharacterCreate'")); } 
	virtual void OnNotify(const FZeeNetUserCharacterGet& InMessage) { UE_LOG(LogZeeNet, Warning, TEXT("OnNotify is not impl: 'FZeeNetUserCharacterGet'")); } 
};

