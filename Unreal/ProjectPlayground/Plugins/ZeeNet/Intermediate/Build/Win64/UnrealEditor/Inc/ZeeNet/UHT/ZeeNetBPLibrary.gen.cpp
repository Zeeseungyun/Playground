// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeNet/Public/ZeeNetBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZeeNetBPLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_ZeeNet();
ZEENET_API UClass* Z_Construct_UClass_UZeeNetBPLibrary();
ZEENET_API UClass* Z_Construct_UClass_UZeeNetBPLibrary_NoRegister();
// End Cross Module References

// Begin Class UZeeNetBPLibrary Function ZeeNetSampleFunction
struct Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics
{
	struct ZeeNetBPLibrary_eventZeeNetSampleFunction_Parms
	{
		float Param;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ZeeNetTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "ZeeNet sample test testing" },
		{ "ModuleRelativePath", "Public/ZeeNetBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Param;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZeeNetBPLibrary_eventZeeNetSampleFunction_Parms, Param), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZeeNetBPLibrary_eventZeeNetSampleFunction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::NewProp_Param,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZeeNetBPLibrary, nullptr, "ZeeNetSampleFunction", nullptr, nullptr, Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::ZeeNetBPLibrary_eventZeeNetSampleFunction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::ZeeNetBPLibrary_eventZeeNetSampleFunction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZeeNetBPLibrary::execZeeNetSampleFunction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Param);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UZeeNetBPLibrary::ZeeNetSampleFunction(Z_Param_Param);
	P_NATIVE_END;
}
// End Class UZeeNetBPLibrary Function ZeeNetSampleFunction

// Begin Class UZeeNetBPLibrary
void UZeeNetBPLibrary::StaticRegisterNativesUZeeNetBPLibrary()
{
	UClass* Class = UZeeNetBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ZeeNetSampleFunction", &UZeeNetBPLibrary::execZeeNetSampleFunction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZeeNetBPLibrary);
UClass* Z_Construct_UClass_UZeeNetBPLibrary_NoRegister()
{
	return UZeeNetBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UZeeNetBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
#endif
		{ "IncludePath", "ZeeNetBPLibrary.h" },
		{ "ModuleRelativePath", "Public/ZeeNetBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UZeeNetBPLibrary_ZeeNetSampleFunction, "ZeeNetSampleFunction" }, // 557832781
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZeeNetBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UZeeNetBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeNet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZeeNetBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UZeeNetBPLibrary_Statics::ClassParams = {
	&UZeeNetBPLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZeeNetBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UZeeNetBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UZeeNetBPLibrary()
{
	if (!Z_Registration_Info_UClass_UZeeNetBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZeeNetBPLibrary.OuterSingleton, Z_Construct_UClass_UZeeNetBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZeeNetBPLibrary.OuterSingleton;
}
template<> ZEENET_API UClass* StaticClass<UZeeNetBPLibrary>()
{
	return UZeeNetBPLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UZeeNetBPLibrary);
UZeeNetBPLibrary::~UZeeNetBPLibrary() {}
// End Class UZeeNetBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZeeNetBPLibrary, UZeeNetBPLibrary::StaticClass, TEXT("UZeeNetBPLibrary"), &Z_Registration_Info_UClass_UZeeNetBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZeeNetBPLibrary), 4241079356U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_338442490(TEXT("/Script/ZeeNet"),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeNet_Source_ZeeNet_Public_ZeeNetBPLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
