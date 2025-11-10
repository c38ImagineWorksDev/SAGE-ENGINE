// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadSense
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadSenseSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FThreadSensePing
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite) FString Source;
    UPROPERTY(BlueprintReadWrite) FString Target;
    UPROPERTY(BlueprintReadWrite) float Intensity;
};

UCLASS()
class SAGE_THREADSENSE_API UThreadSenseSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    virtual void Initialize(FSubsystemCollectionBase& C) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadSense")
    void EmitPing(const FString& Source, const FString& Target, float Intensity);
};
