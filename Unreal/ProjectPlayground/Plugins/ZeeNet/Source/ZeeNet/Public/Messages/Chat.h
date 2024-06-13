#pragma once
#include "CoreMinimal.h"
#include "Chat.generated.h"

UENUM(BlueprintType)
enum class EZeeNetChatReturnCode : uint8
{
	SUCCESS = 0,
};

USTRUCT(BlueprintType)
struct FZeeNetChatSpeak
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	EZeeNetChatReturnCode RC;

	UPROPERTY(BlueprintReadWrite)
	int64 UID;

	UPROPERTY(BlueprintReadWrite)
	FString Id;

	UPROPERTY(BlueprintReadWrite)
	FString Content;
};
