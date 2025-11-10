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

#include "ThreadPrintSubsystem.h"
#include "Engine/Engine.h"

void UThreadPrintSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPrint] Subsystem Initialized."));
}

void UThreadPrintSubsystem::Deinitialize()
{
    Super::Deinitialize();
    EmotionLog.Empty();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPrint] Subsystem Deinitialized."));
}

void UThreadPrintSubsystem::RecordEmotionalEvent(const FString& Source, const FString& Emotion, float Intensity)
{
    EmotionLog.Add(FThreadEmotionRecord(Source, Emotion, Intensity));
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPrint] Event: %s felt %s (%.2f)"), *Source, *Emotion, Intensity);
}

void UThreadPrintSubsystem::PrintThreadLog() const
{
    UE_LOG(LogTemp, Log, TEXT("=== [SAGE ThreadPrint Log] ==="));
    for (const FThreadEmotionRecord& Record : EmotionLog)
    {
        UE_LOG(LogTemp, Log, TEXT(" - %s | %s (%.2f)"), *Record.Source, *Record.Emotion, Record.Intensity);
    }
    UE_LOG(LogTemp, Log, TEXT("==============================="));
}
