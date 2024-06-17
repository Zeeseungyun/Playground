////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetMessageSerializer.h " 
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h" 

#include "ZeeNet/Public/Messages/Authentication.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Authentication.h" 
#include "ZeeNet/Public/Messages/Chat.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Chat.h" 
#include "ZeeNet/Public/Messages/Packet.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Packet.h" 
#include "ZeeNet/Public/Messages/Test.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Test.h" 
#include "ZeeNet/Public/Messages/Test2.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Test2.h" 

void FZeeNetPacketSerializerMap::BuildPacketSerializer() 
{ 
	using namespace Zee::Net::Message::Convert; 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Login>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Login>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Logout>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Logout>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak1>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak1>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Packet::Header>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Packet::Header>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::TestMessage>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::TestMessage>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage2>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage2>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage3>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage3>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage4>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage4>::Point>>()); 

	DefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage5>::Point, 
		MakeShared<FZeeNetPacketSerializer<TZeeNetMapping_ProtoToPoint<Zee::Proto::Test2::TestMessage5>::Point>>()); 

} 

