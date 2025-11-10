// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadWorld
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadWorldSubsystem.h"
#include "Engine/Engine.h"

void UThreadWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    ActiveRegion = TEXT("Unknown");
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadWorld] Subsystem Initialized."));
}

void UThreadWorldSubsystem::Deinitialize()
{
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadWorld] Subsystem Deinitialized."));
}

void UThreadWorldSubsystem::RegisterRegion(const FString& RegionID)
{
    ActiveRegion = RegionID;
    UE_LOG(LogTemp, Log, TEXT("[ThreadWorld] Active region set to: %s"), *RegionID);
}

FString UThreadWorldSubsystem::GetActiveRegion() const
{
    return ActiveRegion;
}
