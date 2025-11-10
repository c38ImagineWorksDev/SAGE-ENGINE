// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadClasses
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadClassesTypes.h"
#include "ThreadClassesSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnThreadLevelUp, int32, NewLevel);

UCLASS()
class SAGE_THREADCLASSES_API UThreadClassesSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /** Set the player’s primary class (resets subclass if incompatible) */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Classes")
    void SetClass(EThreadClass NewClass);

    /** Unlock or switch subclass (requires a primary class chosen) */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Classes")
    void UnlockSubclass(EThreadSubclass NewSubclass);

    /** Add XP and auto-level with a simple curve */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Classes")
    void GainExperience(int32 Amount);

    /** Read-only accessors */
    UFUNCTION(BlueprintPure, Category = "SAGE|Classes") int32 GetLevel() const { return Progress.Level; }
    UFUNCTION(BlueprintPure, Category = "SAGE|Classes") int32 GetXP() const { return Progress.CurrentXP; }
    UFUNCTION(BlueprintPure, Category = "SAGE|Classes") int32 GetXPToNext() const { return Progress.XPToNextLevel; }
    UFUNCTION(BlueprintPure, Category = "SAGE|Classes") EThreadClass GetClass() const { return Progress.CurrentClass; }
    UFUNCTION(BlueprintPure, Category = "SAGE|Classes") EThreadSubclass GetSubclass() const { return Progress.Subclass; }

    /** Fired whenever the player levels up */
    UPROPERTY(BlueprintAssignable, Category = "SAGE|Classes")
    FOnThreadLevelUp OnLevelUp;

private:
    /** Basic XP curve: base * pow(Level, exponent) rounded to int */
    int32 ComputeXPToNextLevel(int32 CurrentLevel) const;

private:
    UPROPERTY()
    FThreadClassProgress Progress;

    /** Tunables for the XP curve */
    UPROPERTY(EditAnywhere, Category = "SAGE|Classes|Tuning")
    int32 BaseXPPerLevel = 100;

    UPROPERTY(EditAnywhere, Category = "SAGE|Classes|Tuning")
    float XPExponent = 1.35f; // gentle ARPG-style curve
};
