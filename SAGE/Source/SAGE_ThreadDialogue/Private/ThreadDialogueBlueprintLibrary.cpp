// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadDialogue
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadDialogueBlueprintLibrary.h"
#include "ThreadDialogueSubsystem.h"
#include "ThreadDialogueAsset.h"

static UThreadDialogueSubsystem* GetDlg(const UObject* WorldContext)
{
    return UThreadDialogueSubsystem::Get(WorldContext);
}

bool UThreadDialogueBlueprintLibrary::Dialogue_Start(const UObject* WorldContext, UThreadDialogueAsset* Asset, FName StartNode)
{
    if (auto* Dlg = GetDlg(WorldContext)) return Dlg->StartDialogue(Asset, StartNode);
    return false;
}

void UThreadDialogueBlueprintLibrary::Dialogue_Advance(const UObject* WorldContext)
{
    if (auto* Dlg = GetDlg(WorldContext)) Dlg->Advance();
}

void UThreadDialogueBlueprintLibrary::Dialogue_Choose(const UObject* WorldContext, int32 ChoiceIndex)
{
    if (auto* Dlg = GetDlg(WorldContext)) Dlg->Choose(ChoiceIndex);
}
