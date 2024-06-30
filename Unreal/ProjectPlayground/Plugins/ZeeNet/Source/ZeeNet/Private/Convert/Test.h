////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#pragma once 
#include "CoreMinimal.h" 
#include "ZeeNet/Public/Messages/Test.h" 
#include "ZeeNet/Private/Messages/Test.pb.h" 
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 

namespace Zee::Net::Message::Convert 
{ 
	template<> struct TZeeNetMapping_ProtoToPoint<Zee::Proto::Test::TestMessage> { static constexpr int32 Point = 0x5001; }; 
	template<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<Zee::Proto::Test::TestMessage>::Point> { using Type = Zee::Proto::Test::TestMessage; }; 
	FORCEINLINE void FromTo(const Zee::Proto::Test::TestMessage& InFrom, FZeeNetTestTestMessage& OutTo);
	FORCEINLINE void FromTo(const FZeeNetTestTestMessage& InFrom, Zee::Proto::Test::TestMessage& OutTo);

} 
