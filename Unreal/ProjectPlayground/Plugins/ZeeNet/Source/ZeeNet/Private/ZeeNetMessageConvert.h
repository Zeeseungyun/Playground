#pragma once
#include "CoreMinimal.h"
#include "Containers/StringConv.h"
#include <string>
#include "google/protobuf/repeated_field.h"
#include "ZeeNet/Public/ZeeNetPacketTraits.h"

namespace Zee::Net::Message::Convert
{
	template<int32 Point> struct TZeeNetMapping_PointToProto { using Type = void; };
	template<typename T> struct TZeeNetMapping_ProtoToPoint { static constexpr int32 Point = ZeeNetInvalidMessagePoint; };

	FORCEINLINE static FString ToFString(const std::string& InStr) { return FString(UTF8_TO_TCHAR(InStr.c_str())); }
	FORCEINLINE static std::string ToStdString(const FString& InStr) { return std::string(TCHAR_TO_UTF8(*InStr)); }
	
	template<typename FromT, typename ToT>	
	struct TIsStaticCastable 
	{ 
		enum 
		{ 
			Value = 
			std::is_same_v<FromT, ToT>
			|| (std::is_integral_v<FromT> && std::is_integral_v<ToT>)
			|| (std::is_floating_point_v<FromT> && std::is_floating_point_v<ToT>)
			|| (std::is_enum_v<FromT> && std::is_enum_v<ToT>)
			|| (std::is_integral_v<FromT> && std::is_enum_v<ToT>)
			|| (std::is_enum_v<FromT> && std::is_integral_v<ToT>)
		}; 
	};

	template<typename T, typename Y>
	concept CStaticCastable = TIsStaticCastable<T, Y>::Value;

	FORCEINLINE static void FromTo(const FString& InFrom, std::string& OutTo) { OutTo = ToStdString(InFrom); }
	FORCEINLINE static void FromTo(const std::string& InFrom, FString& OutTo) { OutTo = ToFString(InFrom); }

	template<typename FromT, typename ToT>
	FORCEINLINE static typename TEnableIf< TIsStaticCastable<FromT, ToT>::Value>::Type
		FromTo(const FromT& InFrom, ToT& OutTo) { OutTo = static_cast<ToT>(InFrom); }

	template<typename ToT>
	FORCEINLINE typename TEnableIf<std::is_same_v<ToT, std::string>, std::string>::Type
		To(const FString& InFrom) { return ToStdString(InFrom); }

	template<typename ToT>
	FORCEINLINE typename TEnableIf<std::is_same_v<ToT, FString>, FString>::Type
		To(const std::string& InFrom) { return ToFString(InFrom); }

	template<typename ToT, typename FromT>
	FORCEINLINE typename TEnableIf<TIsStaticCastable<FromT, ToT>::Value, ToT>::Type
		To(const FromT& InFrom) { return static_cast<ToT>(InFrom); }

}
