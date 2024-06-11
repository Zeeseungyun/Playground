// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectPlaygroundCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTPLAYGROUND_ProjectPlaygroundCharacter_generated_h
#error "ProjectPlaygroundCharacter.generated.h already included, missing '#pragma once' in ProjectPlaygroundCharacter.h"
#endif
#define PROJECTPLAYGROUND_ProjectPlaygroundCharacter_generated_h

#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectPlaygroundCharacter(); \
	friend struct Z_Construct_UClass_AProjectPlaygroundCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectPlaygroundCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectPlayground"), NO_API) \
	DECLARE_SERIALIZER(AProjectPlaygroundCharacter)


#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AProjectPlaygroundCharacter(AProjectPlaygroundCharacter&&); \
	AProjectPlaygroundCharacter(const AProjectPlaygroundCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectPlaygroundCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectPlaygroundCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectPlaygroundCharacter) \
	NO_API virtual ~AProjectPlaygroundCharacter();


#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h_9_PROLOG
#define FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTPLAYGROUND_API UClass* StaticClass<class AProjectPlaygroundCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Source_ProjectPlayground_ProjectPlaygroundCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
