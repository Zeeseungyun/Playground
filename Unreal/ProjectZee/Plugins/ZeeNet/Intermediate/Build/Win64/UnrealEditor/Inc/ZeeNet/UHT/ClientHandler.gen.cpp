// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/ClientHandler.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientHandler() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UClass* Z_Construct_UClass_UClientHandler();
ZEENET_API UClass* Z_Construct_UClass_UClientHandler_NoRegister();
// End Cross Module References

// Begin Class UClientHandler
void UClientHandler::StaticRegisterNativesUClientHandler()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UClientHandler);
UClass* Z_Construct_UClass_UClientHandler_NoRegister()
{
	return UClientHandler::StaticClass();
}
struct Z_Construct_UClass_UClientHandler_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ClientHandler.h" },
		{ "ModuleRelativePath", "Public/ClientHandler.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClientHandler>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UClientHandler_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClientHandler_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClientHandler_Statics::ClassParams = {
	&UClientHandler::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClientHandler_Statics::Class_MetaDataParams), Z_Construct_UClass_UClientHandler_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UClientHandler()
{
	if (!Z_Registration_Info_UClass_UClientHandler.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClientHandler.OuterSingleton, Z_Construct_UClass_UClientHandler_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClientHandler.OuterSingleton;
}
template<> ZEENET_API UClass* StaticClass<UClientHandler>()
{
	return UClientHandler::StaticClass();
}
UClientHandler::UClientHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UClientHandler);
UClientHandler::~UClientHandler() {}
// End Class UClientHandler

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UClientHandler, UClientHandler::StaticClass, TEXT("UClientHandler"), &Z_Registration_Info_UClass_UClientHandler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClientHandler), 3735571508U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_3692202404(TEXT("/Script/ZeeNet"),
	Z_CompiledInDeferFile_FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
