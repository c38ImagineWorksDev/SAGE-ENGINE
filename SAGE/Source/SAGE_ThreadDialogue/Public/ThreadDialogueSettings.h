// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadDialogue
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThreadDialogueSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "SAGE ThreadDialogue Settings"))
class SAGE_THREADDIALOGUE_API UThreadDialogueSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    // Show subtitles by default even if there’s no UI impl yet
    UPROPERTY(EditAnywhere, Config, Category = "Subtitles")
    bool bSubtitlesEnabled = true;

    // Auto-advance lines that have AutoAdvanceAfter <= 0 using this time
    UPROPERTY(EditAnywhere, Config, Category = "Flow")
    float DefaultAutoAdvance = 2.0f;

    // Debug logging
    UPROPERTY(EditAnywhere, Config, Category = "Debug")
    bool bVerboseLogs = false;
};
