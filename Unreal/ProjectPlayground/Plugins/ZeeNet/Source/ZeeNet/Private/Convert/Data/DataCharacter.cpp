////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
#include "ZeeNet/Private/Convert/Data/DataCharacter.h" 

void Zee::Net::Message::Convert::FromTo(const Zee::Proto::Data::Character& InFrom, FZeeNetDataCharacter& OutTo)
{
	OutTo.UID = To<int64>(InFrom.uid()); 
	OutTo.User = To<int64>(InFrom.user()); 
	OutTo.Id = To<int32>(InFrom.id()); 
	OutTo.Slot = To<int32>(InFrom.slot()); 
	OutTo.Name = To<FString>(InFrom.name()); 
}

void Zee::Net::Message::Convert::FromTo(const FZeeNetDataCharacter& InFrom, Zee::Proto::Data::Character& OutTo)
{
	OutTo.set_uid(To<int64>(InFrom.UID)); 
	OutTo.set_user(To<int64>(InFrom.User)); 
	OutTo.set_id(To<int32>(InFrom.Id)); 
	OutTo.set_slot(To<int32>(InFrom.Slot)); 
	OutTo.set_name(To<std::string>(InFrom.Name)); 
}

