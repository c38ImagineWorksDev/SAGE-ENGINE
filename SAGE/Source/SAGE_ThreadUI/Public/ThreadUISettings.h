// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThreadUITypes.h"
#include "ThreadUISettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "SAGE ThreadUI Settings"))
class SAGE_THREADUI_API UThreadUISettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Config, Category = "Theme")
    EThreadUITheme DefaultTheme = EThreadUITheme::System;

    // Soft references so you can wire Blueprint widgets later
    UPROPERTY(EditAnywhere, Config, Category = "Classes", meta = (MetaClass = "/Script/UMG.UserWidget"))
    TSoftClassPtr<class UUserWidget> DefaultHUDClass;

    UPROPERTY(EditAnywhere, Config, Category = "Classes", meta = (MetaClass = "/Script/UMG.UserWidget"))
    TSoftClassPtr<class UUserWidget> FadeWidgetClass;

    UPROPERTY(EditAnywhere, Config, Category = "Classes", meta = (MetaClass = "/Script/UMG.UserWidget"))
    TSoftClassPtr<class UUserWidget> LetterboxWidgetClass;

    UPROPERTY(EditAnywhere, Config, Category = "Debug")
    bool bVerboseLogs = false;
};
