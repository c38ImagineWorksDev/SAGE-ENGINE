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
#include "UObject/Interface.h"
#include "ThreadAITypes.h"
#include "ThreadAIActorInterface.generated.h"

UINTERFACE(Blueprintable)
class SAGE_THREADAI_API UThreadAIActorInterface : public UInterface
{
    GENERATED_BODY()
};

/** Implement on Pawns/Controllers that should react to ThreadAI stimuli. */
class SAGE_THREADAI_API IThreadAIActorInterface
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SAGE|AI")
    void OnThreadStimulus(const FThreadAIStimulus& Stimulus);

    /** Optional: provide a per-actor profile override. Return true if set. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SAGE|AI")
    bool GetThreadAIProfile(FThreadAIProfile& OutProfile) const;
};
