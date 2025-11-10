// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCoreEditor
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class SDockTab;

class FThreadCoreEditorModule final : public IModuleInterface
{
public:
    // IModuleInterface
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    static const FName ThreadCoreTabName;

private:
    TSharedRef<SDockTab> SpawnThreadCoreTab(const class FSpawnTabArgs& Args);
    void RegisterMenus();
    void RegisterSettings();
    void UnregisterSettings();
};
