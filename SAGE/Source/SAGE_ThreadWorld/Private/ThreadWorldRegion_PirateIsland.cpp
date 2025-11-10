// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadWorld
// Region: Pirate Island
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadWorldRegion_PirateIsland.h"
#include "ThreadWorldSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

AThreadWorldRegion_PirateIsland::AThreadWorldRegion_PirateIsland()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AThreadWorldRegion_PirateIsland::BeginPlay()
{
    Super::BeginPlay();
    RegisterRegionWithThreadWorld();
}

void AThreadWorldRegion_PirateIsland::RegisterRegionWithThreadWorld()
{
    if (UWorld* World = GetWorld())
    {
        if (UGameInstance* GI = World->GetGameInstance())
        {
            if (UThreadWorldSubsystem* WorldSubsystem = GI->GetSubsystem<UThreadWorldSubsystem>())
            {
                WorldSubsystem->RegisterRegion(RegionID.ToString());
                UE_LOG(LogTemp, Log, TEXT("[ThreadWorld] Region Registered: %s"), *RegionID.ToString());
            }
        }
    }
}
