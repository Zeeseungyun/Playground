#pragma once
#include "CoreMinimal.h"

struct IZeeNetNotifyHandler
{
public:
	virtual ~IZeeNetNotifyHandler() = default;
	virtual const FString& GetHandlerName() const = 0;
	virtual TArray<FString> GetHandlerNames() const { return { GetHandlerName() }; }
};
