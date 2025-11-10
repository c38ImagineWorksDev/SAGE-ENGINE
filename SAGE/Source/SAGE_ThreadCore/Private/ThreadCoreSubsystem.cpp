/*
 * ============================================================
 * 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
 *  “Born from Making Reality from Your Imagination.”
 * ============================================================
 * Module: SAGE_ThreadCore
 * Version: 0.1.0 – The Thread Awakens
 * Author: C38 ImagineWorks LLC
 * Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
 */


#include "ThreadCoreSubsystem.h"
#include "Engine/Engine.h"

void UThreadCoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCore] Subsystem Initialized."));
}

void UThreadCoreSubsystem::Deinitialize()
{
    Super::Deinitialize();
    RegisteredModules.Empty();
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCore] Subsystem Deinitialized."));
}

void UThreadCoreSubsystem::RegisterModule(FName ModuleName)
{
    if (!IsModuleRegistered(ModuleName))
    {
        RegisteredModules.Add(FRegisteredThreadModule(ModuleName, true));
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCore] Registered module: %s"), *ModuleName.ToString());
    }
}

void UThreadCoreSubsystem::UnregisterModule(FName ModuleName)
{
    for (FRegisteredThreadModule& Mod : RegisteredModules)
    {
        if (Mod.ModuleName == ModuleName)
        {
            Mod.bIsActive = false;
            UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadCore] Unregistered module: %s"), *ModuleName.ToString());
            break;
        }
    }
}

bool UThreadCoreSubsystem::IsModuleRegistered(FName ModuleName) const
{
    for (const FRegisteredThreadModule& Mod : RegisteredModules)
    {
        if (Mod.ModuleName == ModuleName && Mod.bIsActive)
        {
            return true;
        }
    }
    return false;
}

void UThreadCoreSubsystem::PrintRegisteredModules() const
{
    UE_LOG(LogTemp, Log, TEXT("=== [SAGE ThreadCore Active Modules] ==="));
    for (const FRegisteredThreadModule& Mod : RegisteredModules)
    {
        FString State = Mod.bIsActive ? TEXT("Active") : TEXT("Inactive");
        UE_LOG(LogTemp, Log, TEXT(" - %s (%s)"), *Mod.ModuleName.ToString(), *State);
    }
    UE_LOG(LogTemp, Log, TEXT("======================================="));
}

FRegisteredThreadModule* UThreadCoreSubsystem::FindModule(FName ModuleName)
{
    for (FRegisteredThreadModule& Mod : RegisteredModules)
    {
        if (Mod.ModuleName == ModuleName)
        {
            return &Mod;
        }
    }
    return nullptr;
}
