// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ThreadCinematicsTypes.h"
#include "ThreadCinematicsSubsystem.generated.h"

class ULevelSequence;
class ULevelSequencePlayer;
class UThreadCinematicsSettings;
class UThreadCinematicsProfile;

DECLARE_LOG_CATEGORY_EXTERN(LogThreadCinematics, Log, All);

/**
 * World-level cinematics brain for SAGE.
 * Owns mood state, simple profile blending, and basic LevelSequence playback.
 */
UCLASS(BlueprintType)
class SAGE_THREADCINEMATICS_API UThreadCinematicsSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    // Lifecycle
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    // --- Simple mood helpers ---
    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics")
    void SetMood(EThreadCineMood NewMood);

    UFUNCTION(BlueprintPure, Category = "SAGE|Cinematics")
    EThreadCineMood GetMood() const { return CurrentMood; }

    UFUNCTION(BlueprintPure, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    static UThreadCinematicsSubsystem* Get(const UObject* WorldContext);

    // --- API used by the Blueprint Library ---
    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics")
    void SetCinematicMood(EThreadCineMood NewMood, FThreadCineBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics")
    void BlendToProfile(UThreadCinematicsProfile* Profile, FThreadCineBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    ULevelSequencePlayer* PlayReactiveSequence(const UObject* WorldContext, ULevelSequence* Sequence, bool bHideHUD);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics")
    void StopActiveSequence(bool bRestoreHUD);

    UFUNCTION(BlueprintPure, Category = "SAGE|Cinematics")
    bool IsSequencePlaying() const;

private:
    UPROPERTY()
    UThreadCinematicsSettings* Settings = nullptr;

    UPROPERTY(Transient)
    EThreadCineMood CurrentMood = EThreadCineMood::Neutral;

    UPROPERTY(Transient)
    TWeakObjectPtr<ULevelSequencePlayer> ActivePlayer;

    UPROPERTY(Transient)
    bool bHUDHidden = false;
};
