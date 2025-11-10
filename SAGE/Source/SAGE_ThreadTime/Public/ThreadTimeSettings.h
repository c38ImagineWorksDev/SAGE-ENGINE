// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadTime
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThreadTimeSettings.generated.h"

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "ThreadTime Settings"))
class SAGE_THREADTIME_API UThreadTimeSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    /** Synchronize in-game environment to real-world time */
    UPROPERTY(EditAnywhere, config, Category = "SAGE|ThreadTime")
    bool bEnableTimeSync = true;

    /** Time zone offset in hours (for simulated environments) */
    UPROPERTY(EditAnywhere, config, Category = "SAGE|ThreadTime")
    int32 TimeOffsetHours = 0;
};