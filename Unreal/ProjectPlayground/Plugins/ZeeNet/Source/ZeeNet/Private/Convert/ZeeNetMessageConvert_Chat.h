////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once 
#include "CoreMinimal.h" 
#include "ZeeNet/Public/Messages/Chat.h" 
#include "ZeeNet/Private/Messages/Chat.pb.h" 
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 

namespace Zee::Net::Message::Convert 
{ 
	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak> { static constexpr int32 Point = 0x2002; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak>::Point> { using Type = Zee::Proto::Chat::Speak; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Chat::Speak& InFrom, FZeeNetChatSpeak& OutTo);
	FORCEINLINE void FromTo(const FZeeNetChatSpeak& InFrom, Zee::Proto::Chat::Speak& OutTo);

	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak1> { static constexpr int32 Point = 0x2001; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak1>::Point> { using Type = Zee::Proto::Chat::Speak1; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Chat::Speak1& InFrom, FZeeNetChatSpeak1& OutTo);
	FORCEINLINE void FromTo(const FZeeNetChatSpeak1& InFrom, Zee::Proto::Chat::Speak1& OutTo);

} 