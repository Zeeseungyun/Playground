#pragma once
#include "CoreMinimal.h"

template<typename T>
concept TZeeIsEnum = std::is_enum_v<T>;

template<TZeeIsEnum EnumType>
FString ZeeEnumToString(EnumType EnumValue)
{
	if (UEnum* EnumPtr = StaticEnum<EnumType>())
	{
		return EnumPtr->GetNameStringByValue((int64)EnumValue);
	}
	return TEXT("");
}

template<TZeeIsEnum EnumType>
EnumType ZeeStringToEnum(const FString& Value)
{
	if (UEnum* EnumPtr = StaticEnum<EnumType>())
	{
		const int32 Index = EnumPtr->GetIndexByNameString(Value);
		return EnumType(Index);
	}

	return EnumType();
}
