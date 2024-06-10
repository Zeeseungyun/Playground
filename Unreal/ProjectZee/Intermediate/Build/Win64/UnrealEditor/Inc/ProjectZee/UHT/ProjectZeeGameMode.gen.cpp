// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectZee/ProjectZeeGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectZeeGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PROJECTZEE_API UClass* Z_Construct_UClass_AProjectZeeGameMode();
PROJECTZEE_API UClass* Z_Construct_UClass_AProjectZeeGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectZee();
// End Cross Module References

// Begin Class AProjectZeeGameMode
void AProjectZeeGameMode::StaticRegisterNativesAProjectZeeGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AProjectZeeGameMode);
UClass* Z_Construct_UClass_AProjectZeeGameMode_NoRegister()
{
	return AProjectZeeGameMode::StaticClass();
}
struct Z_Construct_UClass_AProjectZeeGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ProjectZeeGameMode.h" },
		{ "ModuleRelativePath", "ProjectZeeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectZeeGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AProjectZeeGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectZee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectZeeGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AProjectZeeGameMode_Statics::ClassParams = {
	&AProjectZeeGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectZeeGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AProjectZeeGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AProjectZeeGameMode()
{
	if (!Z_Registration_Info_UClass_AProjectZeeGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProjectZeeGameMode.OuterSingleton, Z_Construct_UClass_AProjectZeeGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AProjectZeeGameMode.OuterSingleton;
}
template<> PROJECTZEE_API UClass* StaticClass<AProjectZeeGameMode>()
{
	return AProjectZeeGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectZeeGameMode);
AProjectZeeGameMode::~AProjectZeeGameMode() {}
// End Class AProjectZeeGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectZee_Source_ProjectZee_ProjectZeeGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AProjectZeeGameMode, AProjectZeeGameMode::StaticClass, TEXT("AProjectZeeGameMode"), &Z_Registration_Info_UClass_AProjectZeeGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProjectZeeGameMode), 2598980562U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectZee_Source_ProjectZee_ProjectZeeGameMode_h_1817785516(TEXT("/Script/ProjectZee"),
	Z_CompiledInDeferFile_FID_ProjectZee_Source_ProjectZee_ProjectZeeGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectZee_Source_ProjectZee_ProjectZeeGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
