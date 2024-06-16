// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Messages/Packet.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZEENET_Packet_generated_h
#error "Packet.generated.h already included, missing '#pragma once' in Packet.h"
#endif
#define ZEENET_Packet_generated_h

#define FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_21_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics; \
	ZEENET_API static class UScriptStruct* StaticStruct();


template<> ZEENET_API UScriptStruct* StaticStruct<struct FZeeNetPacketHeader>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h


#define FOREACH_ENUM_EZEENETPACKETTYPE(op) \
	op(EZeeNetPacketType::None) \
	op(EZeeNetPacketType::Notify) \
	op(EZeeNetPacketType::Response) \
	op(EZeeNetPacketType::Request) 

enum class EZeeNetPacketType : uint8;
template<> struct TIsUEnumClass<EZeeNetPacketType> { enum { Value = true }; };
template<> ZEENET_API UEnum* StaticEnum<EZeeNetPacketType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
