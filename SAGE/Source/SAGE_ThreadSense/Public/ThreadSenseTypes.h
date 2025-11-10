// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadSense
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "ThreadSenseTypes.generated.h"

USTRUCT(BlueprintType)
struct FThreadStimulus
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite) FString Source;
    UPROPERTY(BlueprintReadWrite) FString StimulusType;
    UPROPERTY(BlueprintReadWrite) float Strength = 1.f;
};
