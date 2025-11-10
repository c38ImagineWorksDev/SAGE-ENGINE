// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadAITypes.h"
#include "ThreadAIBlueprintLibrary.generated.h"

UCLASS()
class SAGE_THREADAI_API UThreadAIBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "SAGE|AI", meta = (WorldContext = "WorldContext"))
    static void ThreadAI_EmitSimpleStimulus(const UObject* WorldContext, AActor* Source, AActor* Target, EThreadAIIntent Intent);

    UFUNCTION(BlueprintCallable, Category = "SAGE|AI", meta = (WorldContext = "WorldContext"))
    static void ThreadAI_EmitStimulus(const UObject* WorldContext, const FThreadAIStimulus& Stimulus);

    /** Get all registered AI agents (BP-safe). */
    UFUNCTION(BlueprintCallable, Category = "SAGE|AI", meta = (WorldContext = "WorldContext"))
    static void ThreadAI_GetAgents(const UObject* WorldContext, TArray<AActor*>& OutAgents);
};
