// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Messages/Test.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEENET_Test_generated_h
#error "Test.generated.h already included, missing '#pragma once' in Test.h"
#endif
#define ZEENET_Test_generated_h

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetTestTestMessage_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetTestTestMessage>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h


#define FOREACH_ENUM_EZEENETTESTRETURNCODE(op) \
	op(EZeeNetTestReturnCode::RC_SUCCESSS) 

enum class EZeeNetTestReturnCode : uint8;
template<> struct TIsUEnumClass<EZeeNetTestReturnCode> { enum { Value = true }; };
template<> ZEENET_API UEnum* StaticEnum<EZeeNetTestReturnCode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
