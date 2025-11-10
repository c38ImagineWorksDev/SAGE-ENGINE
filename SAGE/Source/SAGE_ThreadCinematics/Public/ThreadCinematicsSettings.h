// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThreadCinematicsTypes.h"
// must be last:
#include "ThreadCinematicsSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "SAGE ThreadCinematics Settings"))
class SAGE_THREADCINEMATICS_API UThreadCinematicsSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Config, Category = "Defaults")
    EThreadCineMood DefaultMood = EThreadCineMood::Neutral;

    UPROPERTY(EditAnywhere, Config, Category = "Debug")
    bool bVerboseLogs = false;
};
