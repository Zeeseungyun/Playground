////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once 
#include "CoreMinimal.h" 
#include "ZeeNet/Public/Messages/Dedicate.h" 
#include "ZeeNet/Private/Messages/Dedicate.pb.h" 
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 

namespace Zee::Net::Message::Convert 
{ 
	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Dedicate::Login> { static constexpr int32 Point = 0x3001; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Dedicate::Login>::Point> { using Type = Zee::Proto::Dedicate::Login; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Dedicate::Login& InFrom, FZeeNetDedicateLogin& OutTo);
	FORCEINLINE void FromTo(const FZeeNetDedicateLogin& InFrom, Zee::Proto::Dedicate::Login& OutTo);

	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Dedicate::Move> { static constexpr int32 Point = 0x3002; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Dedicate::Move>::Point> { using Type = Zee::Proto::Dedicate::Move; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Dedicate::Move& InFrom, FZeeNetDedicateMove& OutTo);
	FORCEINLINE void FromTo(const FZeeNetDedicateMove& InFrom, Zee::Proto::Dedicate::Move& OutTo);

	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Dedicate::Leave> { static constexpr int32 Point = 0x3003; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Dedicate::Leave>::Point> { using Type = Zee::Proto::Dedicate::Leave; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Dedicate::Leave& InFrom, FZeeNetDedicateLeave& OutTo);
	FORCEINLINE void FromTo(const FZeeNetDedicateLeave& InFrom, Zee::Proto::Dedicate::Leave& OutTo);

} 