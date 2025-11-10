// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadPlayer
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "ThreadPlayerTypes.generated.h"

/** Player statistics tracked by SAGE */
USTRUCT(BlueprintType)
struct FThreadPlayerStats
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    float Health = 100.f;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    float Stamina = 100.f;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    float Mana = 50.f;
};

/** Player Thread signature (unique identity hash) */
USTRUCT(BlueprintType)
struct FThreadSignature
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    FString PlayerID;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|Player")
    FString ThreadHash;

    FThreadSignature()
    {
        PlayerID = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens);
        ThreadHash = FMD5::HashAnsiString(*PlayerID);
    }
};
#pragma once
