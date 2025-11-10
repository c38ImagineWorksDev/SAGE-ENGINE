// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCombat
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "ThreadCombatTypes.generated.h"

/** Basic combat result struct */
USTRUCT(BlueprintType)
struct FThreadCombatResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Combat")
    FString Source;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Combat")
    FString Target;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Combat")
    float Damage = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Combat")
    bool bCritical = false;
};
