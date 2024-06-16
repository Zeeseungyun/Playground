#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Test2.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Test.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Test2::TestMessage2& InFrom, FZeeNetTest2TestMessage2& OutTo)
{
	FromTo(InFrom.msg(), OutTo.msg); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetTest2TestMessage2& InFrom, Zee::Proto::Test2::TestMessage2& OutTo)
{
	FromTo(InFrom.msg, *OutTo.mutable_msg());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Test2::TestMessage3& InFrom, FZeeNetTest2TestMessage3& OutTo)
{
	FromTo(InFrom.msg1(), OutTo.msg1); 
	FromTo(InFrom.msg2(), OutTo.msg2); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetTest2TestMessage3& InFrom, Zee::Proto::Test2::TestMessage3& OutTo)
{
	FromTo(InFrom.msg1, *OutTo.mutable_msg1());
	FromTo(InFrom.msg2, *OutTo.mutable_msg2());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Test2::TestMessage4& InFrom, FZeeNetTest2TestMessage4& OutTo)
{
	FromTo(InFrom.msg1(), OutTo.msg1); 
	FromTo(InFrom.msg2(), OutTo.msg2); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetTest2TestMessage4& InFrom, Zee::Proto::Test2::TestMessage4& OutTo)
{
	FromTo(InFrom.msg1, *OutTo.mutable_msg1());
	FromTo(InFrom.msg2, *OutTo.mutable_msg2());
}

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Test2::TestMessage5& InFrom, FZeeNetTest2TestMessage5& OutTo)
{
	FromTo(InFrom.msg2(), OutTo.msg2); 
	FromTo(InFrom.msg3(), OutTo.msg3); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetTest2TestMessage5& InFrom, Zee::Proto::Test2::TestMessage5& OutTo)
{
	FromTo(InFrom.msg2, *OutTo.mutable_msg2());
	FromTo(InFrom.msg3, *OutTo.mutable_msg3());
}
