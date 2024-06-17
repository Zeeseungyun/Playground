#pragma once

static constexpr int32 ZeeNetInvalidMessagePoint = 0;

template<int32 Point> struct TZeeNetMapping_PointToUnreal { using Type = void; };
template<typename T> struct TZeeNetMapping_UnrealToPoint { static constexpr int32 Point = ZeeNetInvalidMessagePoint; };

template<typename T>
struct TZeeNetIsValidMapping 
{
	static constexpr bool Value = TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint;
};

template<typename T>
concept CZeeNetPacketMessage = TZeeNetIsValidMapping<T>::Value;
