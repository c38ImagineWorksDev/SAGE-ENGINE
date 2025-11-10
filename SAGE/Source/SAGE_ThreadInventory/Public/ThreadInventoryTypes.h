// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadInventory
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "ThreadInventoryTypes.generated.h"

/** Defines basic item data tracked by the inventory system */
USTRUCT(BlueprintType)
struct FThreadItem
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Inventory")
    FString ItemID;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Inventory")
    FString ItemName;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Inventory")
    FString ItemType;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Inventory")
    int32 Quantity = 1;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Inventory")
    bool bEquipped = false;

    FThreadItem()
    {
        ItemID = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens);
    }
};
