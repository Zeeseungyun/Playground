// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/Messages/Test2.h"
#include "ZeeNet/Public/Messages/Test.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest2() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTestTestMessage();
// End Cross Module References

// Begin ScriptStruct FZeeNetTest2TestMessage2
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2;
class UScriptStruct* FZeeNetTest2TestMessage2::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetTest2TestMessage2"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetTest2TestMessage2>()
{
	return FZeeNetTest2TestMessage2::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage2" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetTest2TestMessage2>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage2, msg), Z_Construct_UScriptStruct_FZeeNetTestTestMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg_MetaData), NewProp_msg_MetaData) }; // 317897572
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::NewProp_msg,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetTest2TestMessage2",
	Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::PropPointers),
	sizeof(FZeeNetTest2TestMessage2),
	alignof(FZeeNetTest2TestMessage2),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2.InnerSingleton;
}
// End ScriptStruct FZeeNetTest2TestMessage2

// Begin ScriptStruct FZeeNetTest2TestMessage3
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3;
class UScriptStruct* FZeeNetTest2TestMessage3::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetTest2TestMessage3"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetTest2TestMessage3>()
{
	return FZeeNetTest2TestMessage3::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg1_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage3" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg2_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage3" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg1;
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg2;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetTest2TestMessage3>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::NewProp_msg1 = { "msg1", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage3, msg1), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg1_MetaData), NewProp_msg1_MetaData) }; // 1497234574
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::NewProp_msg2 = { "msg2", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage3, msg2), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg2_MetaData), NewProp_msg2_MetaData) }; // 1497234574
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::NewProp_msg1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::NewProp_msg2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetTest2TestMessage3",
	Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::PropPointers),
	sizeof(FZeeNetTest2TestMessage3),
	alignof(FZeeNetTest2TestMessage3),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3.InnerSingleton;
}
// End ScriptStruct FZeeNetTest2TestMessage3

// Begin ScriptStruct FZeeNetTest2TestMessage4
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4;
class UScriptStruct* FZeeNetTest2TestMessage4::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetTest2TestMessage4"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetTest2TestMessage4>()
{
	return FZeeNetTest2TestMessage4::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg1_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage4" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg2_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage4" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg1;
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg2;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetTest2TestMessage4>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::NewProp_msg1 = { "msg1", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage4, msg1), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg1_MetaData), NewProp_msg1_MetaData) }; // 1497234574
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::NewProp_msg2 = { "msg2", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage4, msg2), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg2_MetaData), NewProp_msg2_MetaData) }; // 1401232259
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::NewProp_msg1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::NewProp_msg2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetTest2TestMessage4",
	Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::PropPointers),
	sizeof(FZeeNetTest2TestMessage4),
	alignof(FZeeNetTest2TestMessage4),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4.InnerSingleton;
}
// End ScriptStruct FZeeNetTest2TestMessage4

// Begin ScriptStruct FZeeNetTest2TestMessage5
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5;
class UScriptStruct* FZeeNetTest2TestMessage5::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetTest2TestMessage5"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetTest2TestMessage5>()
{
	return FZeeNetTest2TestMessage5::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg2_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage5" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_msg3_MetaData[] = {
		{ "Category", "ZeeNetTest2TestMessage5" },
		{ "ModuleRelativePath", "Public/Messages/Test2.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg2;
	static const UECodeGen_Private::FStructPropertyParams NewProp_msg3;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetTest2TestMessage5>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::NewProp_msg2 = { "msg2", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage5, msg2), Z_Construct_UScriptStruct_FZeeNetTestTestMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg2_MetaData), NewProp_msg2_MetaData) }; // 317897572
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::NewProp_msg3 = { "msg3", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetTest2TestMessage5, msg3), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_msg3_MetaData), NewProp_msg3_MetaData) }; // 1568233551
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::NewProp_msg2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::NewProp_msg3,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetTest2TestMessage5",
	Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::PropPointers),
	sizeof(FZeeNetTest2TestMessage5),
	alignof(FZeeNetTest2TestMessage5),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5.InnerSingleton;
}
// End ScriptStruct FZeeNetTest2TestMessage5

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test2_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeNetTest2TestMessage2::StaticStruct, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage2_Statics::NewStructOps, TEXT("ZeeNetTest2TestMessage2"), &Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage2, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetTest2TestMessage2), 1497234574U) },
		{ FZeeNetTest2TestMessage3::StaticStruct, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage3_Statics::NewStructOps, TEXT("ZeeNetTest2TestMessage3"), &Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage3, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetTest2TestMessage3), 1401232259U) },
		{ FZeeNetTest2TestMessage4::StaticStruct, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage4_Statics::NewStructOps, TEXT("ZeeNetTest2TestMessage4"), &Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage4, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetTest2TestMessage4), 1568233551U) },
		{ FZeeNetTest2TestMessage5::StaticStruct, Z_Construct_UScriptStruct_FZeeNetTest2TestMessage5_Statics::NewStructOps, TEXT("ZeeNetTest2TestMessage5"), &Z_Registration_Info_UScriptStruct_ZeeNetTest2TestMessage5, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetTest2TestMessage5), 3499432866U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test2_h_3797090558(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test2_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test2_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
