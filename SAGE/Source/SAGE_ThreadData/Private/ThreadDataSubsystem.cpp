// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadData
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadDataSubsystem.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UThreadDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadData] Subsystem Initialized."));
}

void UThreadDataSubsystem::Deinitialize()
{
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadData] Subsystem Deinitialized."));
}

void UThreadDataSubsystem::SaveStringToFile(const FString& Data, const FString& FileName)
{
    const FString FullPath = FPaths::ProjectSavedDir() / FileName;

    if (FFileHelper::SaveStringToFile(Data, *FullPath))
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadData] File saved successfully: %s"), *FullPath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[SAGE_ThreadData] Failed to save file: %s"), *FullPath);
    }
}

FString UThreadDataSubsystem::LoadStringFromFile(const FString& FileName) const
{
    const FString FullPath = FPaths::ProjectSavedDir() / FileName;
    FString LoadedData;

    if (FFileHelper::LoadFileToString(LoadedData, *FullPath))
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadData] File loaded successfully: %s"), *FullPath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[SAGE_ThreadData] Failed to load file: %s"), *FullPath);
    }

    return LoadedData;
}
