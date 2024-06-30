////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"
#include "DataCharacter.generated.h"

USTRUCT(BlueprintType) 
struct FZeeNetDataCharacter 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	int64 UID = static_cast<int64>(0); 

	UPROPERTY(BlueprintReadWrite) 
	int64 User = static_cast<int64>(0); 

	UPROPERTY(BlueprintReadWrite) 
	int32 Id = static_cast<int32>(0); 

	UPROPERTY(BlueprintReadWrite) 
	int32 Slot = static_cast<int32>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FString Name; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetDataCharacter> { static constexpr int32 Point = 0x8001; static constexpr bool bIsData = true; }; 

