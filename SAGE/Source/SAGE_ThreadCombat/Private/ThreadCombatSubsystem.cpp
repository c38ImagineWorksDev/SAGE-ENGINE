// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCombat
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadCombatSubsystem.h"
#include "ThreadPlayerSubsystem.h"
#include "ThreadPhysicsSubsystem.h"
#include "Kismet/KismetMathLibrary.h"

void UThreadCombatSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCombat] Subsystem Initialized."));
}

void UThreadCombatSubsystem::Deinitialize()
{
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCombat] Subsystem Deinitialized."));
}

FThreadCombatResult UThreadCombatSubsystem::PerformAttack(const FString& Attacker, const FString& Target, float BaseDamage)
{
    FThreadCombatResult Result;
    Result.Source = Attacker;
    Result.Target = Target;
    Result.bCritical = RollCritical(15.0f); // 15% base crit chance

    // Apply damage scaling
    Result.Damage = BaseDamage * (Result.bCritical ? 1.75f : 1.0f);

    // If Player subsystem exists, adjust health
    if (UGameInstance* GI = GetGameInstance())
    {
        if (UThreadPlayerSubsystem* Player = GI->GetSubsystem<UThreadPlayerSubsystem>())
        {
            if (Target.Equals(Player->Signature.PlayerID))
            {
                Player->ModifyHealth(-Result.Damage);
            }
        }

        if (UThreadPhysicsSubsystem* Physics = GI->GetSubsystem<UThreadPhysicsSubsystem>())
        {
            Physics->RegisterImpact(Attacker, Target, Result.Damage);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("[Combat] %s dealt %.2f damage to %s%s"),
        *Attacker, Result.Damage, *Target,
        Result.bCritical ? TEXT(" [CRITICAL!]") : TEXT(""));

    return Result;
}

bool UThreadCombatSubsystem::RollCritical(float ChancePercent) const
{
    const float Roll = UKismetMathLibrary::RandomFloatInRange(0.f, 100.f);
    return Roll <= ChancePercent;
}
