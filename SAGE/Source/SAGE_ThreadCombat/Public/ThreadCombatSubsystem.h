// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCombat
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadCombatTypes.h"
#include "ThreadCombatSubsystem.generated.h"

UCLASS()
class SAGE_THREADCOMBAT_API UThreadCombatSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /** Performs a basic attack between two entities */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Combat")
    FThreadCombatResult PerformAttack(const FString& Attacker, const FString& Target, float BaseDamage);

    /** Calculates critical hit chance */
    UFUNCTION(BlueprintCallable, Category = "SAGE|Combat")
    bool RollCritical(float ChancePercent) const;
};
