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
#include "Subsystems/WorldSubsystem.h"
#include "ThreadAITypes.h"
#include "ThreadAISubsystem.generated.h"

class UThreadAISettings;

DECLARE_LOG_CATEGORY_EXTERN(LogThreadAI, Log, All);

/**
 * World-level manager:
 *  - Tracks agents (weak refs)
 *  - Broadcasts stimuli
 *  - Bridges to Sense/Print/Lore for bias in your BT/Tasks
 */
UCLASS(BlueprintType)
class SAGE_THREADAI_API UThreadAISubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    // === UWorldSubsystem ===
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    // === Registration (C++/BP) ===
    UFUNCTION(BlueprintCallable, Category = "SAGE|AI")
    void RegisterAgent(AActor* Agent);

    UFUNCTION(BlueprintCallable, Category = "SAGE|AI")
    void UnregisterAgent(AActor* Agent);

    /** C++ only: raw agent pool (BP can't use TWeakObjectPtr) */
    const TArray<TWeakObjectPtr<AActor>>& GetAgentsRaw() const { return Agents; }

    /** BP-friendly list of current live agents */
    UFUNCTION(BlueprintPure, Category = "SAGE|AI")
    void GetAgentList(TArray<AActor*>& OutAgents) const;

    UFUNCTION(BlueprintPure, Category = "SAGE|AI")
    bool IsRegistered(AActor* Agent) const;

    // === Stimuli ===
    UFUNCTION(BlueprintCallable, Category = "SAGE|AI")
    void EmitStimulus(const FThreadAIStimulus& Stimulus);

    UFUNCTION(BlueprintCallable, Category = "SAGE|AI")
    void EmitSimpleStimulus(AActor* Source, AActor* Target, EThreadAIIntent Intent);

    // Convenience getter
    UFUNCTION(BlueprintPure, Category = "SAGE|AI", meta = (WorldContext = "WorldContext"))
    static UThreadAISubsystem* Get(const UObject* WorldContext);

private:
    UPROPERTY()
    UThreadAISettings* CachedSettings = nullptr;

    /** Weak pool so we don't fight GC. */
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<AActor>> Agents;

    bool CompactAgents();
};
