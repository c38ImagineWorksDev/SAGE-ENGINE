// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCore
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadCore : ModuleRules
{
    public SAGE_ThreadCore(ReadOnlyTargetRules Target) : base(Target)
    {
        // ------------------------------------------------------------
        // PCH Settings
        // ------------------------------------------------------------
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // ------------------------------------------------------------
        // Core Unreal Dependencies
        // ------------------------------------------------------------
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore"
        });

        // ------------------------------------------------------------
        // Private Dependencies (Internal Use Only)
        // ------------------------------------------------------------
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Projects",
            "Slate",
            "SlateCore"
        });

        // ------------------------------------------------------------
        // Editor Dependencies (Optional)
        // ------------------------------------------------------------
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "UnrealEd",           // Core editor systems
                "DeveloperSettings",  // Required for UDeveloperSettings subclasses
                "PropertyEditor",     // For custom details panels and UI widgets
                "SettingsEditor",     // Enables SAGE settings in Project Settings
                "EditorSubsystem",    // Editor-only subsystem management
                "Slate",              // UI rendering framework
                "SlateCore"           // Core Slate components
            });
        }

        // ------------------------------------------------------------
        // Build Settings | C38 ImagineWorks
        // ------------------------------------------------------------
        bUseUnity = true;                     // Keep fast builds for now
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;

        // Uncomment below if you add custom log categories or diagnostics layers later
        // bUseUnity = false;
    }
}
