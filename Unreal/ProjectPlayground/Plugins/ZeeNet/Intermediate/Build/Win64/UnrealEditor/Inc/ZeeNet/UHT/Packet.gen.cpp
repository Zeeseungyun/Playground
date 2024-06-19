// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/Messages/Packet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePacket() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetPacketType();
ZEENET_API UScriptStruct* Z_Construct_UScriptStruct_FZeeNetPacketHeader();
// End Cross Module References

// Begin Enum EZeeNetPacketType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EZeeNetPacketType;
static UEnum* EZeeNetPacketType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EZeeNetPacketType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EZeeNetPacketType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ZeeNet_EZeeNetPacketType, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("EZeeNetPacketType"));
	}
	return Z_Registration_Info_UEnum_EZeeNetPacketType.OuterSingleton;
}
template<> ZEENET_API UEnum* StaticEnum<EZeeNetPacketType>()
{
	return EZeeNetPacketType_StaticEnum();
}
struct Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Packet.h" },
		{ "None.Name", "EZeeNetPacketType::None" },
		{ "NoResponse.Name", "EZeeNetPacketType::NoResponse" },
		{ "Notify.Name", "EZeeNetPacketType::Notify" },
		{ "Request.Name", "EZeeNetPacketType::Request" },
		{ "Response.Name", "EZeeNetPacketType::Response" },
		{ "ResponseTimeout.Name", "EZeeNetPacketType::ResponseTimeout" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EZeeNetPacketType::None", (int64)EZeeNetPacketType::None },
		{ "EZeeNetPacketType::Notify", (int64)EZeeNetPacketType::Notify },
		{ "EZeeNetPacketType::Request", (int64)EZeeNetPacketType::Request },
		{ "EZeeNetPacketType::Response", (int64)EZeeNetPacketType::Response },
		{ "EZeeNetPacketType::NoResponse", (int64)EZeeNetPacketType::NoResponse },
		{ "EZeeNetPacketType::ResponseTimeout", (int64)EZeeNetPacketType::ResponseTimeout },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	"EZeeNetPacketType",
	"EZeeNetPacketType",
	Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ZeeNet_EZeeNetPacketType()
{
	if (!Z_Registration_Info_UEnum_EZeeNetPacketType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EZeeNetPacketType.InnerSingleton, Z_Construct_UEnum_ZeeNet_EZeeNetPacketType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EZeeNetPacketType.InnerSingleton;
}
// End Enum EZeeNetPacketType

// Begin ScriptStruct FZeeNetPacketHeader
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader;
class UScriptStruct* FZeeNetPacketHeader::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeNetPacketHeader, (UObject*)Z_Construct_UPackage__Script_ZeeNet(), TEXT("ZeeNetPacketHeader"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader.OuterSingleton;
}
template<> ZEENET_API UScriptStruct* StaticStruct<FZeeNetPacketHeader>()
{
	return FZeeNetPacketHeader::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Messages/Packet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PacketSize_MetaData[] = {
		{ "Category", "ZeeNetPacketHeader" },
		{ "ModuleRelativePath", "Public/Messages/Packet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Point_MetaData[] = {
		{ "Category", "ZeeNetPacketHeader" },
		{ "ModuleRelativePath", "Public/Messages/Packet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sequence_MetaData[] = {
		{ "Category", "ZeeNetPacketHeader" },
		{ "ModuleRelativePath", "Public/Messages/Packet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PacketType_MetaData[] = {
		{ "Category", "ZeeNetPacketHeader" },
		{ "ModuleRelativePath", "Public/Messages/Packet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_PacketSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Point;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PacketType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PacketType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeNetPacketHeader>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_PacketSize = { "PacketSize", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetPacketHeader, PacketSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PacketSize_MetaData), NewProp_PacketSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetPacketHeader, Point), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Point_MetaData), NewProp_Point_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetPacketHeader, Sequence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sequence_MetaData), NewProp_Sequence_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_PacketType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_PacketType = { "PacketType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeNetPacketHeader, PacketType), Z_Construct_UEnum_ZeeNet_EZeeNetPacketType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PacketType_MetaData), NewProp_PacketType_MetaData) }; // 659019632
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_PacketSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_Point,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_PacketType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewProp_PacketType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
	nullptr,
	&NewStructOps,
	"ZeeNetPacketHeader",
	Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::PropPointers),
	sizeof(FZeeNetPacketHeader),
	alignof(FZeeNetPacketHeader),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeNetPacketHeader()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader.InnerSingleton, Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader.InnerSingleton;
}
// End ScriptStruct FZeeNetPacketHeader

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EZeeNetPacketType_StaticEnum, TEXT("EZeeNetPacketType"), &Z_Registration_Info_UEnum_EZeeNetPacketType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 659019632U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeNetPacketHeader::StaticStruct, Z_Construct_UScriptStruct_FZeeNetPacketHeader_Statics::NewStructOps, TEXT("ZeeNetPacketHeader"), &Z_Registration_Info_UScriptStruct_ZeeNetPacketHeader, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeNetPacketHeader), 213440825U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_32066798(TEXT("/Script/ZeeNet"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_Messages_Packet_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
