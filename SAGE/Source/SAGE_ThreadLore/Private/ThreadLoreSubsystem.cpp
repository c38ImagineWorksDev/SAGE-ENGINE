/*
 * ============================================================
 * ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
 *  “Born from Making Reality from Your Imagination.”
 * ============================================================
 * Module: SAGE_ThreadLore
 * Version: 0.1.0 – The Thread Awakens
 * Author: C38 ImagineWorks LLC
 * Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
 */
#include "ThreadLoreSubsystem.h"
void UThreadLoreSubsystem::Initialize(FSubsystemCollectionBase& C)
{
    Super::Initialize(C);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadLore] Subsystem Initialized."));
}
void UThreadLoreSubsystem::Deinitialize()
{
    Super::Deinitialize();
    LoreMemory.Empty();
}
void UThreadLoreSubsystem::Remember(FString Key, FString Value)
{
    LoreMemory.Add(Key, Value);
    UE_LOG(LogTemp, Log, TEXT("[Lore] %s -> %s"), *Key, *Value);
}
FString UThreadLoreSubsystem::Recall(FString Key) const
{
    const FString* Found = LoreMemory.Find(Key);
    return Found ? *Found : TEXT("Unknown");
}
