////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"
#include "Account.generated.h"

USTRUCT(BlueprintType) 
struct FZeeNetDataAccount 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	int64 UID = static_cast<int64>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FString Id; 

	UPROPERTY(BlueprintReadWrite) 
	FString Password; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetDataAccount> { static constexpr int32 Point = 0x5001; static constexpr bool bIsData = true; }; 

