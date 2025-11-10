// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE Target
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

using UnrealBuildTool;
using System.Collections.Generic;

public class SAGETarget : TargetRules
{
    public SAGETarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6; // ← updated

        ExtraModuleNames.AddRange(new string[] {
            "SAGE",
            "SAGE_ThreadWorld","SAGE_ThreadCombat","SAGE_ThreadClasses",
            "SAGE_ThreadInventory","SAGE_ThreadCinematics","SAGE_ThreadAI",
            "SAGE_ThreadUI","SAGE_ThreadTime","SAGE_ThreadData","SAGE_ThreadPrint",
            "SAGE_ThreadDialogue"
        });
    }
}
