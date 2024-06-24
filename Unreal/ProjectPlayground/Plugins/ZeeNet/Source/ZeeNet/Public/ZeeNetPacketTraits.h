#pragma once

static constexpr int32 ZeeNetInvalidMessagePoint = 0;

template<typename T>
struct TZeeNetPacketTraits
{
	static constexpr int32 Point = ZeeNetInvalidMessagePoint;
	static constexpr bool bIsData = false;
};

template<typename T>
struct TZeeNetIsValidPacket
{
	static constexpr bool Value = TZeeNetPacketTraits<T>::Point != ZeeNetInvalidMessagePoint && !TZeeNetPacketTraits<T>::bIsData;
};

template<typename T>
concept CZeeNetPacketMessage = TZeeNetIsValidPacket<T>::Value;
