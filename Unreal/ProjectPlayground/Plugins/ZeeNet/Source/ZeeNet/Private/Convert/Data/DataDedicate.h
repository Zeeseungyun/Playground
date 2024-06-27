////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once 
#include "CoreMinimal.h" 
#include "ZeeNet/Public/Messages/Data/DataDedicate.h" 
#include "ZeeNet/Private/Messages/Data/DataDedicate.pb.h" 
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 

namespace Zee::Net::Message::Convert 
{ 
	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Data::DedicateServer> { static constexpr int32 Point = 0x9001; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Data::DedicateServer>::Point> { using Type = Zee::Proto::Data::DedicateServer; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Data::DedicateServer& InFrom, FZeeNetDataDedicateServer& OutTo);
	FORCEINLINE void FromTo(const FZeeNetDataDedicateServer& InFrom, Zee::Proto::Data::DedicateServer& OutTo);

} 