// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadLore
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadLoreTypes.h"
#include "ThreadLoreSubsystem.generated.h"

UCLASS()
class SAGE_THREADLORE_API UThreadLoreSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    virtual void Initialize(FSubsystemCollectionBase& C) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadLore")
    void Remember(FString Key, FString Value);

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadLore")
    FString Recall(FString Key) const;

private:
    UPROPERTY() TMap<FString, FString> LoreMemory;
};
