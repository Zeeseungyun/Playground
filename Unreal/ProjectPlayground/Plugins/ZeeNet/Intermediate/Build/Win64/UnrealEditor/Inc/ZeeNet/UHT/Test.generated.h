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
	friend struct Z_Construct_UScriptStruct_FZeeNetTestMessage_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetTestMessage>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Test_h


#define FOREACH_ENUM_EZEENETRETURNCODE(op) \
	op(EZeeNetReturnCode::RC_SUCCESSS) 

enum class EZeeNetReturnCode : uint8;
template<> struct TIsUEnumClass<EZeeNetReturnCode> { enum { Value = true }; };
template<> ZEENET_API UEnum* StaticEnum<EZeeNetReturnCode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
