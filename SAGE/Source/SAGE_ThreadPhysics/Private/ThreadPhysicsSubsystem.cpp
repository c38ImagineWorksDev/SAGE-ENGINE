// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadPhysics
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadPhysicsSubsystem.h"
void UThreadPhysicsSubsystem::Initialize(FSubsystemCollectionBase& C)
{
    Super::Initialize(C);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPhysics] Subsystem Initialized."));
}
void UThreadPhysicsSubsystem::Deinitialize() { Super::Deinitialize(); }
void UThreadPhysicsSubsystem::RegisterImpact(const FString& A, const FString& B, float F)
{
    UE_LOG(LogTemp, Log, TEXT("[Physics] %s impacted %s with %.2f force."), *A, *B, F);
}
