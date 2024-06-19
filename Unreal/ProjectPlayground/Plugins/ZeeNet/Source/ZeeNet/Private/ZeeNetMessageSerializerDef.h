#pragma once
#include "ZeeNet/Private/ZeeNetMessageSerializer.h"
#include "ZeeNet/Private/ZeeNetMessageConvert.h" 
#include "ZeeNet/Public/ZeeNetPacketMapping.h" 
#include "ZeeNet/Public/ZeeNetPacket.h"
#include "ZeeNet/Private/Convert/ZeeNetMessageConvert_Packet.h"

template<int32 MessagePoint> struct FZeeNetPacketSerializer;

template<>
struct FZeeNetPacketSerializer<TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point> final : public FZeeNetPacketSerializerBase
{
public:
	using ProtoType = Zee::Proto::Packet::Header;
	using UnrealType = FZeeNetPacketHeader;

	friend class FZeeNetClient;

	FZeeNetPacket<FZeeNetPacketHeader> UnrealMessage;

	FZeeNetPacketHeader& GetHeader() const final
	{
		return const_cast<FZeeNetPacketSerializer*>(this)->UnrealMessage.Header;
	}

	FZeeNetPacketSerializer() = default;

public:
	void* GetMessage() const final { return &const_cast<FZeeNetPacketSerializer*>(this)->GetHeader(); }
	void* GetPacket() const final { return GetMessage(); }

	void SetMessageInternal(const void* InMessagePtr) final { GetHeader() = *(const UnrealType*)(InMessagePtr); }

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

		Zee::Net::Message::Convert::FromTo(ProtoMessage, GetHeader());
		return HeaderSize + ReadBytes;
	}

	//return written bytes.
	int32 Serialize(uint8* OutBuffer, int32 InBufferSize) const final
	{
		ProtoType ProtoMessage;
		Zee::Net::Message::Convert::FromTo(GetHeader(), ProtoMessage);
		const int32 HeaderSize = (int32)ProtoMessage.ByteSizeLong();

		int32 WrittenBytes = WriteBuffer(OutBuffer, HeaderSize);
		check(InBufferSize - WrittenBytes >= 0);

		if (!ProtoMessage.SerializeToArray(OutBuffer + WrittenBytes, InBufferSize - WrittenBytes))
		{
			check(0);
			return 0;
		}

		return HeaderSize + sizeof(HeaderSize);
	}

	virtual TSharedPtr<FZeeNetPacketSerializerBase> Clone() const final
	{
		return TSharedPtr<FZeeNetPacketSerializerBase>(MakeShared<FZeeNetPacketSerializer>(*this));
	}
};

template<int32 MessagePoint>
struct FZeeNetPacketSerializer final
	: public FZeeNetPacketSerializerBase
{
public:
	using ProtoType = typename Zee::Net::Message::Convert::TZeeNetMapping_PointToProto<MessagePoint>::Type;
	using UnrealType = typename TZeeNetMapping_PointToUnreal<MessagePoint>::Type;
	
	FZeeNetPacketSerializer()
	{
		UnrealMessage.Header.Point = MessagePoint;
	}

private:
	FZeeNetPacket<UnrealType> UnrealMessage;

	FZeeNetPacketHeader& GetHeader() const final
	{
		return const_cast<FZeeNetPacketSerializer*>(this)->UnrealMessage.Header;
	}

public:
	void* GetMessage() const final { return &const_cast<FZeeNetPacketSerializer*>(this)->UnrealMessage.Message; }
	void* GetPacket() const final { return &const_cast<FZeeNetPacketSerializer*>(this)->UnrealMessage; }

	void SetMessageInternal(const void* InMessagePtr) final { UnrealMessage.Message = *reinterpret_cast<const UnrealType*>(InMessagePtr); }

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

		Zee::Net::Message::Convert::FromTo(ProtoMessage, GetCastMutableMessage<UnrealType>());
		return InBufferSize;
	}

	//return written bytes.
	int32 Serialize(uint8* OutBuffer, int32 InBufferSize) const final
	{
		ProtoType ProtoMessage;
		Zee::Net::Message::Convert::FromTo(GetCastMessage<UnrealType>(), ProtoMessage);
		GetHeader().PacketSize = (int32)ProtoMessage.ByteSizeLong();

		//header write first.
		int32 WrittenBytes = 0;
		{
			using HeaderType = FZeeNetPacketSerializer<TZeeNetMapping_UnrealToPoint<FZeeNetPacketHeader>::Point>;
			HeaderType HeaderWrite;
			HeaderWrite.GetHeader() = GetHeader();
			WrittenBytes = HeaderWrite.Serialize(OutBuffer, InBufferSize);
		}

		check(InBufferSize - WrittenBytes >= GetHeader().PacketSize);

		if (!ProtoMessage.SerializeToArray(OutBuffer + WrittenBytes, InBufferSize - WrittenBytes))
		{
			check(0);
			return 0;
		}

		WrittenBytes += GetHeader().PacketSize;
		return WrittenBytes;
	}

	virtual TSharedPtr<FZeeNetPacketSerializerBase> Clone() const final 
	{
		return TSharedPtr<FZeeNetPacketSerializerBase>(MakeShared<FZeeNetPacketSerializer>(*this));
	}
};
