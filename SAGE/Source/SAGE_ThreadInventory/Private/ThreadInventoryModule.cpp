// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadInventory
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "Modules/ModuleManager.h"

class FSAGE_ThreadInventoryModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadInventory] Module Startup complete."));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadInventory] Module Shutdown complete."));
    }
};

IMPLEMENT_MODULE(FSAGE_ThreadInventoryModule, SAGE_ThreadInventory)
