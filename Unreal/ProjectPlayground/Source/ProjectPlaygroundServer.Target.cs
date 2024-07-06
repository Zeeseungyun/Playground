// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class ProjectPlaygroundServerTarget : TargetRules
{
	public ProjectPlaygroundServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("ProjectPlayground");
		bUseLoggingInShipping = true;
	}
}
