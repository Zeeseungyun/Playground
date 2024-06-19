// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ZeeUIBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEEUI_ZeeUIBPLibrary_generated_h
#error "ZeeUIBPLibrary.generated.h already included, missing '#pragma once' in ZeeUIBPLibrary.h"
#endif
#define ZEEUI_ZeeUIBPLibrary_generated_h

#define FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_RPC_WRAPPERS \
	DECLARE_FUNCTION(execZeeUISampleFunction);


#define FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUZeeUIBPLibrary(); \
	friend struct Z_Construct_UClass_UZeeUIBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UZeeUIBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZeeUI"), NO_API) \
	DECLARE_SERIALIZER(UZeeUIBPLibrary)


#define FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UZeeUIBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UZeeUIBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZeeUIBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZeeUIBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UZeeUIBPLibrary(UZeeUIBPLibrary&&); \
	UZeeUIBPLibrary(const UZeeUIBPLibrary&); \
public: \
	NO_API virtual ~UZeeUIBPLibrary();


#define FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_25_PROLOG
#define FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_RPC_WRAPPERS \
	FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_INCLASS \
	FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEEUI_API UClass* StaticClass<class UZeeUIBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_ZeeUIBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
