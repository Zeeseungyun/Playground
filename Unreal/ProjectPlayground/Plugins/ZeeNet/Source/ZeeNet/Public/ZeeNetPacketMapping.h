#pragma once

static constexpr int32 ZeeNetInvalidMessagePoint = 0;

template<int32 Point> struct TZeeNetMapping_PointToUnreal { using Type = void; };
template<typename T> struct TZeeNetMapping_UnrealToPoint { static constexpr int32 Point = ZeeNetInvalidMessagePoint; };

template<typename T>
struct TZeeNetIsValidMapping 
{
	enum { Value = TZeeNetMapping_UnrealToPoint<T>::Point != ZeeNetInvalidMessagePoint	};
};
