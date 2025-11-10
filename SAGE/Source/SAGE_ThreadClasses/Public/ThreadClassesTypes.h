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
#include "GameplayTagContainer.h"
#include "ThreadClassesTypes.generated.h"

UENUM(BlueprintType)
enum class EThreadClass : uint8
{
    None        UMETA(DisplayName = "None"),
    Warrior     UMETA(DisplayName = "Warrior"),
    Ranger      UMETA(DisplayName = "Ranger"),
    Arcanist    UMETA(DisplayName = "Arcanist"),
    Trickster   UMETA(DisplayName = "Trickster")
};

UENUM(BlueprintType)
enum class EThreadSubclass : uint8
{
    None        UMETA(DisplayName = "None"),
    Berserker   UMETA(DisplayName = "Berserker"),
    Sentinel    UMETA(DisplayName = "Sentinel"),
    Stormcaller UMETA(DisplayName = "Stormcaller"),
    Shadowdancer UMETA(DisplayName = "Shadowdancer")
};

USTRUCT(BlueprintType)
struct FThreadClassProgress
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Classes")
    EThreadClass CurrentClass = EThreadClass::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Classes")
    EThreadSubclass Subclass = EThreadSubclass::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Classes")
    int32 Level = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Classes")
    int32 CurrentXP = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Classes")
    int32 XPToNextLevel = 100;

    /** Optional: tags granted by class/subclass (for Combat/AI gating) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SAGE|Classes")
    FGameplayTagContainer GrantedTags;
};
