// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadNetwork
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadNetworkSubsystem.h"
#include "Engine/Engine.h"

void UThreadNetworkSubsystem::Initialize(FSubsystemCollectionBase& C)
{
    Super::Initialize(C);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadNetwork] Subsystem Initialized."));
}

void UThreadNetworkSubsystem::Deinitialize()
{
    Super::Deinitialize();
}

void UThreadNetworkSubsystem::BroadcastPresence(const FString& PlayerName)
{
    UE_LOG(LogTemp, Log, TEXT("[Network] %s is present in the Thread."), *PlayerName);
}
