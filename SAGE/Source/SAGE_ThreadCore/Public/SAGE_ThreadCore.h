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

#pragma once

#include "Modules/ModuleManager.h"

class FSAGE_ThreadCoreModule : public IModuleInterface
{
public:
    /** Called when the module is loaded into memory */
    virtual void StartupModule() override;

    /** Called when the module is unloaded from memory */
    virtual void ShutdownModule() override;

    /** Returns true if the module is initialized */
    static bool IsInitialized();

private:
    static bool bInitialized;
};
