#pragma once
#include "ZeeNet/Private/ZeeNetMessageSerializer.h"
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 
#include "ZeeNet/Public/ZeeNetPacketMapping.h" 
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Packet.h"

template<int32 MessagePoint> struct FZeeNetPacket;

template<>
struct FZeeNetPacket<TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point> final : public FZeeNetPacketSerializerBase
{
public:
	using ProtoType = Zee::Proto::Packet::Header;
	using UnrealType = FZeeNetPacketHeader;

	friend class FZeeNetClient;
public:
	const void* GetMessage() const final { return &Header; }
	void SetMessageInternal(const void* InMessagePtr) final { Header = *(const UnrealType*)(InMessagePtr); }

	//return read bytes.
	int32 Deserialize(const uint8* InBuffer, int32 InBufferSize) final
	{
		int32 HeaderSize = 0;
		int32 ReadBytes = ReadBuffer(InBuffer, HeaderSize);
		check(HeaderSize <= InBufferSize);

		ProtoType ProtoMessage;
		if (!ProtoMessage.ParseFromArray(InBuffer + ReadBytes, HeaderSize))
		{
			check(0);
		}

		Zee::Net::Message::Convert::FromTo(ProtoMessage, Header);

		return HeaderSize + ReadBytes;
	}

	//return written bytes.
	int32 Serialize(uint8* OutBuffer, int32 InBufferSize) const final
	{
		ProtoType ProtoMessage;
		Zee::Net::Message::Convert::FromTo(Header, ProtoMessage);
		const int32 HeaderSize = (int32)ProtoMessage.ByteSizeLong();

		int32 WrittenBytes = WriteBuffer(OutBuffer, HeaderSize);
		check(InBufferSize - WrittenBytes >= 0);

		if (!ProtoMessage.SerializeToArray(OutBuffer + WrittenBytes, InBufferSize - WrittenBytes))
		{
			check(0);
			return 0;
		}

		return HeaderSize;
	}

	virtual TSharedPtr<FZeeNetPacketSerializerBase> Clone() const final
	{
		return TSharedPtr<FZeeNetPacketSerializerBase>(MakeShared<FZeeNetPacket>(*this));
	}
};

template<int32 MessagePoint>
struct FZeeNetPacket final
	: public FZeeNetPacketSerializerBase
{
public:
	using ProtoType = typename Zee::Net::Message::Convert::TZeeNetMapping_PointToProto<MessagePoint>::Type;
	using UnrealType = typename TZeeNetMapping_PointToUnreal<MessagePoint>::Type;
	
	FZeeNetPacket()
	{
		this->Header.Point = MessagePoint;
	}

private:
	UnrealType UnrealMessage;

public:
	const void* GetMessage() const final { return &UnrealMessage; }
	void SetMessageInternal(const void* InMessagePtr) final { UnrealMessage = *(const UnrealType*)(InMessagePtr); }

	//return read bytes.
	int32 Deserialize(const uint8* InBuffer, int32 InBufferSize) final
	{
		//Header멤버는 NetClient가 이미 설정함.
		 
		////header read first.
		//int32 ReadBytes = 0;
		//{
		//	HeaderType HeaderRead;
		//	ReadBytes = HeaderRead.Deserialize(InBuffer, InBufferSize);
		//	Header = HeaderRead.Header;
		//}

		ProtoType ProtoMessage;
		if (!ProtoMessage.ParseFromArray(InBuffer, InBufferSize))
		{
			check(0);
		}

		Zee::Net::Message::Convert::FromTo(ProtoMessage, UnrealMessage);
		return InBufferSize;
	}

	//return written bytes.
	int32 Serialize(uint8* OutBuffer, int32 InBufferSize) const final
	{
		ProtoType ProtoMessage;
		Zee::Net::Message::Convert::FromTo(UnrealMessage, ProtoMessage);
		const int32 PacketSize = (int32)ProtoMessage.ByteSizeLong();

		//header write first.
		int32 WrittenBytes = 0;
		{
			using HeaderType = FZeeNetPacket<TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point>;
			HeaderType HeaderWrite;
			HeaderWrite.Header = Header;
			Header.PacketSize = PacketSize;
			WrittenBytes = HeaderWrite.Serialize(OutBuffer, InBufferSize);
		}

		check(InBufferSize - WrittenBytes >= PacketSize);

		if (!ProtoMessage.SerializeToArray(OutBuffer + WrittenBytes, InBufferSize - WrittenBytes))
		{
			check(0);
			return 0;
		}

		WrittenBytes += PacketSize;
		return WrittenBytes;
	}

	virtual TSharedPtr<FZeeNetPacketSerializerBase> Clone() const final 
	{
		return TSharedPtr<FZeeNetPacketSerializerBase>(MakeShared<FZeeNetPacket>(*this));
	}
};
