#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Test.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::TestMessage& InFrom, FZeeNetTestMessage& OutTo)
{
	FromTo(InFrom.rc(), OutTo.RC); 
	OutTo.RCLists = To<EZeeNetReturnCode>(InFrom.rclists()); 
	OutTo.Id = To<FString>(InFrom.id()); 
	OutTo.Content = To<FString>(InFrom.content()); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetTestMessage& InFrom, Zee::Proto::TestMessage& OutTo)
{
	FromTo(InFrom.RC, *OutTo.mutable_rc());
	*OutTo.mutable_rclists() = To<int32>(InFrom.RCLists); 
	OutTo.set_id(To<std::string>(InFrom.Id)); 
	OutTo.set_content(To<std::string>(InFrom.Content)); 
}
