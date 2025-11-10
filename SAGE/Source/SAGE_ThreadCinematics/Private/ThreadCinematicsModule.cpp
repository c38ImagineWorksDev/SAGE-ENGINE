// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadCinematicsModule.h"
#include "Logging/LogMacros.h"

DEFINE_LOG_CATEGORY_STATIC(LogThreadCinematicsStartup, Log, All);
IMPLEMENT_MODULE(FThreadCinematicsModule, SAGE_ThreadCinematics)

void FThreadCinematicsModule::StartupModule()
{
    UE_LOG(LogThreadCinematicsStartup, Log, TEXT("SAGE_ThreadCinematics: Startup"));
}

void FThreadCinematicsModule::ShutdownModule()
{
    UE_LOG(LogThreadCinematicsStartup, Log, TEXT("SAGE_ThreadCinematics: Shutdown"));
}
