/*
 * ============================================================
 * 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
 *  “Born from Making Reality from Your Imagination.”
 * ============================================================
 * Module: SAGE_ThreadPrint
 * Version: 0.1.0 – The Thread Awakens
 * Author: C38 ImagineWorks LLC
 * Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "ThreadPrintTypes.generated.h"

USTRUCT(BlueprintType)
struct FThreadEmotionRecord
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadPrint")
    FString Source;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadPrint")
    FString Emotion;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadPrint")
    float Intensity;

    FThreadEmotionRecord()
        : Source(TEXT("Unknown")), Emotion(TEXT("Neutral")), Intensity(0.f)
    {
    }

    FThreadEmotionRecord(const FString& InSource, const FString& InEmotion, float InIntensity)
        : Source(InSource), Emotion(InEmotion), Intensity(InIntensity)
    {
    }
};
