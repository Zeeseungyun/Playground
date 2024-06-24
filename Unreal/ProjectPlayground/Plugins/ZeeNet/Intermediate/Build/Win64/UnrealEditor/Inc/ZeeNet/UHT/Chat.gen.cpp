// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/Messages/Chat.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChat() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetChatSpeak();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetChatSpeak1();
// End Cross Module References

// Begin Enum EZeeNetChatReturnCode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EZeeNetChatReturnCode;
static UEnum* EZeeNetChatReturnCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EZeeNetChatReturnCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EZeeNetChatReturnCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("EZeeNetChatReturnCode"));
	}
	return Z_Registration_Info_UEnum_EZeeNetChatReturnCode.OuterSingleton;
}
template<> ZEENET_API UEnum* StaticEnum<EZeeNetChatReturnCode>()
{
	return EZeeNetChatReturnCode_StaticEnum();
}
struct Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
		{ "RC_SUCCESSS.Name", "EZeeNetChatReturnCode::RC_SUCCESSS" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EZeeNetChatReturnCode::RC_SUCCESSS", (int64)EZeeNetChatReturnCode::RC_SUCCESSS },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	"EZeeNetChatReturnCode",
	"EZeeNetChatReturnCode",
	Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode()
{
	if (!Z_Registration_Info_UEnum_EZeeNetChatReturnCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EZeeNetChatReturnCode.InnerSingleton, Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EZeeNetChatReturnCode.InnerSingleton;
}
// End Enum EZeeNetChatReturnCode

// Begin ScriptStruct FZeeNetChatSpeak
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak;
class UScriptStruct* FZeeNetChatSpeak::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetChatSpeak, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetChatSpeak"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetChatSpeak>()
{
	return FZeeNetChatSpeak::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RC_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UID_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Contents_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RC_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RC;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Content;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Contents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Contents;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetChatSpeak>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_RC_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_RC = { "RC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak, RC), Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RC_MetaData), NewProp_RC_MetaData) }; // 2668431788
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_UID = { "UID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak, UID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UID_MetaData), NewProp_UID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak, Content), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Contents_Inner = { "Contents", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Contents = { "Contents", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak, Contents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Contents_MetaData), NewProp_Contents_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_RC_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_RC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_UID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Contents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewProp_Contents,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetChatSpeak",
	Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::PropPointers),
	sizeof(FZeeNetChatSpeak),
	alignof(FZeeNetChatSpeak),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetChatSpeak()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak.InnerSingleton;
}
// End ScriptStruct FZeeNetChatSpeak

// Begin ScriptStruct FZeeNetChatSpeak1
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1;
class UScriptStruct* FZeeNetChatSpeak1::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetChatSpeak1, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetChatSpeak1"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetChatSpeak1>()
{
	return FZeeNetChatSpeak1::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RC_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak1" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UID_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak1" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak1" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak1" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speak12_MetaData[] = {
		{ "Category", "ZeeNetChatSpeak1" },
		{ "ModuleRelativePath", "Public/Messages/Chat.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RC_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RC;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Content;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Speak12;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetChatSpeak1>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_RC_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_RC = { "RC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak1, RC), Z_Construct_UEnum_ZeeNet_EZeeNetChatReturnCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RC_MetaData), NewProp_RC_MetaData) }; // 2668431788
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_UID = { "UID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak1, UID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UID_MetaData), NewProp_UID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak1, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak1, Content), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_Speak12 = { "Speak12", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetChatSpeak1, Speak12), Z_Construct_UScriptStruct_FZeeNetChatSpeak, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speak12_MetaData), NewProp_Speak12_MetaData) }; // 4037896284
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_RC_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_RC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_UID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewProp_Speak12,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetChatSpeak1",
	Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::PropPointers),
	sizeof(FZeeNetChatSpeak1),
	alignof(FZeeNetChatSpeak1),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetChatSpeak1()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1.InnerSingleton;
}
// End ScriptStruct FZeeNetChatSpeak1

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EZeeNetChatReturnCode_StaticEnum, TEXT("EZeeNetChatReturnCode"), &Z_Registration_Info_UEnum_EZeeNetChatReturnCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2668431788U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeNetChatSpeak::StaticStruct, Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics::NewStructOps, TEXT("ZeeNetChatSpeak"), &Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetChatSpeak), 4037896284U) },
		{ FZeeNetChatSpeak1::StaticStruct, Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics::NewStructOps, TEXT("ZeeNetChatSpeak1"), &Z_Registration_Info_UScriptStruct_ZeeNetChatSpeak1, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetChatSpeak1), 1902014750U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_1715026165(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
