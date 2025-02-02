////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNetMessageSerializer.h " 
#include "ZeeNet/Private/ZeeNetMessageSerializerDef.h" 

#include "ZeeNet/Public/Messages/Authentication.h" 
#include "ZeeNet/Private/Convert/Authentication.h" 
#include "ZeeNet/Public/Messages/Collection.h" 
#include "ZeeNet/Private/Convert/Collection.h" 
#include "ZeeNet/Public/Messages/Dedicate.h" 
#include "ZeeNet/Private/Convert/Dedicate.h" 
#include "ZeeNet/Public/Messages/UserCharacter.h" 
#include "ZeeNet/Private/Convert/UserCharacter.h" 

void FZeeNetPacketSerializerMap::BuildPacketSerializer() 
{ 
	using namespace Zee::Net::Message::Convert; 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetAuthenticationLogin>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetAuthenticationLogin>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetAuthenticationLogout>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetAuthenticationLogout>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetCollectionCollect>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetCollectionCollect>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetCollectionGet>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetCollectionGet>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetDedicateLogin>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetDedicateLogin>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetDedicateMove>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetDedicateMove>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetDedicateLeave>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetDedicateLeave>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetUserCharacterCreate>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetUserCharacterCreate>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetUserCharacterGet>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetUserCharacterGet>>()); 

	DefaultSerializers.Add(TZeeNetPacketTraits<FZeeNetUserCharacterSelect>::Point, 
		MakeShared<FZeeNetPacketSerializer<FZeeNetUserCharacterSelect>>()); 

} 

