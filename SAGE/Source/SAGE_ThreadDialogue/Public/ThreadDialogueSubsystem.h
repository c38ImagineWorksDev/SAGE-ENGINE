// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadDialogue
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ThreadDialogueTypes.h"
#include "ThreadDialogueSubsystem.generated.h"

class UThreadDialogueAsset;
class UThreadDialogueSettings;

DECLARE_LOG_CATEGORY_EXTERN(LogThreadDialogue, Log, All);

// UI signals
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDialogueLine, FGameplayTag, Speaker, FText, Text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDialogueChoices, const TArray<FThreadDialogueChoice>&, Choices);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogueEnded);

UCLASS(BlueprintType)
class SAGE_THREADDIALOGUE_API UThreadDialogueSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintPure, Category = "SAGE|Dialogue", meta = (WorldContext = "WorldContext"))
    static UThreadDialogueSubsystem* Get(const UObject* WorldContext);

    // Start a conversation at a specific node (or asset’s StartNode if none)
    UFUNCTION(BlueprintCallable, Category = "SAGE|Dialogue")
    bool StartDialogue(UThreadDialogueAsset* Asset, FName Node = NAME_None);

    // Advance within current node (next line, then choices/next node)
    UFUNCTION(BlueprintCallable, Category = "SAGE|Dialogue")
    void Advance();

    // Choose a branch by index when choices are shown
    UFUNCTION(BlueprintCallable, Category = "SAGE|Dialogue")
    void Choose(int32 ChoiceIndex);

    UFUNCTION(BlueprintPure, Category = "SAGE|Dialogue")
    bool IsActive() const { return ActiveAsset != nullptr; }

    // HUD/UI events to bind in BP widgets
    UPROPERTY(BlueprintAssignable, Category = "SAGE|Dialogue")
    FOnDialogueLine OnLine;

    UPROPERTY(BlueprintAssignable, Category = "SAGE|Dialogue")
    FOnDialogueChoices OnChoices;

    UPROPERTY(BlueprintAssignable, Category = "SAGE|Dialogue")
    FOnDialogueEnded OnEnded;

private:
    UPROPERTY()
    UThreadDialogueSettings* Settings = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UThreadDialogueAsset> ActiveAsset = nullptr;

    UPROPERTY(Transient)
    FName CurrentNode = NAME_None;

    int32 LineIndex = 0;
    FTimerHandle AutoAdvanceHandle;

    bool TryShowLine();
    void ShowChoicesOrAdvance();
    void ClearAutoAdvance();
};
