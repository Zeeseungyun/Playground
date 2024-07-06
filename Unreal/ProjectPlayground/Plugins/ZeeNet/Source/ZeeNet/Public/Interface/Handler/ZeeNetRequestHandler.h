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
	//���� �켱 ���� ���ڰ� ���� ���� �켱 ������ �ö�.
	virtual int32 GetPriority() const { return 0; }
};
