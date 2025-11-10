// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAI
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "GameplayTagContainer.h"
#include "ThreadAITypes.generated.h"

/** High-level intent states inform BT/Tasks and steering */
UENUM(BlueprintType)
enum class EThreadAIIntent : uint8
{
    Passive      UMETA(DisplayName = "Passive"),
    Alert        UMETA(DisplayName = "Alert"),
    Aggressive   UMETA(DisplayName = "Aggressive"),
    Flee         UMETA(DisplayName = "Flee"),
    Investigate  UMETA(DisplayName = "Investigate")
};

/** A lightweight stimulus packet */
USTRUCT(BlueprintType)
struct FThreadAIStimulus
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI")
    TWeakObjectPtr<AActor> Source = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI")
    TWeakObjectPtr<AActor> Target = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI")
    EThreadAIIntent Intent = EThreadAIIntent::Investigate;

    /** Optional semantic tags (e.g., ThreadPrint or world tags) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI")
    FGameplayTagContainer Tags;
};

/** Behavior tuning profile (data-driven knobs) */
USTRUCT(BlueprintType)
struct FThreadAIProfile
{
    GENERATED_BODY()

    /** Reaction delay to stimuli (seconds) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI", meta = (ClampMin = "0.0"))
    float ReactionLatency = 0.15f;

    /** How long to remember a target without refresh (seconds) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI", meta = (ClampMin = "0.0"))
    float MemorySeconds = 8.0f;

    /** Base perception radius (can be scaled by ThreadSense) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI", meta = (ClampMin = "0.0"))
    float PerceptionRadius = 1800.0f;

    /** Aggression bias multiplier from ThreadPrint confidence/infamy */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|AI", meta = (ClampMin = "0.0"))
    float AggressionBias = 1.0f;
};
