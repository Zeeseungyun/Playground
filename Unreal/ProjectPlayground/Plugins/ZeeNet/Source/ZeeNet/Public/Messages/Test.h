////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"
#include "Test.generated.h"

UENUM(BlueprintType) 
enum class EZeeNetReturnCode : uint8 
{ 
	RC_SUCCESSS = 0,
}; 

USTRUCT(BlueprintType) 
struct FZeeNetTestMessage 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	TArray<int32> RC; 

	UPROPERTY(BlueprintReadWrite) 
	TArray<EZeeNetReturnCode> RCLists; 

	UPROPERTY(BlueprintReadWrite) 
	FString Id; 

	UPROPERTY(BlueprintReadWrite) 
	FString Content; 

}; 
template<> struct TZeeNetMapping_UnrealToPoint<FZeeNetTestMessage> { static constexpr int32 Point = 0x4001; }; 
template<> struct TZeeNetMapping_PointToUnreal<TZeeNetMapping_UnrealToPoint<FZeeNetTestMessage>::Point> { using Type = FZeeNetTestMessage; }; 


