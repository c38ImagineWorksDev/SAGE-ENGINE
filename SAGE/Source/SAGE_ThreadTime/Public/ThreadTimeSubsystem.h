// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadTime
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadTimeSubsystem.generated.h"

UCLASS()
class SAGE_THREADTIME_API UThreadTimeSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    virtual void Initialize(FSubsystemCollectionBase& C) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadTime")
    FDateTime GetRealWorldTime() const;

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadTime")
    FString GetFormattedThreadTime() const;
};
