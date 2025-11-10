// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadPlayer
// Version: 0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadPlayerSubsystem.h"
#include "ThreadDataSubsystem.h"
#include "Engine/Engine.h"
#include "JsonObjectConverter.h"

void UThreadPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPlayer] Initialized for Player ID: %s"), *Signature.PlayerID);
}

void UThreadPlayerSubsystem::Deinitialize()
{
    SavePlayerState();
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPlayer] Deinitialized and state saved."));
}

void UThreadPlayerSubsystem::ModifyHealth(float Amount)
{
    PlayerStats.Health = FMath::Clamp(PlayerStats.Health + Amount, 0.f, 100.f);
    UE_LOG(LogTemp, Log, TEXT("[Player] Health modified to: %.2f"), PlayerStats.Health);
}

void UThreadPlayerSubsystem::SavePlayerState()
{
    if (UGameInstance* GI = GetGameInstance())
    {
        if (UThreadDataSubsystem* Data = GI->GetSubsystem<UThreadDataSubsystem>())
        {
            FString SaveData;
            FJsonObjectConverter::UStructToJsonObjectString(PlayerStats, SaveData);
            Data->SaveStringToFile(SaveData, TEXT("PlayerState.json"));
        }
    }
}

void UThreadPlayerSubsystem::LoadPlayerState()
{
    if (UGameInstance* GI = GetGameInstance())
    {
        if (UThreadDataSubsystem* Data = GI->GetSubsystem<UThreadDataSubsystem>())
        {
            FString LoadedData = Data->LoadStringFromFile(TEXT("PlayerState.json"));
            FJsonObjectConverter::JsonObjectStringToUStruct(LoadedData, &PlayerStats);
            UE_LOG(LogTemp, Log, TEXT("[Player] State loaded: Health=%.2f, Stamina=%.2f, Mana=%.2f"),
                PlayerStats.Health, PlayerStats.Stamina, PlayerStats.Mana);
        }
    }
}
