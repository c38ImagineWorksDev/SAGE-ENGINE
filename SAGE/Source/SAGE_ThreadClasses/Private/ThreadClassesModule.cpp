// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadClasses
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "Modules/ModuleManager.h"

class FSAGE_ThreadClassesModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadClasses] Module Startup complete."));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadClasses] Module Shutdown complete."));
    }
};

IMPLEMENT_MODULE(FSAGE_ThreadClassesModule, SAGE_ThreadClasses)
