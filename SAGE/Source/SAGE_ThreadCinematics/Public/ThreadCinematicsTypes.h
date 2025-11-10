// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ThreadCinematicsTypes.generated.h"

UENUM(BlueprintType)
enum class EThreadCineMood : uint8
{
    Neutral     UMETA(DisplayName = "Neutral"),
    Tense       UMETA(DisplayName = "Tense"),
    Tragic      UMETA(DisplayName = "Tragic"),
    Triumphant  UMETA(DisplayName = "Triumphant"),
    Awe         UMETA(DisplayName = "Awe"),
    Intimate    UMETA(DisplayName = "Intimate"),
    Dread       UMETA(DisplayName = "Dread")
};

USTRUCT(BlueprintType)
struct SAGE_THREADCINEMATICS_API FThreadCineBlendParams
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0"))
    float BlendSeconds = 0.6f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0"))
    float HoldSeconds = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0"))
    float EaseInExp = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0"))
    float EaseOutExp = 2.0f;

    /** Optional semantic tags that describe the cinematic context. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Cinematics")
    FGameplayTagContainer Tags;
};
