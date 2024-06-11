// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectPlayground/ProjectPlaygroundGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectPlaygroundGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PROJECTPLAYGROUND_API UClass* Z_Construct_UClass_AProjectPlaygroundGameMode();
PROJECTPLAYGROUND_API UClass* Z_Construct_UClass_AProjectPlaygroundGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectPlayground();
// End Cross Module References

// Begin Class AProjectPlaygroundGameMode
void AProjectPlaygroundGameMode::StaticRegisterNativesAProjectPlaygroundGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AProjectPlaygroundGameMode);
UClass* Z_Construct_UClass_AProjectPlaygroundGameMode_NoRegister()
{
	return AProjectPlaygroundGameMode::StaticClass();
}
struct Z_Construct_UClass_AProjectPlaygroundGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ProjectPlaygroundGameMode.h" },
		{ "ModuleRelativePath", "ProjectPlaygroundGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectPlaygroundGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AProjectPlaygroundGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectPlayground,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectPlaygroundGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AProjectPlaygroundGameMode_Statics::ClassParams = {
	&AProjectPlaygroundGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectPlaygroundGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AProjectPlaygroundGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AProjectPlaygroundGameMode()
{
	if (!Z_Registration_Info_UClass_AProjectPlaygroundGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProjectPlaygroundGameMode.OuterSingleton, Z_Construct_UClass_AProjectPlaygroundGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AProjectPlaygroundGameMode.OuterSingleton;
}
template<> PROJECTPLAYGROUND_API UClass* StaticClass<AProjectPlaygroundGameMode>()
{
	return AProjectPlaygroundGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectPlaygroundGameMode);
AProjectPlaygroundGameMode::~AProjectPlaygroundGameMode() {}
// End Class AProjectPlaygroundGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AProjectPlaygroundGameMode, AProjectPlaygroundGameMode::StaticClass, TEXT("AProjectPlaygroundGameMode"), &Z_Registration_Info_UClass_AProjectPlaygroundGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProjectPlaygroundGameMode), 3453506607U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_2208167888(TEXT("/Script/ProjectPlayground"),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
