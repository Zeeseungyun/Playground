#pragma once
#include "CoreMinimal.h"

template<typename T>
concept TPPIsEnum = std::is_enum_v<T>;

template<TPPIsEnum EnumType>
FString ZeeEnumToString(EnumType EnumValue)
{
	if (UEnum* EnumPtr = StaticEnum<EnumType>())
	{
		return EnumPtr->GetNameStringByValue((int64)EnumValue);
	}
	return TEXT("");
}

template<TPPIsEnum EnumType>
EnumType ZeeStringToEnum(const FString& Value)
{
	if (UEnum* EnumPtr = StaticEnum<EnumType>())
	{
		const int32 Index = EnumPtr->GetIndexByNameString(Value);
		return EnumType(Index);
	}

	return EnumType();
}
