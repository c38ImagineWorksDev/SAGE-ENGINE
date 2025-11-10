// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadInventory
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadInventory : ModuleRules
{
    public SAGE_ThreadInventory(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "SAGE_ThreadCore",
            "SAGE_ThreadPlayer",
            "SAGE_ThreadData"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Projects"
        });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.Add("UnrealEd");
        }
    }
}
