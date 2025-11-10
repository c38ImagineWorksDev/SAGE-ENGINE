// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE (Root)
// // Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================


#include "SAGE.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FSAGE, SAGE, "SAGE");

void FSAGE::StartupModule()
{
    UE_LOG(LogTemp, Log, TEXT("[SAGE] Core module has started successfully."));
}

void FSAGE::ShutdownModule()
{
    UE_LOG(LogTemp, Log, TEXT("[SAGE] Core module has shut down cleanly."));
}
