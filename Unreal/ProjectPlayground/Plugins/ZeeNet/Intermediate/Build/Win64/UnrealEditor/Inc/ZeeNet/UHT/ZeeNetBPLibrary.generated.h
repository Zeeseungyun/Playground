// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ZeeNetBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEENET_ZeeNetBPLibrary_generated_h
#error "ZeeNetBPLibrary.generated.h already included, missing '#pragma once' in ZeeNetBPLibrary.h"
#endif
#define ZEENET_ZeeNetBPLibrary_generated_h

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_RPC_WRAPPERS \
	DECLARE_FUNCTION(execZeeNetSampleFunction);


#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUZeeNetBPLibrary(); \
	friend struct Z_Construct_UClass_UZeeNetBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UZeeNetBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZeeNet"), NO_API) \
	DECLARE_SERIALIZER(UZeeNetBPLibrary)


#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UZeeNetBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UZeeNetBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZeeNetBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZeeNetBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UZeeNetBPLibrary(UZeeNetBPLibrary&&); \
	UZeeNetBPLibrary(const UZeeNetBPLibrary&); \
public: \
	NO_API virtual ~UZeeNetBPLibrary();


#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_25_PROLOG
#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_RPC_WRAPPERS \
	FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_INCLASS \
	FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEENET_API UClass* StaticClass<class UZeeNetBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
