// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadAI : ModuleRules
{
    public SAGE_ThreadAI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine",
            "AIModule", "NavigationSystem",
            "GameplayTags", "DeveloperSettings"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Projects", "GameplayTasks",
            "SAGE_ThreadWorld",
            "SAGE_ThreadSense",
            "SAGE_ThreadCombat",
            "SAGE_ThreadPrint",
            "SAGE_ThreadLore",
            "SAGE_ThreadData"
        });

        bUseUnity = true;
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
    }
}
