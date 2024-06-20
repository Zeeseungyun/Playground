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
ZEENET_API UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout();
// End Cross Module References

// Begin Enum EZeeNetAuthenticationReturnCode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode;
static UEnum* EZeeNetAuthenticationReturnCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("EZeeNetAuthenticationReturnCode"));
	}
	return Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode.OuterSingleton;
}
template<> ZEENET_API UEnum* StaticEnum<EZeeNetAuthenticationReturnCode>()
{
	return EZeeNetAuthenticationReturnCode_StaticEnum();
}
struct Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
		{ "RC_FAILED_ALREADY_LOGIN.Name", "EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGIN" },
		{ "RC_FAILED_ALREADY_LOGOUT.Name", "EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGOUT" },
		{ "RC_SUCCESSS.Name", "EZeeNetAuthenticationReturnCode::RC_SUCCESSS" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EZeeNetAuthenticationReturnCode::RC_SUCCESSS", (int64)EZeeNetAuthenticationReturnCode::RC_SUCCESSS },
		{ "EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGIN", (int64)EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGIN },
		{ "EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGOUT", (int64)EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGOUT },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	"EZeeNetAuthenticationReturnCode",
	"EZeeNetAuthenticationReturnCode",
	Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode()
{
	if (!Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode.InnerSingleton, Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode.InnerSingleton;
}
// End Enum EZeeNetAuthenticationReturnCode

// Begin ScriptStruct FZeeNetAuthenticationLogin
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin;
class UScriptStruct* FZeeNetAuthenticationLogin::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetAuthenticationLogin"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetAuthenticationLogin>()
{
	return FZeeNetAuthenticationLogin::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RC_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogin" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogin" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogin" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UID_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogin" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RC_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RC;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetAuthenticationLogin>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_RC_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_RC = { "RC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogin, RC), Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RC_MetaData), NewProp_RC_MetaData) }; // 1389182516
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogin, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogin, Password), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Password_MetaData), NewProp_Password_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_UID = { "UID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogin, UID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UID_MetaData), NewProp_UID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_RC_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_RC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_Password,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewProp_UID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetAuthenticationLogin",
	Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::PropPointers),
	sizeof(FZeeNetAuthenticationLogin),
	alignof(FZeeNetAuthenticationLogin),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin.InnerSingleton;
}
// End ScriptStruct FZeeNetAuthenticationLogin

// Begin ScriptStruct FZeeNetAuthenticationLogout
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout;
class UScriptStruct* FZeeNetAuthenticationLogout::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetAuthenticationLogout"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetAuthenticationLogout>()
{
	return FZeeNetAuthenticationLogout::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RC_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogout" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogout" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UID_MetaData[] = {
		{ "Category", "ZeeNetAuthenticationLogout" },
		{ "ModuleRelativePath", "Public/Messages/Authentication.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RC_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RC;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetAuthenticationLogout>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_RC_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_RC = { "RC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogout, RC), Z_Construct_UEnum_ZeeNet_EZeeNetAuthenticationReturnCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RC_MetaData), NewProp_RC_MetaData) }; // 1389182516
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogout, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_UID = { "UID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetAuthenticationLogout, UID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UID_MetaData), NewProp_UID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_RC_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_RC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewProp_UID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetAuthenticationLogout",
	Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::PropPointers),
	sizeof(FZeeNetAuthenticationLogout),
	alignof(FZeeNetAuthenticationLogout),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout.InnerSingleton;
}
// End ScriptStruct FZeeNetAuthenticationLogout

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EZeeNetAuthenticationReturnCode_StaticEnum, TEXT("EZeeNetAuthenticationReturnCode"), &Z_Registration_Info_UEnum_EZeeNetAuthenticationReturnCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1389182516U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeNetAuthenticationLogin::StaticStruct, Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics::NewStructOps, TEXT("ZeeNetAuthenticationLogin"), &Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogin, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetAuthenticationLogin), 2742683496U) },
		{ FZeeNetAuthenticationLogout::StaticStruct, Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics::NewStructOps, TEXT("ZeeNetAuthenticationLogout"), &Z_Registration_Info_UScriptStruct_ZeeNetAuthenticationLogout, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetAuthenticationLogout), 448704838U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_2575780312(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
