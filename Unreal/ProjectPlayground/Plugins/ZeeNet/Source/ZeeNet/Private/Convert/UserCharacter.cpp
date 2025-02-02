////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNet/Private/Convert/UserCharacter.h" 
#include "ZeeNet/Private/Convert/Data/DataCharacter.h" 
#include "ZeeNet/Private/Convert/Data/DataDedicate.h" 
#include "ZeeNet/Private/Convert/Data/DataCommon.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::UserCharacter::Create& InFrom, FZeeNetUserCharacterCreate& OutTo)
{
	OutTo.RC = To<EZeeNetUserCharacterReturnCode>(InFrom.rc()); 
	FromTo(InFrom.character(), OutTo.Character); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetUserCharacterCreate& InFrom, Zee::Proto::UserCharacter::Create& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::UserCharacter::ReturnCode>(InFrom.RC)); 
	FromTo(InFrom.Character, *OutTo.mutable_character());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::UserCharacter::Get& InFrom, FZeeNetUserCharacterGet& OutTo)
{
	OutTo.RC = To<EZeeNetUserCharacterReturnCode>(InFrom.rc()); 
	OutTo.User = To<int64>(InFrom.user()); 
	OutTo.Characters.Reserve(InFrom.characters().size());
	for (const auto& Elem : InFrom.characters()) { FromTo(Elem, OutTo.Characters.AddZeroed_GetRef()); }
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetUserCharacterGet& InFrom, Zee::Proto::UserCharacter::Get& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::UserCharacter::ReturnCode>(InFrom.RC)); 
	OutTo.set_user(To<int64>(InFrom.User)); 
	OutTo.mutable_characters()->Reserve(InFrom.Characters.Num());
	for (const auto& Elem : InFrom.Characters) { FromTo(Elem, *OutTo.mutable_characters()->Add()); }
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::UserCharacter::Select& InFrom, FZeeNetUserCharacterSelect& OutTo)
{
	OutTo.RC = To<EZeeNetUserCharacterReturnCode>(InFrom.rc()); 
	FromTo(InFrom.character(), OutTo.Character); 
	FromTo(InFrom.toserver(), OutTo.ToServer); 
	FromTo(InFrom.position(), OutTo.Position); 
	OutTo.UserIp = To<FString>(InFrom.userip()); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetUserCharacterSelect& InFrom, Zee::Proto::UserCharacter::Select& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::UserCharacter::ReturnCode>(InFrom.RC)); 
	FromTo(InFrom.Character, *OutTo.mutable_character());
	FromTo(InFrom.ToServer, *OutTo.mutable_toserver());
	FromTo(InFrom.Position, *OutTo.mutable_position());
	OutTo.set_userip(To<std::string>(InFrom.UserIp)); 
}

