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
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadPrintTypes.h"
#include "ThreadPrintSubsystem.generated.h"

/**
 * ThreadPrint handles emotional resonance tracking and narrative consequence.
 */
UCLASS()
class SAGE_THREADPRINT_API UThreadPrintSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /** Records an emotional event in the ThreadPrint log */
    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadPrint")
    void RecordEmotionalEvent(const FString& Source, const FString& Emotion, float Intensity);

    /** Dumps all recorded events to the log */
    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadPrint")
    void PrintThreadLog() const;

private:
    UPROPERTY()
    TArray<FThreadEmotionRecord> EmotionLog;
};
