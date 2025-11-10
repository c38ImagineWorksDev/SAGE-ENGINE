// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadTime
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadTime : ModuleRules
{
    public SAGE_ThreadTime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // --- Core Dependencies ---
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "SAGE_ThreadCore"   // Handshake with ThreadCoreSubsystem
        });

        // --- Private/Internal ---
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Projects"
        });

        // --- Editor-Only Dependencies ---
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "UnrealEd",
                "DeveloperSettings",
                "PropertyEditor",
                "SettingsEditor",
                "EditorSubsystem"
            });
        }

        bUseUnity = true;
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
    }
}
