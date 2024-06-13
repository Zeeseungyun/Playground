// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/Messages/Authentication.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAuthentication() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FTempStruct();
// End Cross Module References

// Begin ScriptStruct FTempStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TempStruct;
class UScriptStruct* FTempStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TempStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TempStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTempStruct, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("TempStruct"));
	}
	return Z_Registration_Info_UScriptStruct_TempStruct.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FTempStruct>()
{
	return FTempStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FTempStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTempStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FTempStruct_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTempStruct, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTempStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTempStruct_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTempStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTempStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"TempStruct",
	Z_Construct_UScriptStruct_FTempStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTempStruct_Statics::PropPointers),
	sizeof(FTempStruct),
	alignof(FTempStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTempStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTempStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FTempStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TempStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TempStruct.InnerSingleton, Z_Construct_UScriptStruct_FTempStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_TempStruct.InnerSingleton;
}
// End ScriptStruct FTempStruct

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FTempStruct::StaticStruct, Z_Construct_UScriptStruct_FTempStruct_Statics::NewStructOps, TEXT("TempStruct"), &Z_Registration_Info_UScriptStruct_TempStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTempStruct), 2663956678U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_2549753614(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
