// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Messages/Authentication.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEENET_Authentication_generated_h
#error "Authentication.generated.h already included, missing '#pragma once' in Authentication.h"
#endif
#define ZEENET_Authentication_generated_h

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetAuthenticationLogin>();

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_41_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetAuthenticationLogout>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h


#define FOREACH_ENUM_EZEENETAUTHENTICATIONRETURNCODE(op) \
	op(EZeeNetAuthenticationReturnCode::RC_SUCCESSS) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGIN) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_ALREADY_LOGOUT) 

enum class EZeeNetAuthenticationReturnCode : uint8;
template<> struct TIsUEnumClass<EZeeNetAuthenticationReturnCode> { enum { Value = true }; };
template<> ZEENET_API UEnum* StaticEnum<EZeeNetAuthenticationReturnCode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
