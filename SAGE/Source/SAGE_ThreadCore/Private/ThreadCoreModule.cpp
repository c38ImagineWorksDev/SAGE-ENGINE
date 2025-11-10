/*
 * ============================================================
 * 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
 *  “Born from Making Reality from Your Imagination.”
 * ============================================================
 * Module: SAGE_ThreadCore
 * Version: 0.1.0 – The Thread Awakens
 * Author: C38 ImagineWorks LLC
 * Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
 */


#include "Modules/ModuleManager.h"
#include "ThreadCoreSubsystem.h"

class FSAGE_ThreadCoreModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCore] Module Startup complete."));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCore] Module Shutdown complete."));
    }
};

// The module name here *must* match the .build.cs filename exactly.
IMPLEMENT_MODULE(FSAGE_ThreadCoreModule, SAGE_ThreadCore)
