#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"

struct ZEENET_API FZeeNetMessageInvoker
	: public TSharedFromThis<FZeeNetMessageInvoker>
{
	virtual void Invoke()
	{

	}
};

struct ZEENET_API FZeeNetMessageInvoker
{
private:
	TMap<int32 /*Sequence*/, TSharedPtr<FZeeNetMessageInvoker>> InvokerList;

public:
	FZeeNetMessageInvoker();

};
