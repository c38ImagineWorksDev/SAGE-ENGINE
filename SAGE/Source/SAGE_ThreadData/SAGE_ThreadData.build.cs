// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadData
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadData : ModuleRules
{
    public SAGE_ThreadData(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core","CoreUObject","Engine","Json","JsonUtilities",
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
