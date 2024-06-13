#include "ZeeNetMessageConverter_Chat.g.h"
#include "ZeeNet/Private/ZeeNetMessageConverter.h"

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Chat::Speak& InFrom, FZeeNetChatSpeak& OutTo)
{
	OutTo.Content = To<decltype(OutTo.Content)>(InFrom.content());
	OutTo.RC = To<decltype(OutTo.RC)>(InFrom.rc());
	OutTo.UID = To<decltype(OutTo.UID)>(InFrom.uid());
	OutTo.Id = To<decltype(OutTo.Id)>(InFrom.id());
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetChatSpeak& InFrom, Zee::Proto::Chat::Speak& OutTo)
{
	OutTo.set_content(To<decltype(OutTo.content())>(InFrom.Content));
	OutTo.set_id(To<decltype(OutTo.id())> (InFrom.Id));
	OutTo.set_rc(To<decltype(OutTo.rc())>(InFrom.RC));
	OutTo.set_uid(To<decltype(OutTo.uid())>(InFrom.UID));
}
