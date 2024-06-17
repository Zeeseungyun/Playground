// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/Messages/Test.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTestTestMessage();
// End Cross Module References

// Begin Enum EZeeNetTestReturnCode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EZeeNetTestReturnCode;
static UEnum* EZeeNetTestReturnCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EZeeNetTestReturnCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EZeeNetTestReturnCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("EZeeNetTestReturnCode"));
	}
	return Z_Registration_Info_UEnum_EZeeNetTestReturnCode.OuterSingleton;
}
template<> ZEENET_API UEnum* StaticEnum<EZeeNetTestReturnCode>()
{
	return EZeeNetTestReturnCode_StaticEnum();
}
struct Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
		{ "RC_SUCCESSS.Name", "EZeeNetTestReturnCode::RC_SUCCESSS" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EZeeNetTestReturnCode::RC_SUCCESSS", (int64)EZeeNetTestReturnCode::RC_SUCCESSS },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	"EZeeNetTestReturnCode",
	"EZeeNetTestReturnCode",
	Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode()
{
	if (!Z_Registration_Info_UEnum_EZeeNetTestReturnCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EZeeNetTestReturnCode.InnerSingleton, Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EZeeNetTestReturnCode.InnerSingleton;
}
// End Enum EZeeNetTestReturnCode

// Begin ScriptStruct FZeeNetTestTestMessage
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage;
class UScriptStruct* FZeeNetTestTestMessage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetTestTestMessage, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetTestTestMessage"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetTestTestMessage>()
{
	return FZeeNetTestTestMessage::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RC_MetaData[] = {
		{ "Category", "ZeeNetTestTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RCLists_MetaData[] = {
		{ "Category", "ZeeNetTestTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "ZeeNetTestTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "Category", "ZeeNetTestTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RC_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RC;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RCLists_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RCLists_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RCLists;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Content;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetTestTestMessage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RC_Inner = { "RC", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RC = { "RC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestTestMessage, RC), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RC_MetaData), NewProp_RC_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RCLists_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RCLists_Inner = { "RCLists", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ZeeNet_EZeeNetTestReturnCode, METADATA_PARAMS(0, nullptr) }; // 178184894
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RCLists = { "RCLists", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestTestMessage, RCLists), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RCLists_MetaData), NewProp_RCLists_MetaData) }; // 178184894
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestTestMessage, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestTestMessage, Content), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RC_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RCLists_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RCLists_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_RCLists,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewProp_Content,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetTestTestMessage",
	Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::PropPointers),
	sizeof(FZeeNetTestTestMessage),
	alignof(FZeeNetTestTestMessage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTestTestMessage()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage.InnerSingleton;
}
// End ScriptStruct FZeeNetTestTestMessage

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EZeeNetTestReturnCode_StaticEnum, TEXT("EZeeNetTestReturnCode"), &Z_Registration_Info_UEnum_EZeeNetTestReturnCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 178184894U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeNetTestTestMessage::StaticStruct, Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics::NewStructOps, TEXT("ZeeNetTestTestMessage"), &Z_Registration_Info_UScriptStruct_ZeeNetTestTestMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetTestTestMessage), 317897572U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_2601496377(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
