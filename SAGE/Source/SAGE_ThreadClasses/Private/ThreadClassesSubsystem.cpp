// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadClasses
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadClassesSubsystem.h"
#include "Engine/Engine.h"

void UThreadClassesSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Progress.Level = FMath::Max(1, Progress.Level);
    Progress.XPToNextLevel = ComputeXPToNextLevel(Progress.Level);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadClasses] Subsystem Initialized. L% d / %d XP to next"),
        Progress.Level, Progress.XPToNextLevel);
}

void UThreadClassesSubsystem::Deinitialize()
{
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadClasses] Subsystem Deinitialized."));
}

int32 UThreadClassesSubsystem::ComputeXPToNextLevel(int32 CurrentLevel) const
{
    const float Need = static_cast<float>(BaseXPPerLevel) * FMath::Pow(static_cast<float>(CurrentLevel), XPExponent);
    return FMath::Max(50, FMath::RoundToInt(Need));
}

void UThreadClassesSubsystem::SetClass(EThreadClass NewClass)
{
    if (Progress.CurrentClass == NewClass) { return; }

    Progress.CurrentClass = NewClass;

    // Reset subclass if it doesn't conceptually fit (simple guard for now)
    if (NewClass == EThreadClass::None)
    {
        Progress.Subclass = EThreadSubclass::None;
    }

    // Example: grant a tag bucket based on class (expand later)
    Progress.GrantedTags.Reset();
    switch (NewClass)
    {
    case EThreadClass::Warrior:   Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Class.Warrior"))); break;
    case EThreadClass::Ranger:    Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Class.Ranger"))); break;
    case EThreadClass::Arcanist:  Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Class.Arcanist"))); break;
    case EThreadClass::Trickster: Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Class.Trickster"))); break;
    default: break;
    }

    UE_LOG(LogTemp, Log, TEXT("[Classes] Class set to %d"), static_cast<int32>(NewClass));
}

void UThreadClassesSubsystem::UnlockSubclass(EThreadSubclass NewSubclass)
{
    // Minimal rule: cannot pick a subclass without a class
    if (Progress.CurrentClass == EThreadClass::None)
    {
        UE_LOG(LogTemp, Warning, TEXT("[Classes] Cannot set subclass without a primary class."));
        return;
    }

    Progress.Subclass = NewSubclass;

    // Add a sample tag per subclass (tweak later)
    switch (NewSubclass)
    {
    case EThreadSubclass::Berserker:   Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Subclass.Berserker"))); break;
    case EThreadSubclass::Sentinel:    Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Subclass.Sentinel"))); break;
    case EThreadSubclass::Stormcaller: Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Subclass.Stormcaller"))); break;
    case EThreadSubclass::Shadowdancer:Progress.GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Subclass.Shadowdancer"))); break;
    default: break;
    }

    UE_LOG(LogTemp, Log, TEXT("[Classes] Subclass set to %d"), static_cast<int32>(NewSubclass));
}

void UThreadClassesSubsystem::GainExperience(int32 Amount)
{
    if (Amount <= 0) { return; }

    Progress.CurrentXP += Amount;
    UE_LOG(LogTemp, Log, TEXT("[Classes] +%d XP (L%d: %d/%d)"),
        Amount, Progress.Level, Progress.CurrentXP, Progress.XPToNextLevel);

    while (Progress.CurrentXP >= Progress.XPToNextLevel)
    {
        Progress.CurrentXP -= Progress.XPToNextLevel;
        Progress.Level++;
        Progress.XPToNextLevel = ComputeXPToNextLevel(Progress.Level);

        UE_LOG(LogTemp, Log, TEXT("[Classes] LEVEL UP! -> L%d (Need %d XP)"),
            Progress.Level, Progress.XPToNextLevel);

        OnLevelUp.Broadcast(Progress.Level);
    }
}
