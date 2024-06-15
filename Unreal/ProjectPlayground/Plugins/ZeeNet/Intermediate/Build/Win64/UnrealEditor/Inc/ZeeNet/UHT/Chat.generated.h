// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Messages/Chat.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEENET_Chat_generated_h
#error "Chat.generated.h already included, missing '#pragma once' in Chat.h"
#endif
#define ZEENET_Chat_generated_h

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetChatSpeak_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetChatSpeak>();

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h_43_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetChatSpeak1_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetChatSpeak1>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Chat_h


#define FOREACH_ENUM_EZEENETCHATRETURNCODE(op) \
	op(EZeeNetChatReturnCode::RC_SUCCESSS) 

enum class EZeeNetChatReturnCode : uint8;
template<> struct TIsUEnumClass<EZeeNetChatReturnCode> { enum { Value = true }; };
template<> ZEENET_API UEnum* StaticEnum<EZeeNetChatReturnCode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
