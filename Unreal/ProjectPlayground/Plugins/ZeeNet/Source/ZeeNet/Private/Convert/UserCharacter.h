////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once 
#include "CoreMinimal.h" 
#include "ZeeNet/Public/Messages/UserCharacter.h" 
#include "ZeeNet/Private/Messages/UserCharacter.pb.h" 
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 

namespace Zee::Net::Message::Convert 
{ 
	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::UserCharacter::Create> { static constexpr int32 Point = 0x5001; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::UserCharacter::Create>::Point> { using Type = Zee::Proto::UserCharacter::Create; }; 
	FORCEINLINE void FromTo(const Zee::Proto::UserCharacter::Create& InFrom, FZeeNetUserCharacterCreate& OutTo);
	FORCEINLINE void FromTo(const FZeeNetUserCharacterCreate& InFrom, Zee::Proto::UserCharacter::Create& OutTo);

	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::UserCharacter::Get> { static constexpr int32 Point = 0x5002; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::UserCharacter::Get>::Point> { using Type = Zee::Proto::UserCharacter::Get; }; 
	FORCEINLINE void FromTo(const Zee::Proto::UserCharacter::Get& InFrom, FZeeNetUserCharacterGet& OutTo);
	FORCEINLINE void FromTo(const FZeeNetUserCharacterGet& InFrom, Zee::Proto::UserCharacter::Get& OutTo);

	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::UserCharacter::Select> { static constexpr int32 Point = 0x5003; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::UserCharacter::Select>::Point> { using Type = Zee::Proto::UserCharacter::Select; }; 
	FORCEINLINE void FromTo(const Zee::Proto::UserCharacter::Select& InFrom, FZeeNetUserCharacterSelect& OutTo);
	FORCEINLINE void FromTo(const FZeeNetUserCharacterSelect& InFrom, Zee::Proto::UserCharacter::Select& OutTo);

} 
