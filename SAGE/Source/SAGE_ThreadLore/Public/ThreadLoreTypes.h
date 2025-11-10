// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadLore
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "ThreadLoreTypes.generated.h"

USTRUCT(BlueprintType)
struct FThreadLoreEntry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadLore") FString Key;
    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadLore") FString Value;
};
