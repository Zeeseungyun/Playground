#pragma once
#include "CoreMinimal.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"
#include "ZeeNet/Public/ZeeNetPacket.h"

enum class EZeeNetReponseType
{
	Succeess,
	SocketError,
	UnknownError,
};

struct ZEENET_API IZeeNetResponser
{
public:
	virtual ~IZeeNetResponser() = default;

	template<CZeeNetPacketMessage T>
	EZeeNetReponseType Response(const FZeeNetPacket<T>& InPacket)
	{
		return Response_Impl(&InPacket);
	}

private:
	//do not use directly PacketHeader message.
	template<>
	EZeeNetReponseType Response<FZeeNetPacketHeader>(const FZeeNetPacket<FZeeNetPacketHeader>& InPacket)
	{
		check(0);
		return EZeeNetReponseType::UnknownError;
	}

protected:
	virtual EZeeNetReponseType Response_Impl(const void* InPacketRawPtr) = 0;
};
