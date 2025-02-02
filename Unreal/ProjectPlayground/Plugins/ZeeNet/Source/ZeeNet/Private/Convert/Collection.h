////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once 
#include "CoreMinimal.h" 
#include "ZeeNet/Public/Messages/Collection.h" 
#include "ZeeNet/Private/Messages/Collection.pb.h" 
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 

namespace Zee::Net::Message::Convert 
{ 
	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Collection::Collect> { static constexpr int32 Point = 0x2001; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Collection::Collect>::Point> { using Type = Zee::Proto::Collection::Collect; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Collection::Collect& InFrom, FZeeNetCollectionCollect& OutTo);
	FORCEINLINE void FromTo(const FZeeNetCollectionCollect& InFrom, Zee::Proto::Collection::Collect& OutTo);

	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Collection::Get> { static constexpr int32 Point = 0x2002; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Collection::Get>::Point> { using Type = Zee::Proto::Collection::Get; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Collection::Get& InFrom, FZeeNetCollectionGet& OutTo);
	FORCEINLINE void FromTo(const FZeeNetCollectionGet& InFrom, Zee::Proto::Collection::Get& OutTo);

} 
