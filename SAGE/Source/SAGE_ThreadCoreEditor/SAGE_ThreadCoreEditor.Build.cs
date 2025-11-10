// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCoreEditor
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;

public class SAGE_ThreadCoreEditor : ModuleRules
{
    public SAGE_ThreadCoreEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        // Build this module for Editor only
        PrecompileForTargets = PrecompileTargetsType.Editor;

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core","CoreUObject","Engine","Slate","SlateCore"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            // Editor frameworks
            "UnrealEd","LevelEditor","ToolMenus","Projects",
            "DeveloperSettings","PropertyEditor","InputCore",
            "ApplicationCore","EditorSubsystem","EditorStyle", // Slate styling/icons
            "UMG",

            // Runtime core you want to surface in the panel
            "SAGE_ThreadCore"
        });

        bUseUnity = true;
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
    }
}
