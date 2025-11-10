// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThreadAITypes.h"
#include "ThreadAISettings.generated.h"

/** Project Settings → SAGE → ThreadAI */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "SAGE ThreadAI Settings"))
class SAGE_THREADAI_API UThreadAISettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Config, Category = "Defaults")
    FThreadAIProfile DefaultProfile;

    UPROPERTY(EditAnywhere, Config, Category = "Tags")
    FGameplayTagContainer GlobalStimulusTags;

    UPROPERTY(EditAnywhere, Config, Category = "Debug")
    bool bVerboseLogs = false;
};
