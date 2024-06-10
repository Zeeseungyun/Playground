// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ClientHandler.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEENET_ClientHandler_generated_h
#error "ClientHandler.generated.h already included, missing '#pragma once' in ClientHandler.h"
#endif
#define ZEENET_ClientHandler_generated_h

#define FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUClientHandler(); \
	friend struct Z_Construct_UClass_UClientHandler_Statics; \
public: \
	DECLARE_CLASS(UClientHandler, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZeeNet"), NO_API) \
	DECLARE_SERIALIZER(UClientHandler)


#define FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UClientHandler(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UClientHandler(UClientHandler&&); \
	UClientHandler(const UClientHandler&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClientHandler); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClientHandler); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UClientHandler) \
	NO_API virtual ~UClientHandler();


#define FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_12_PROLOG
#define FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_15_INCLASS_NO_PURE_DECLS \
	FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZEENET_API UClass* StaticClass<class UClientHandler>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectZee_Plugins_ZeeNet_Source_ZeeNet_Public_ClientHandler_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
