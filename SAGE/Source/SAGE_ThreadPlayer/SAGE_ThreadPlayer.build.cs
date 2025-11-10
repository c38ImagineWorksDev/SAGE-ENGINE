// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadPlayer
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadPlayer : ModuleRules
{
    public SAGE_ThreadPlayer(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "SAGE_ThreadCore",
            "SAGE_ThreadData",
            "SAGE_ThreadPrint",
            "Json",
            "JsonUtilities",

        });

        PrivateDependencyModuleNames.AddRange(new string[] { "Projects" });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "UnrealEd",
                "DeveloperSettings",
                "PropertyEditor",
                "EditorSubsystem"
            });
        }

        bUseUnity = true;
    }
}
