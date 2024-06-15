#pragma once
#include "CoreMinimal.h"
#include "Containers/StringConv.h"
#include <string>
#include "google/protobuf/repeated_field.h"

namespace Zee::Net::Message::Convert
{
	template<int32 Point> struct TZeeNetMapping_PointToProto { using Type = void; };
	template<typename T> struct TZeeNetMapping_ProtoToPoint { static constexpr int32 Point = 0; };

	FORCEINLINE static FString ToFString(const std::string& InStr) { return FString(UTF8_TO_TCHAR(InStr.c_str())); }
	FORCEINLINE static std::string ToStdString(const FString& InStr) { return std::string(TCHAR_TO_UTF8(*InStr)); }
	
	template<typename FromT, typename ToT>	struct TIsStaticCastable 
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

	FORCEINLINE static void FromTo(const google::protobuf::RepeatedPtrField<std::string>& InFrom, TArray<FString>& OutTo)
	{
		OutTo.Reserve(InFrom.size());
		for (const std::string& Elem : InFrom)
		{
			OutTo.Add(ToFString(Elem));
		}
	}

	FORCEINLINE static void FromTo(const TArray<FString>& InFrom, google::protobuf::RepeatedPtrField<std::string>& OutTo)
	{
		OutTo.Reserve(InFrom.Num());
		for (const FString& Elem : InFrom)
		{
			OutTo.Add(ToStdString(Elem));
		}
	}

	template<typename ToT, typename FromT>
	FORCEINLINE 
		typename TEnableIf<TIsStaticCastable<FromT, ToT>::Value>::Type
		FromTo(const TArray<FromT>& InFrom, google::protobuf::RepeatedField<ToT>& OutTo)
	{
		OutTo.Reserve(InFrom.Num());
		for (const FromT& Elem : InFrom)
		{
			OutTo.Add(static_cast<ToT>(Elem));
		}
	}

	template<typename ToT, typename FromT>
	FORCEINLINE 
		typename TEnableIf<TIsStaticCastable<FromT, ToT>::Value>::Type
		FromTo(const google::protobuf::RepeatedField<FromT>& InFrom, TArray<ToT>& OutTo)
	{
		OutTo.Reserve(InFrom.size());
		for (const FromT& Elem : InFrom)
		{
			OutTo.Add(static_cast<ToT>(Elem));
		}
	}

	template<typename ToT, typename FromT>
	FORCEINLINE
		typename TEnableIf<!TIsStaticCastable<FromT, ToT>::Value>::Type
		FromTo(const TArray<FromT>& InFrom, google::protobuf::RepeatedField<ToT>& OutTo)
	{
		OutTo.Reserve(InFrom.Num());
		for (const FromT& Elem : InFrom)
		{
			FromTo(Elem, *OutTo.AddAlreadyReserved());
		}
	}

	template<typename ToT, typename FromT>
	FORCEINLINE 
		typename TEnableIf<!TIsStaticCastable<FromT, ToT>::Value>::Type
		FromTo(const google::protobuf::RepeatedField<FromT>& InFrom, TArray<ToT>& OutTo)
	{
		OutTo.AddUninitialized(InFrom.size());
		int32 i = 0;
		for (const FromT& Elem : InFrom)
		{
			FromTo(Elem, OutTo[i++]);
		}
	}

	template<typename ToT, typename FromT>
	FORCEINLINE 
		typename TEnableIf<TIsStaticCastable<FromT, ToT>::Value, google::protobuf::RepeatedField<ToT>>::Type
		To(const TArray<FromT>& InFrom) 
	{
		google::protobuf::RepeatedField<ToT> Ret;
		Ret.Reserve(InFrom.Num());
		for (const FromT& Elem : InFrom)
		{
			Ret.Add(static_cast<ToT>(Elem));
		}

		return Ret;
	}

	template<typename ToT, typename FromT>
	FORCEINLINE
		typename TEnableIf<TIsStaticCastable<FromT, ToT>::Value, TArray<ToT>>::Type
		To(const google::protobuf::RepeatedField<FromT>& InFrom) 
	{
		TArray<ToT> Ret;
		Ret.Reserve(InFrom.size());
		for (const FromT& Elem : InFrom)
		{
			Ret.Add(static_cast<ToT>(Elem));
		}

		return Ret;
	}

	template<typename ToT>
	FORCEINLINE
		typename TEnableIf<std::is_same_v<ToT, std::string>, std::string>::Type
		To(const FString& InFrom) { return ToStdString(InFrom); }

	template<typename ToT>
	FORCEINLINE
		typename TEnableIf<std::is_same_v<ToT, FString>, FString>::Type
		To(const std::string& InFrom) { return ToFString(InFrom); }

	template<typename ToT, typename FromT>
	FORCEINLINE
		typename TEnableIf<TIsStaticCastable<FromT, ToT>::Value, ToT>::Type
		To(const FromT& InFrom) { return static_cast<ToT>(InFrom); }

}
