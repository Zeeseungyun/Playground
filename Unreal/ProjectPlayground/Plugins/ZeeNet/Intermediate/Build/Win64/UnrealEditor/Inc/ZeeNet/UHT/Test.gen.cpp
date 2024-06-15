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
ZEENET_API UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTestMessage();
// End Cross Module References

// Begin Enum EZeeNetReturnCode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EZeeNetReturnCode;
static UEnum* EZeeNetReturnCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EZeeNetReturnCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EZeeNetReturnCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("EZeeNetReturnCode"));
	}
	return Z_Registration_Info_UEnum_EZeeNetReturnCode.OuterSingleton;
}
template<> ZEENET_API UEnum* StaticEnum<EZeeNetReturnCode>()
{
	return EZeeNetReturnCode_StaticEnum();
}
struct Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
		{ "RC_SUCCESSS.Name", "EZeeNetReturnCode::RC_SUCCESSS" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EZeeNetReturnCode::RC_SUCCESSS", (int64)EZeeNetReturnCode::RC_SUCCESSS },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	"EZeeNetReturnCode",
	"EZeeNetReturnCode",
	Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode()
{
	if (!Z_Registration_Info_UEnum_EZeeNetReturnCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EZeeNetReturnCode.InnerSingleton, Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EZeeNetReturnCode.InnerSingleton;
}
// End Enum EZeeNetReturnCode

// Begin ScriptStruct FZeeNetTestMessage
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetTestMessage;
class UScriptStruct* FZeeNetTestMessage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTestMessage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetTestMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetTestMessage, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetTestMessage"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTestMessage.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetTestMessage>()
{
	return FZeeNetTestMessage::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RC_MetaData[] = {
		{ "Category", "ZeeNetTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RCLists_MetaData[] = {
		{ "Category", "ZeeNetTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "ZeeNetTestMessage" },
		{ "ModuleRelativePath", "Public/Messages/Test.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "Category", "ZeeNetTestMessage" },
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
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetTestMessage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RC_Inner = { "RC", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RC = { "RC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestMessage, RC), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RC_MetaData), NewProp_RC_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RCLists_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RCLists_Inner = { "RCLists", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ZeeNet_EZeeNetReturnCode, METADATA_PARAMS(0, nullptr) }; // 178221107
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RCLists = { "RCLists", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestMessage, RCLists), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RCLists_MetaData), NewProp_RCLists_MetaData) }; // 178221107
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestMessage, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTestMessage, Content), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RC_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RCLists_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RCLists_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_RCLists,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewProp_Content,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetTestMessage",
	Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::PropPointers),
	sizeof(FZeeNetTestMessage),
	alignof(FZeeNetTestMessage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTestMessage()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTestMessage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetTestMessage.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTestMessage.InnerSingleton;
}
// End ScriptStruct FZeeNetTestMessage

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EZeeNetReturnCode_StaticEnum, TEXT("EZeeNetReturnCode"), &Z_Registration_Info_UEnum_EZeeNetReturnCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 178221107U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeNetTestMessage::StaticStruct, Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics::NewStructOps, TEXT("ZeeNetTestMessage"), &Z_Registration_Info_UScriptStruct_ZeeNetTestMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetTestMessage), 1049621564U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_1336893510(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
