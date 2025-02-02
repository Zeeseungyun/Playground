////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"
#include "ZeeNet/Public/Messages/Data/DataDedicate.h"
#include "ZeeNet/Public/Messages/Data/DataCharacter.h"
#include "ZeeNet/Public/Messages/Data/DataCommon.h"
#include "Dedicate.generated.h"

UENUM(BlueprintType) 
enum class EZeeNetDedicateReturnCode : uint8 
{ 
	RC_SUCCESS = 0,
	RC_FAILED_UNKNOWN = 1,
	RC_FAILED_DEDI_NOT_FOUND = 2,
}; 
inline constexpr bool ZEENET_API ZeeNetIsSuccess(EZeeNetDedicateReturnCode Value) { return EZeeNetDedicateReturnCode::RC_SUCCESS == Value; }

USTRUCT(BlueprintType) 
struct FZeeNetDedicateLogin 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetDedicateReturnCode RC = static_cast<EZeeNetDedicateReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataDedicateServer DedicateServer; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetDedicateLogin> { static constexpr int32 Point = 0x3001; static constexpr bool bIsData = false; }; 

USTRUCT(BlueprintType) 
struct FZeeNetDedicateMove 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetDedicateReturnCode RC = static_cast<EZeeNetDedicateReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataCharacter Character; 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataDedicateServer ToServer; 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataPosition Position; 

	UPROPERTY(BlueprintReadWrite) 
	FString UserIp; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetDedicateMove> { static constexpr int32 Point = 0x3002; static constexpr bool bIsData = false; }; 

USTRUCT(BlueprintType) 
struct FZeeNetDedicateLeave 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataCharacter Character; 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetDataPosition Position; 

}; 
template<> struct TZeeNetPacketTraits<FZeeNetDedicateLeave> { static constexpr int32 Point = 0x3003; static constexpr bool bIsData = false; }; 

