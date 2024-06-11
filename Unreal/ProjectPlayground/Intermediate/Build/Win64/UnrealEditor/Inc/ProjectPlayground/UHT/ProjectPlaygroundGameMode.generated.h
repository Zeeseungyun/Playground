// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectPlaygroundGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTPLAYGROUND_ProjectPlaygroundGameMode_generated_h
#error "ProjectPlaygroundGameMode.generated.h already included, missing '#pragma once' in ProjectPlaygroundGameMode.h"
#endif
#define PROJECTPLAYGROUND_ProjectPlaygroundGameMode_generated_h

#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectPlaygroundGameMode(); \
	friend struct Z_Construct_UClass_AProjectPlaygroundGameMode_Statics; \
public: \
	DECLARE_CLASS(AProjectPlaygroundGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectPlayground"), PROJECTPLAYGROUND_API) \
	DECLARE_SERIALIZER(AProjectPlaygroundGameMode)


#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AProjectPlaygroundGameMode(AProjectPlaygroundGameMode&&); \
	AProjectPlaygroundGameMode(const AProjectPlaygroundGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PROJECTPLAYGROUND_API, AProjectPlaygroundGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectPlaygroundGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectPlaygroundGameMode) \
	PROJECTPLAYGROUND_API virtual ~AProjectPlaygroundGameMode();


#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_9_PROLOG
#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTPLAYGROUND_API UClass* StaticClass<class AProjectPlaygroundGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
