////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketMapping.h"
#include "Chat.generated.h"

UENUM(BlueprintType) 
enum class EZeeNetChatReturnCode : uint8 
{ 
	RC_SUCCESSS = 0,
}; 

USTRUCT(BlueprintType) 
struct FZeeNetChatSpeak 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetChatReturnCode RC = static_cast<EZeeNetChatReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	int64 UID = static_cast<int64>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FString Id; 

	UPROPERTY(BlueprintReadWrite) 
	FString Content; 

	UPROPERTY(BlueprintReadWrite) 
	TArray<FString> Contents; 

}; 
template<> struct TZeeNetMapping_UnrealToPoint<FZeeNetChatSpeak> { static constexpr int32 Point = 0x2002; }; 
template<> struct TZeeNetMapping_PointToUnreal<TZeeNetMapping_UnrealToPoint<FZeeNetChatSpeak>::Point> { using Type = FZeeNetChatSpeak; }; 


USTRUCT(BlueprintType) 
struct FZeeNetChatSpeak1 
{ 
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite) 
	EZeeNetChatReturnCode RC = static_cast<EZeeNetChatReturnCode>(0); 

	UPROPERTY(BlueprintReadWrite) 
	int64 UID = static_cast<int64>(0); 

	UPROPERTY(BlueprintReadWrite) 
	FString Id; 

	UPROPERTY(BlueprintReadWrite) 
	FString Content; 

	UPROPERTY(BlueprintReadWrite) 
	FZeeNetChatSpeak Speak1; 

}; 
template<> struct TZeeNetMapping_UnrealToPoint<FZeeNetChatSpeak1> { static constexpr int32 Point = 0x2001; }; 
template<> struct TZeeNetMapping_PointToUnreal<TZeeNetMapping_UnrealToPoint<FZeeNetChatSpeak1>::Point> { using Type = FZeeNetChatSpeak1; }; 


