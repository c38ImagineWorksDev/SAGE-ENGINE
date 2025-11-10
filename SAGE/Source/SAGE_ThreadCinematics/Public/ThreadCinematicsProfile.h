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
#include "Engine/DataAsset.h"
#include "ThreadCinematicsTypes.h"
#include "ThreadCinematicsProfile.generated.h"

/**
 * Cinematic mood profile: describe how a mood *looks/feels*
 * (camera offset hints, PP weight, vignette, FOV bias, etc.)
 * Designers can author multiple assets and swap/blend them at runtime.
 */
UCLASS(BlueprintType)
class SAGE_THREADCINEMATICS_API UThreadCinematicsProfile : public UDataAsset
{
    GENERATED_BODY()
public:
    /** What mood this profile represents. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|Cinematics")
    EThreadCineMood Mood = EThreadCineMood::Neutral;

    /** Target FOV during this mood (leave < 1.0 to ignore). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0"))
    float TargetFOV = 0.0f;

    /** Optional camera boom offset (applied additively). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|Cinematics")
    FVector CameraOffset = FVector::ZeroVector;

    /** Post-process intensity [0..1] designers can map in BP/UI. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float PostProcessWeight = 0.0f;

    /** UI vignette strength [0..1], forwarded to ThreadUI (optional). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|Cinematics", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float VignetteWeight = 0.0f;

    /** Tags to describe the profile's vibe (e.g., Mood.Tense, Scene.Boss). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|Cinematics")
    FGameplayTagContainer Tags;
};
