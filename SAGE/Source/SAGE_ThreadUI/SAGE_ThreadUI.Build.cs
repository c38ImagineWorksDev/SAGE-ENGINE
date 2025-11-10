// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadUI : ModuleRules
{
    public SAGE_ThreadUI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core","CoreUObject","Engine","UMG","Slate","SlateCore","GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Projects","InputCore","ApplicationCore",
            "SAGE_ThreadTime","SAGE_ThreadPrint" // optional nice-to-haves
        });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new[]
            {
                "UnrealEd","DeveloperSettings","PropertyEditor","SettingsEditor"
            });
        }

        bUseUnity = true;
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
    }
}
