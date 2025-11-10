// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadDialogue
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadDialogueModule.h"
#include "Logging/LogMacros.h"

DEFINE_LOG_CATEGORY_STATIC(LogThreadDialogueStartup, Log, All);
IMPLEMENT_MODULE(FThreadDialogueModule, SAGE_ThreadDialogue)

void FThreadDialogueModule::StartupModule()
{
    UE_LOG(LogThreadDialogueStartup, Log, TEXT("SAGE_ThreadDialogue: Startup"));
}

void FThreadDialogueModule::ShutdownModule()
{
    UE_LOG(LogThreadDialogueStartup, Log, TEXT("SAGE_ThreadDialogue: Shutdown"));
}
