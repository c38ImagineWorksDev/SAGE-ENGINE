// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadNetwork
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadNetwork : ModuleRules
{
    public SAGE_ThreadNetwork(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core","CoreUObject","Engine",
            "OnlineSubsystem","OnlineSubsystemUtils",
            "SAGE_ThreadCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { "Projects" });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "UnrealEd","DeveloperSettings","PropertyEditor",
                "SettingsEditor","EditorSubsystem"
            });
        }
    }
}
