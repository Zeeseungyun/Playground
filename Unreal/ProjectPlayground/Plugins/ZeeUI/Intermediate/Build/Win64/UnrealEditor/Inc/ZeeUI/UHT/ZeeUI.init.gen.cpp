// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZeeUI_init() {}
	ZEEUI_API UFunction* Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnBoardMoved__DelegateSignature();
	ZEEUI_API UFunction* Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnStickActivated__DelegateSignature();
	ZEEUI_API UFunction* Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnStickInactivated__DelegateSignature();
	ZEEUI_API UFunction* Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnStickMoved__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ZeeUI;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ZeeUI()
	{
		if (!Z_Registration_Info_UPackage__Script_ZeeUI.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnBoardMoved__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnStickActivated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnStickInactivated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UZeeUIVirtualJoystick_Del_OnStickMoved__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ZeeUI",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x786FC48D,
				0x56EB93F0,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ZeeUI.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ZeeUI.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ZeeUI(Z_Construct_UPackage__Script_ZeeUI, TEXT("/Script/ZeeUI"), Z_Registration_Info_UPackage__Script_ZeeUI, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x786FC48D, 0x56EB93F0));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
