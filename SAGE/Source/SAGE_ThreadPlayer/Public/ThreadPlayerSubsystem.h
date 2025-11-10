// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadPlayer
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadPlayerTypes.h"
#include "ThreadPlayerSubsystem.generated.h"

UCLASS()
class SAGE_THREADPLAYER_API UThreadPlayerSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /** Player stats (health, stamina, mana, etc.) */
    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    FThreadPlayerStats PlayerStats;

    /** Player’s unique Thread signature */
    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    FThreadSignature Signature;

    /** Modify player health by amount (can be negative) */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Player")
    void ModifyHealth(float Amount);

    /** Save player state to file */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Player")
    void SavePlayerState();

    /** Load player state from file */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Player")
    void LoadPlayerState();
};
