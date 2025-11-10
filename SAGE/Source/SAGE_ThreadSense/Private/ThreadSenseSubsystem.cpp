// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadSense
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadSenseSubsystem.h"
void UThreadSenseSubsystem::Initialize(FSubsystemCollectionBase& C)
{
    Super::Initialize(C);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadSense] Subsystem Initialized."));
}
void UThreadSenseSubsystem::Deinitialize() { Super::Deinitialize(); }
void UThreadSenseSubsystem::EmitPing(const FString& S, const FString& T, float I)
{
    UE_LOG(LogTemp, Log, TEXT("[Sense] %s senses %s (%.2f)"), *S, *T, I);
}
