// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadClasses
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadClasses : ModuleRules
{
    public SAGE_ThreadClasses(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core","CoreUObject","Engine","GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Projects","SAGE_ThreadData","SAGE_ThreadWorld","SAGE_ThreadPrint"
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
