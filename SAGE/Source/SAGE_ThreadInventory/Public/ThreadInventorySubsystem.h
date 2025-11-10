// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadInventory
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadInventorySubsystem.generated.h"

/**
 * Handles basic inventory logic for SAGE engine testing.
 * Future versions will include serialization and metadata.
 */
UCLASS()
class SAGE_THREADINVENTORY_API UThreadInventorySubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "SAGE|Inventory")
    void AddItem(const FString& ItemName);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Inventory")
    void ClearInventory();

    UFUNCTION(BlueprintCallable, Category = "SAGE|Inventory")
    TArray<FString> GetItems() const;

private:
    UPROPERTY()
    TArray<FString> InventoryItems;
};
