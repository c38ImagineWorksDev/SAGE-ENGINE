// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadData
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadDataSubsystem.generated.h"

/**
 * Handles data persistence, saving, and loading for SAGE systems.
 * Provides a unified interface for serializing gameplay or engine state.
 */
UCLASS()
class SAGE_THREADDATA_API UThreadDataSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:

    /** Initialize the subsystem at runtime */
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    /** Deinitialize the subsystem when shutting down */
    virtual void Deinitialize() override;

    /** Save text-based data to a file inside the Saved/ directory */
    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadData")
    void SaveStringToFile(const FString& Data, const FString& FileName);

    /** Load text-based data from a file inside the Saved/ directory */
    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadData")
    FString LoadStringFromFile(const FString& FileName) const;
};
