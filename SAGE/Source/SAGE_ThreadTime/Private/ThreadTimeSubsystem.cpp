// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadTime
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadTimeSubsystem.h"
void UThreadTimeSubsystem::Initialize(FSubsystemCollectionBase& C)
{
    Super::Initialize(C);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadTime] Subsystem Initialized."));
}
void UThreadTimeSubsystem::Deinitialize() { Super::Deinitialize(); }
FDateTime UThreadTimeSubsystem::GetRealWorldTime() const
{
    return FDateTime::Now();
}
FString UThreadTimeSubsystem::GetFormattedThreadTime() const
{
    return FDateTime::Now().ToString(TEXT("%Y-%m-%d %H:%M:%S"));
}
