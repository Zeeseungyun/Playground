// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ProjectPlayground : ModuleRules
{
    public ProjectPlayground(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "NavigationSystem", 
            "AIModule", 
            "Niagara", 
            "EnhancedInput" ,
            "Slate",
            "SlateCore",
            "UMG"
        });
        
        PublicDependencyModuleNames.AddRange(new string[] { "ZeeNet", "ZeeUI" });
        PublicIncludePathModuleNames.AddRange(new string[] { "ZeeNet", "ZeeUI" });
    }
}
