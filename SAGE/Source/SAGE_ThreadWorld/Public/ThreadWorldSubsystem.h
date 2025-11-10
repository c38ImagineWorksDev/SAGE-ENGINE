// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadWorld
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadWorldSubsystem.generated.h"

/**
 *  Base environmental management subsystem.
 *  Handles world-level registration and environmental thread state.
 */
UCLASS()
class SAGE_THREADWORLD_API UThreadWorldSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /** Register or update the current active world region */
    UFUNCTION(BlueprintCallable, Category = "SAGE|World")
    void RegisterRegion(const FString& RegionID);

    /** Get the current active region ID */
    UFUNCTION(BlueprintCallable, Category = "SAGE|World")
    FString GetActiveRegion() const;

private:
    UPROPERTY()
    FString ActiveRegion;
};
