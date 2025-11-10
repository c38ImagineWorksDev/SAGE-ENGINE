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


#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadCoreTypes.h"
#include "ThreadCoreSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FRegisteredThreadModule
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "SAGE|ThreadCore")
    FName ModuleName;

    UPROPERTY(BlueprintReadOnly, Category = "SAGE|ThreadCore")
    bool bIsActive;

    FRegisteredThreadModule()
        : ModuleName(NAME_None), bIsActive(false)
    {
    }

    FRegisteredThreadModule(FName InName, bool bInActive)
        : ModuleName(InName), bIsActive(bInActive)
    {
    }
};

/**
 * The central registry and communication hub for all SAGE modules.
 */
UCLASS()
class SAGE_THREADCORE_API UThreadCoreSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    /** Registers a module with ThreadCore */
    void RegisterModule(FName ModuleName);

    /** Unregisters a module */
    void UnregisterModule(FName ModuleName);

    /** Checks if a module is registered */
    bool IsModuleRegistered(FName ModuleName) const;

    /** Prints the list of registered modules to the log */
    void PrintRegisteredModules() const;

private:
    /** Active module registry */
    UPROPERTY()
    TArray<FRegisteredThreadModule> RegisteredModules;

    /** Helper function to find module by name */
    FRegisteredThreadModule* FindModule(FName ModuleName);
};
