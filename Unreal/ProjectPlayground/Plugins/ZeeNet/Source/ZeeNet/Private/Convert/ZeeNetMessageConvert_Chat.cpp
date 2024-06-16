#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Chat.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Chat::Speak& InFrom, FZeeNetChatSpeak& OutTo)
{
	OutTo.RC = To<EZeeNetChatReturnCode>(InFrom.rc()); 
	OutTo.UID = To<int64>(InFrom.uid()); 
	OutTo.Id = To<FString>(InFrom.id()); 
	OutTo.Content = To<FString>(InFrom.content()); 
	FromTo(InFrom.contents(), OutTo.Contents); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetChatSpeak& InFrom, Zee::Proto::Chat::Speak& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::Chat::ReturnCode>(InFrom.RC)); 
	OutTo.set_uid(To<int64>(InFrom.UID)); 
	OutTo.set_id(To<std::string>(InFrom.Id)); 
	OutTo.set_content(To<std::string>(InFrom.Content)); 
	FromTo(InFrom.Contents, *OutTo.mutable_contents());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Chat::Speak1& InFrom, FZeeNetChatSpeak1& OutTo)
{
	OutTo.RC = To<EZeeNetChatReturnCode>(InFrom.rc()); 
	OutTo.UID = To<int64>(InFrom.uid()); 
	OutTo.Id = To<FString>(InFrom.id()); 
	OutTo.Content = To<FString>(InFrom.content()); 
	FromTo(InFrom.speak1(), OutTo.Speak1); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetChatSpeak1& InFrom, Zee::Proto::Chat::Speak1& OutTo)
{
	OutTo.set_rc(To<Zee::Proto::Chat::ReturnCode>(InFrom.RC)); 
	OutTo.set_uid(To<int64>(InFrom.UID)); 
	OutTo.set_id(To<std::string>(InFrom.Id)); 
	OutTo.set_content(To<std::string>(InFrom.Content)); 
	FromTo(InFrom.Speak1, *OutTo.mutable_speak1());
}
