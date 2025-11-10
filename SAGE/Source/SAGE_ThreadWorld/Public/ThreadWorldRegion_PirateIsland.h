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

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThreadWorldRegion_PirateIsland.generated.h"

UCLASS(Blueprintable)
class SAGE_THREADWORLD_API AThreadWorldRegion_PirateIsland : public AActor
{
    GENERATED_BODY()

public:
    AThreadWorldRegion_PirateIsland();

protected:
    virtual void BeginPlay() override;

public:
    /** The region ID recognized by ThreadWorld */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|World")
    FName RegionID = "Pirate_Island";

    /** The human-readable name of this region */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SAGE|World")
    FString DisplayName = "Pirate Island";

    /** Called when this region begins play to register itself */
    UFUNCTION(BlueprintCallable, Category = "SAGE|World")
    void RegisterRegionWithThreadWorld();
};
