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

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_27_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetAuthenticationLogin_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetAuthenticationLogin>();

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h_44_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetAuthenticationLogout_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetAuthenticationLogout>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Authentication_h


#define FOREACH_ENUM_EZEENETAUTHENTICATIONRETURNCODE(op) \
	op(EZeeNetAuthenticationReturnCode::RC_SUCCESS) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_UNKNOWN) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_LOGIN_DUPLICATED) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_LOGIN_WRONG_PASSWORD) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_LOGIN_WRONG_ID) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_LOGIN_CANT_CREATE_ACCOUNT) \
	op(EZeeNetAuthenticationReturnCode::RC_FAILED_DB_CONNECTION_ERROR) 

enum class EZeeNetAuthenticationReturnCode : uint8;
template<> struct TIsUEnumClass<EZeeNetAuthenticationReturnCode> { enum { Value = true }; };
template<> ZEENET_API UEnum* StaticEnum<EZeeNetAuthenticationReturnCode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
