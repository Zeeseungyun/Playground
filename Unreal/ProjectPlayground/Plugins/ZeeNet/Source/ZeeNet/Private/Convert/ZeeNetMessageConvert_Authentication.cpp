#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Authentication.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Chat.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Authentication::Login& InFrom, FZeeNetAuthenticationLogin& OutTo)
{
	OutTo.RC = To<EZeeNetAuthenticationReturnCode>(InFrom.rc()); 
	OutTo.Id = To<FString>(InFrom.id()); 
	OutTo.UID = To<int64>(InFrom.uid()); 
	FromTo(InFrom.speak(), OutTo.Speak); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetAuthenticationLogin& InFrom, Zee::Proto::Authentication::Login& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::Authentication::ReturnCode>(InFrom.RC)); 
	OutTo.set_id(To<std::string>(InFrom.Id)); 
	OutTo.set_uid(To<int64>(InFrom.UID)); 
	FromTo(InFrom.Speak, *OutTo.mutable_speak());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Authentication::Logout& InFrom, FZeeNetAuthenticationLogout& OutTo)
{
	OutTo.RC = To<EZeeNetAuthenticationReturnCode>(InFrom.rc()); 
	OutTo.Id = To<FString>(InFrom.id()); 
	OutTo.UID = To<int64>(InFrom.uid()); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetAuthenticationLogout& InFrom, Zee::Proto::Authentication::Logout& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::Authentication::ReturnCode>(InFrom.RC)); 
	OutTo.set_id(To<std::string>(InFrom.Id)); 
	OutTo.set_uid(To<int64>(InFrom.UID)); 
}
