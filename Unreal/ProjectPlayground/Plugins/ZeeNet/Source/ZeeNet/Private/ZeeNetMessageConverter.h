#pragma once
#include "CoreMinimal.h"
#include "Containers/StringConv.h"
#include <string>
#include "ZeeNet/Private/Messages/Chat.pb.h"
#include "ZeeNet/Public/Messages/Chat.h"

//C:\Users\zee\source\repos\UE5\UE5\Engine\Source\Runtime\Core\Public\Containers\StringConv.h
namespace Zee::Net::Message::Convert
{
	FORCEINLINE static FString ToFString(const std::string& InStr) { return FString(UTF8_TO_TCHAR(InStr.c_str())); }
	FORCEINLINE static std::string ToStdString(const FString& InStr) { return std::string(TCHAR_TO_UTF8(*InStr)); }
	
	template<typename FromT, typename ToT>	struct TIsConvertible { enum { Value = false }; };

	template<typename ToT, typename FromT>
	FORCEINLINE static constexpr
		TEnableIf<TIsConvertible<FromT, typename TDecay<ToT>::Type>::Value, ToT>::Type
		To(const FromT& InFrom) noexcept { ToT Ret; FromTo(InFrom, Ret); return Ret; }

	template<typename ToT, typename FromT>
	FORCEINLINE static constexpr 
		TEnableIf<TIsEnum<FromT>::Value && TIsEnum<ToT>::Value, ToT>::Type
		To(const FromT& InFrom) noexcept { return static_cast<ToT>(InFrom); }

	template<typename ToT, typename FromT>
	FORCEINLINE static constexpr 
		TEnableIf<TIsIntegral<FromT>::Value && TIsIntegral<ToT>::Value, ToT>::Type
		To(const FromT& InFrom) noexcept { return static_cast<ToT>(InFrom); }

	template<typename ToT>
	FORCEINLINE static 
		TEnableIf<std::is_same_v<typename TDecay<ToT>::Type, std::string>, std::string>::Type
		To(const FString& InFrom) noexcept { return ToStdString(InFrom); }

	template<typename ToT>
	FORCEINLINE static 
		TEnableIf<std::is_same_v<typename TDecay<ToT>::Type, FString>, FString>::Type
		To(const std::string& InFrom) noexcept { return ToFString(InFrom); }

	template<typename ToT, typename FromT>
	FORCEINLINE static constexpr 
		TEnableIf<TIsFloatingPoint<FromT>::Value && TIsFloatingPoint<ToT>::Value, ToT>::Type
		To(const FromT& InFrom) noexcept { return static_cast<ToT>(InFrom); }
}
