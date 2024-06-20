// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZeeUI/Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZeeUILobbySlateStyle() {}

// Begin Cross Module References
SLATECORE_API UClass* Z_Construct_UClass_USlateWidgetStyleContainerBase();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FButtonStyle();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FEditableTextBoxStyle();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateWidgetStyle();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FTextBlockStyle();
UPackage* Z_Construct_UPackage__Script_ZeeUI();
ZEEUI_API UClass* Z_Construct_UClass_UZeeUILobbySlateStyleContainer();
ZEEUI_API UClass* Z_Construct_UClass_UZeeUILobbySlateStyleContainer_NoRegister();
ZEEUI_API UScriptStruct* Z_Construct_UScriptStruct_FZeeUILobbySlateStyle();
// End Cross Module References

// Begin ScriptStruct FZeeUILobbySlateStyle
static_assert(std::is_polymorphic<FZeeUILobbySlateStyle>() == std::is_polymorphic<FSlateWidgetStyle>(), "USTRUCT FZeeUILobbySlateStyle cannot be polymorphic unless super FSlateWidgetStyle is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle;
class UScriptStruct* FZeeUILobbySlateStyle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZeeUILobbySlateStyle, (UObject*)Z_Construct_UPackage__Script_ZeeUI(), TEXT("ZeeUILobbySlateStyle"));
	}
	return Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle.OuterSingleton;
}
template<> ZEEUI_API UScriptStruct* StaticStruct<FZeeUILobbySlateStyle>()
{
	return FZeeUILobbySlateStyle::StaticStruct();
}
struct Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginButtonStyle_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Style that define the appearance of all menu buttons. \n" },
#endif
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Style that define the appearance of all menu buttons." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginButtonTextStyle_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Style that defines the text for our menu title. \n" },
#endif
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Style that defines the text for our menu title." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginTitleTextStyle_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Style that defines the text for our menu title. \n" },
#endif
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Style that defines the text for our menu title." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginBoxTextStyle_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Style that defines the text for our menu title. \n" },
#endif
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Style that defines the text for our menu title." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginBoxEditableTextBoxStyle_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Style that defines the text for our menu title. \n" },
#endif
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Style that defines the text for our menu title." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_LoginButtonStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LoginButtonTextStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LoginTitleTextStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LoginBoxTextStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LoginBoxEditableTextBoxStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZeeUILobbySlateStyle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginButtonStyle = { "LoginButtonStyle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeUILobbySlateStyle, LoginButtonStyle), Z_Construct_UScriptStruct_FButtonStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginButtonStyle_MetaData), NewProp_LoginButtonStyle_MetaData) }; // 1298854793
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginButtonTextStyle = { "LoginButtonTextStyle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeUILobbySlateStyle, LoginButtonTextStyle), Z_Construct_UScriptStruct_FTextBlockStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginButtonTextStyle_MetaData), NewProp_LoginButtonTextStyle_MetaData) }; // 4086975916
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginTitleTextStyle = { "LoginTitleTextStyle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeUILobbySlateStyle, LoginTitleTextStyle), Z_Construct_UScriptStruct_FTextBlockStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginTitleTextStyle_MetaData), NewProp_LoginTitleTextStyle_MetaData) }; // 4086975916
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginBoxTextStyle = { "LoginBoxTextStyle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeUILobbySlateStyle, LoginBoxTextStyle), Z_Construct_UScriptStruct_FTextBlockStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginBoxTextStyle_MetaData), NewProp_LoginBoxTextStyle_MetaData) }; // 4086975916
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginBoxEditableTextBoxStyle = { "LoginBoxEditableTextBoxStyle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FZeeUILobbySlateStyle, LoginBoxEditableTextBoxStyle), Z_Construct_UScriptStruct_FEditableTextBoxStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginBoxEditableTextBoxStyle_MetaData), NewProp_LoginBoxEditableTextBoxStyle_MetaData) }; // 661305945
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginButtonStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginButtonTextStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginTitleTextStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginBoxTextStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewProp_LoginBoxEditableTextBoxStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeUI,
	Z_Construct_UScriptStruct_FSlateWidgetStyle,
	&NewStructOps,
	"ZeeUILobbySlateStyle",
	Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::PropPointers),
	sizeof(FZeeUILobbySlateStyle),
	alignof(FZeeUILobbySlateStyle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FZeeUILobbySlateStyle()
{
	if (!Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle.InnerSingleton, Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle.InnerSingleton;
}
// End ScriptStruct FZeeUILobbySlateStyle

// Begin Class UZeeUILobbySlateStyleContainer
void UZeeUILobbySlateStyleContainer::StaticRegisterNativesUZeeUILobbySlateStyleContainer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZeeUILobbySlateStyleContainer);
UClass* Z_Construct_UClass_UZeeUILobbySlateStyleContainer_NoRegister()
{
	return UZeeUILobbySlateStyleContainer::StaticClass();
}
struct Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Provides a widget style container to allow us to edit properties in-editor\n" },
#endif
		{ "HideCategories", "Object Object" },
		{ "IncludePath", "Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides a widget style container to allow us to edit properties in-editor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LobbySlateStyle_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This is our actual Style object. \n" },
#endif
		{ "ModuleRelativePath", "Public/Lobby/SlateStyle/ZeeUILobbySlateStyle.h" },
		{ "ShowOnlyInnerProperties", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is our actual Style object." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_LobbySlateStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZeeUILobbySlateStyleContainer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::NewProp_LobbySlateStyle = { "LobbySlateStyle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZeeUILobbySlateStyleContainer, LobbySlateStyle), Z_Construct_UScriptStruct_FZeeUILobbySlateStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LobbySlateStyle_MetaData), NewProp_LobbySlateStyle_MetaData) }; // 3868751147
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::NewProp_LobbySlateStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USlateWidgetStyleContainerBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ZeeUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::ClassParams = {
	&UZeeUILobbySlateStyleContainer::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::PropPointers),
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::Class_MetaDataParams), Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UZeeUILobbySlateStyleContainer()
{
	if (!Z_Registration_Info_UClass_UZeeUILobbySlateStyleContainer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZeeUILobbySlateStyleContainer.OuterSingleton, Z_Construct_UClass_UZeeUILobbySlateStyleContainer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZeeUILobbySlateStyleContainer.OuterSingleton;
}
template<> ZEEUI_API UClass* StaticClass<UZeeUILobbySlateStyleContainer>()
{
	return UZeeUILobbySlateStyleContainer::StaticClass();
}
UZeeUILobbySlateStyleContainer::UZeeUILobbySlateStyleContainer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UZeeUILobbySlateStyleContainer);
UZeeUILobbySlateStyleContainer::~UZeeUILobbySlateStyleContainer() {}
// End Class UZeeUILobbySlateStyleContainer

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_Lobby_SlateStyle_ZeeUILobbySlateStyle_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FZeeUILobbySlateStyle::StaticStruct, Z_Construct_UScriptStruct_FZeeUILobbySlateStyle_Statics::NewStructOps, TEXT("ZeeUILobbySlateStyle"), &Z_Registration_Info_UScriptStruct_ZeeUILobbySlateStyle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZeeUILobbySlateStyle), 3868751147U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZeeUILobbySlateStyleContainer, UZeeUILobbySlateStyleContainer::StaticClass, TEXT("UZeeUILobbySlateStyleContainer"), &Z_Registration_Info_UClass_UZeeUILobbySlateStyleContainer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZeeUILobbySlateStyleContainer), 1221905329U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_Lobby_SlateStyle_ZeeUILobbySlateStyle_h_3215329433(TEXT("/Script/ZeeUI"),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_Lobby_SlateStyle_ZeeUILobbySlateStyle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_Lobby_SlateStyle_ZeeUILobbySlateStyle_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_Lobby_SlateStyle_ZeeUILobbySlateStyle_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectPlayground_Plugins_ZeeUI_Source_ZeeUI_Public_Lobby_SlateStyle_ZeeUILobbySlateStyle_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
