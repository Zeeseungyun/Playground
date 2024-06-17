#pragma once
#include "CoreMinimal.h"

struct IZeeNetNotifyHandler
{
public:
	virtual ~IZeeNetNotifyHandler() = default;
	virtual const TCHAR* GetHandlerName() const = 0;
};
