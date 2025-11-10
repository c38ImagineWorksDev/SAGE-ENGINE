// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE Editor Target
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;
using System.Collections.Generic;

public class SAGEEditorTarget : TargetRules
{
    public SAGEEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6; // ← updated

        ExtraModuleNames.AddRange(new string[]
        {
            "SAGE",
            "SAGE_ThreadCore",        // runtime core
            "SAGE_ThreadCoreEditor",  // ← editor-only panel
            "SAGE_ThreadWorld",
            "SAGE_ThreadCombat",
            "SAGE_ThreadClasses",
            "SAGE_ThreadInventory",
            "SAGE_ThreadCinematics",
            "SAGE_ThreadAI",
            "SAGE_ThreadUI",
            "SAGE_ThreadTime",
            "SAGE_ThreadData",
            "SAGE_ThreadPrint",
            "SAGE_ThreadDialogue"
        });
    }
}
