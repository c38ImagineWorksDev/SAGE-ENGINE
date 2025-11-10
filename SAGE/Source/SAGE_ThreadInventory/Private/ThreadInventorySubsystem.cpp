// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadInventory
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadInventorySubsystem.h"
#include "Engine/Engine.h"

void UThreadInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadInventory] Subsystem Initialized."));
}

void UThreadInventorySubsystem::Deinitialize()
{
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadInventory] Subsystem Deinitialized."));
}

void UThreadInventorySubsystem::AddItem(const FString& ItemName)
{
    InventoryItems.Add(ItemName);
    UE_LOG(LogTemp, Log, TEXT("[Inventory] Added item: %s"), *ItemName);
}

void UThreadInventorySubsystem::ClearInventory()
{
    InventoryItems.Empty();
    UE_LOG(LogTemp, Log, TEXT("[Inventory] Inventory cleared."));
}

TArray<FString> UThreadInventorySubsystem::GetItems() const
{
    return InventoryItems;
}
