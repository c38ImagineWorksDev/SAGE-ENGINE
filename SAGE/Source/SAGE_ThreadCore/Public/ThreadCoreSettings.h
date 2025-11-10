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

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThreadCoreSettings.generated.h"

 /**
  * UThreadCoreSettings
  * Global SAGE configuration, accessible via Project Settings.
  */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "SAGE ThreadCore Settings"))
class SAGE_THREADCORE_API UThreadCoreSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    /** Whether SAGE modules should auto-initialize at runtime */
    UPROPERTY(EditAnywhere, config, Category = "Initialization")
    bool bAutoInitializeModules = true;

    /** Whether to log SAGE subsystem messages to console */
    UPROPERTY(EditAnywhere, config, Category = "Debug")
    bool bEnableVerboseLogging = true;
};
