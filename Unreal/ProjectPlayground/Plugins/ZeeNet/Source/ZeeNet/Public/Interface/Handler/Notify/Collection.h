////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "ZeeNet.h"
#include "ZeeNet/Public/Messages/Collection.h"
#include "ZeeNet/Public/Interface/Handler/ZeeNetNotifyHandler.h"

struct ZEENET_API IZeeNetNotifyHandler_Collection 
	: public IZeeNetNotifyHandler 
{
	const FString& GetHandlerName() const final { static FString Name = TEXT("Notify_Collection"); return Name; } 

	virtual void OnNotify(const FZeeNetCollectionCollect& InMessage) { UE_LOG(LogZeeNet, Warning, TEXT("OnNotify is not impl: 'FZeeNetCollectionCollect'")); } 
	virtual void OnNotify(const FZeeNetCollectionGet& InMessage) { UE_LOG(LogZeeNet, Warning, TEXT("OnNotify is not impl: 'FZeeNetCollectionGet'")); } 
};
