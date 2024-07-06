#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"
#include "ZeeNet/Public/Interface/ZeeNetResponser.h"

enum class EZeeNetRequestHandlerResponse : uint8
{
	NoResponse,
	ResponseDirectly,
	ResponsePending,
};

struct ZEENET_API IZeeNetRequestHandler
{
public:
	virtual ~IZeeNetRequestHandler() = default;
	virtual const FString& GetHandlerName() const = 0;
	virtual TArray<FString> GetHandlerNames() const { return { GetHandlerName() }; }
	//응답 우선 순위 숫자가 작을 수록 우선 순위가 올라감.
	virtual int32 GetPriority() const { return 0; }
};
