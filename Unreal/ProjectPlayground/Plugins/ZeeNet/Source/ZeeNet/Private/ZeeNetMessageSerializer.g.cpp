#include "ZeeNetMessageSerializer.h"
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Authentication.h"
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Chat.h"

static constexpr int32 HeaderSize = sizeof(int32 /*TotalSize*/) + sizeof(int32 /*Point*/) + sizeof(int32/*Sequence*/) + sizeof(uint8 /*bIsRespond*/);

template<int32 MessagePoint>
struct FZeeNetPacket final
	: public FZeeNetPacketBase
{
public:
	using ProtoType = typename Zee::Net::Message::Convert::TZeeNetMapping_PointToProto<MessagePoint>::Type;
	using UnrealType = typename TZeeNetMapping_PointToUnreal<MessagePoint>::Type;

	FZeeNetPacket()
	{
		this->Point = MessagePoint;
	}

private:
	UnrealType UnrealMessage;

public:
	const void* GetMessageInternal() const final { return &UnrealMessage; }
	void SetMessageInternal(const void* InMessagePtr) final { UnrealMessage = *(const UnrealType*)(InMessagePtr); }

	//retrun readbytes.
	int32 Deserialize(const uint8* Buffer, int32 Size) final
	{
		int32 Offset = 0;
		const int32 TotalSize = *(const int32*)Buffer;
		Buffer += sizeof(int32);

		const int32 ReadPoint = *(const int32*)Buffer;
		Buffer += sizeof(int32);
		check(Point == ReadPoint);

		Sequence = *(const int32*)Buffer;
		Buffer += sizeof(int32);

		bIsRespond = (*(const uint8*)Buffer)? true : false;
		Buffer += sizeof(uint8);

		ProtoType ProtoMessage;
		ProtoMessage.ParseFromArray(Buffer, TotalSize - sizeof(int32));
		Zee::Net::Message::Convert::FromTo(ProtoMessage, UnrealMessage);

		return TotalSize;
	}

	//return writebytes.
	int32 Serialize(uint8* Buffer, int32 InBound) const final
	{
		ProtoType ProtoMessage;
		Zee::Net::Message::Convert::FromTo(UnrealMessage, ProtoMessage);

		const int32 MessageSize = (int32)ProtoMessage.ByteSizeLong();
		const int32 TotalSize = MessageSize + HeaderSize;

		int32 Offset = 0;
		*(int32*)Buffer = TotalSize;
		Offset += sizeof(int32);
		Buffer += sizeof(int32);

		*(int32*)Buffer = Point;
		Offset += sizeof(int32);
		Buffer += sizeof(int32);

		*(int32*)Buffer = Sequence;
		Offset += sizeof(int32);
		Buffer += sizeof(int32);

		*(uint8*)Buffer = bIsRespond ? 1 : 0;
		Offset += sizeof(uint8);
		Buffer += sizeof(uint8);

		if (!ProtoMessage.SerializeToArray(Buffer, InBound - Offset))
		{
			check(0);
			return -1;
		}

		return TotalSize;
	}

	virtual TSharedPtr<FZeeNetPacketBase> Clone() const final 
	{
		return TSharedPtr<FZeeNetPacketBase>(MakeShared<FZeeNetPacket>(*this));
	}
};

void FZeeNetPacketSerializer::BuildDefaultPackets()
{
	using namespace Zee::Net::Message::Convert;

	DefaultMessages.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak>::Point, 
		MakeShared<FZeeNetPacket<TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak>::Point>>());

	DefaultMessages.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak1>::Point,
		MakeShared<FZeeNetPacket<TZeeNetMapping_ProtoToPoint<Zee::Proto::Chat::Speak1>::Point>>());

	DefaultMessages.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Login>::Point,
		MakeShared<FZeeNetPacket<TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Login>::Point>>());

	DefaultMessages.Add(TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Logout>::Point,
		MakeShared<FZeeNetPacket<TZeeNetMapping_ProtoToPoint<Zee::Proto::Authentication::Logout>::Point>>());
}
