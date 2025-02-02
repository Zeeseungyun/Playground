////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNet/Private/Convert/Dedicate.h" 
#include "ZeeNet/Private/Convert/Data/DataDedicate.h" 
#include "ZeeNet/Private/Convert/Data/DataCharacter.h" 
#include "ZeeNet/Private/Convert/Data/DataCommon.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Dedicate::Login& InFrom, FZeeNetDedicateLogin& OutTo)
{
	OutTo.RC = To<EZeeNetDedicateReturnCode>(InFrom.rc()); 
	FromTo(InFrom.dedicateserver(), OutTo.DedicateServer); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetDedicateLogin& InFrom, Zee::Proto::Dedicate::Login& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::Dedicate::ReturnCode>(InFrom.RC)); 
	FromTo(InFrom.DedicateServer, *OutTo.mutable_dedicateserver());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Dedicate::Move& InFrom, FZeeNetDedicateMove& OutTo)
{
	OutTo.RC = To<EZeeNetDedicateReturnCode>(InFrom.rc()); 
	FromTo(InFrom.character(), OutTo.Character); 
	FromTo(InFrom.toserver(), OutTo.ToServer); 
	FromTo(InFrom.position(), OutTo.Position); 
	OutTo.UserIp = To<FString>(InFrom.userip()); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetDedicateMove& InFrom, Zee::Proto::Dedicate::Move& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::Dedicate::ReturnCode>(InFrom.RC)); 
	FromTo(InFrom.Character, *OutTo.mutable_character());
	FromTo(InFrom.ToServer, *OutTo.mutable_toserver());
	FromTo(InFrom.Position, *OutTo.mutable_position());
	OutTo.set_userip(To<std::string>(InFrom.UserIp)); 
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Dedicate::Leave& InFrom, FZeeNetDedicateLeave& OutTo)
{
	FromTo(InFrom.character(), OutTo.Character); 
	FromTo(InFrom.position(), OutTo.Position); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetDedicateLeave& InFrom, Zee::Proto::Dedicate::Leave& OutTo)
{
	FromTo(InFrom.Character, *OutTo.mutable_character());
	FromTo(InFrom.Position, *OutTo.mutable_position());
}

