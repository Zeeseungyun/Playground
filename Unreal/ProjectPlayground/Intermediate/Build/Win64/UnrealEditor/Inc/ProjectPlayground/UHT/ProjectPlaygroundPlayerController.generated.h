// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectPlaygroundPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTPLAYGROUND_ProjectPlaygroundPlayerController_generated_h
#error "ProjectPlaygroundPlayerController.generated.h already included, missing '#pragma once' in ProjectPlaygroundPlayerController.h"
#endif
#define PROJECTPLAYGROUND_ProjectPlaygroundPlayerController_generated_h

#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectPlaygroundPlayerController(); \
	friend struct Z_Construct_UClass_AProjectPlaygroundPlayerController_Statics; \
public: \
	DECLARE_CLASS(AProjectPlaygroundPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectPlayground"), NO_API) \
	DECLARE_SERIALIZER(AProjectPlaygroundPlayerController)


#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AProjectPlaygroundPlayerController(AProjectPlaygroundPlayerController&&); \
	AProjectPlaygroundPlayerController(const AProjectPlaygroundPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectPlaygroundPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectPlaygroundPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectPlaygroundPlayerController) \
	NO_API virtual ~AProjectPlaygroundPlayerController();


#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h_17_PROLOG
#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h_20_INCLASS_NO_PURE_DECLS \
	FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTPLAYGROUND_API UClass* StaticClass<class AProjectPlaygroundPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
