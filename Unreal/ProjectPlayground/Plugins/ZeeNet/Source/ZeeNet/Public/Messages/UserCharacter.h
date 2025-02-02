////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"
#include "ZeeNet/Public/Messages/Data/DataCharacter.h"
#include "ZeeNet/Public/Messages/Data/DataDedicate.h"
#include "ZeeNet/Public/Messages/Data/DataCommon.h"
#include "UserCharacter.generated.h"

UENUM(BlueprintType) 
enum class EZeeNetUserCharacterReturnCode : uint8 
{ 
	RC_SUCCESS = 0,
	RC_FAILED_UNKNOWN = 1,
	RC_FAILED_CREATE_DUPLICATED_NAME = 2,
}; 
inline constexpr bool ZEENET_API ZeeNetIsSuccess(EZeeNetUserCharacterReturnCode Value) { return EZeeNetUserCharacterReturnCode::RC_SUCCESS == Value; }

USTRUCT(BlueprintType) 
struct FZeeNetUserCharacterCreate 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetUserCharacterReturnCode RC = static_cast<EZeeNetUserCharacterReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataCharacter Character; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetUserCharacterCreate> { static constexpr int32 Point = 0x5001; static constexpr bool bIsData = false; }; 

USTRUCT(BlueprintType) 
struct FZeeNetUserCharacterGet 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetUserCharacterReturnCode RC = static_cast<EZeeNetUserCharacterReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	int64 User = static_cast<int64>(0); 

	UPROPERTY(BlueprintReadWrite) 
	TArray<FZeeNetDataCharacter> Characters; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetUserCharacterGet> { static constexpr int32 Point = 0x5002; static constexpr bool bIsData = false; }; 

USTRUCT(BlueprintType) 
struct FZeeNetUserCharacterSelect 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetUserCharacterReturnCode RC = static_cast<EZeeNetUserCharacterReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataCharacter Character; 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataDedicateServer ToServer; 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataPosition Position; 

	UPROPERTY(BlueprintReadWrite) 
	FString UserIp; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetUserCharacterSelect> { static constexpr int32 Point = 0x5003; static constexpr bool bIsData = false; }; 

