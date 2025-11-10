// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ThreadUITypes.generated.h"

UENUM(BlueprintType)
enum class EThreadUITheme : uint8
{
    System     UMETA(DisplayName = "System"),
    Minimal    UMETA(DisplayName = "Minimal"),
    Noir       UMETA(DisplayName = "Noir"),
    HighViz    UMETA(DisplayName = "HighViz"),
};

USTRUCT(BlueprintType)
struct SAGE_THREADUI_API FThreadUINotification
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Message = FText::GetEmpty();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Duration = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag StyleTag; // e.g., UI.Notify.Success / Warning / Error
};

USTRUCT(BlueprintType)
struct SAGE_THREADUI_API FThreadUIBlendParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Duration = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurveExponent = 1.0f; // cheap ease-in/out stand-in
};
