// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadUIModule.h"
#include "Logging/LogMacros.h"

DEFINE_LOG_CATEGORY_STATIC(LogThreadUIStartup, Log, All);
IMPLEMENT_MODULE(FThreadUIModule, SAGE_ThreadUI)

void FThreadUIModule::StartupModule()
{
    UE_LOG(LogThreadUIStartup, Log, TEXT("SAGE_ThreadUI: Startup"));
}

void FThreadUIModule::ShutdownModule()
{
    UE_LOG(LogThreadUIStartup, Log, TEXT("SAGE_ThreadUI: Shutdown"));
}
