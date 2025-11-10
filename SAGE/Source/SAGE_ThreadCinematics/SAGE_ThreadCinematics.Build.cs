// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadCinematics : ModuleRules
{
    public SAGE_ThreadCinematics(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine",
            "MovieScene", "LevelSequence", "UMG", "GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Projects",
            // SAGE neighbors (soft deps; keep if present in your tree)
            "SAGE_ThreadAudio",
            "SAGE_ThreadPrint",
            "SAGE_ThreadAI",
            "SAGE_ThreadUI",
            "SAGE_ThreadTime"
        });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new[]
            {
                "UnrealEd", "DeveloperSettings", "PropertyEditor", "SettingsEditor"
            });
        }

        bUseUnity = true;
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
    }
}
