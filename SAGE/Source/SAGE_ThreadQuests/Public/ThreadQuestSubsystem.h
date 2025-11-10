// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Subsystem)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadQuestTypes.h"
#include "ThreadQuestSubsystem.generated.h"

class UThreadQuestAsset;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestStateChanged, FThreadQuestID, QuestId, EThreadQuestState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestStageChanged, FThreadQuestID, QuestId, FName, NewStageId, const FThreadQuestStage&, StageData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestObjectiveToggled, FThreadQuestID, QuestId, FName, ObjectiveId, bool, bCompleted);

UCLASS(BlueprintType)
class SAGE_THREADQUESTS_API UThreadQuestSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    // Begin Subsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    // End Subsystem

    UPROPERTY(BlueprintAssignable, Category = "Quest|Events")
    FOnQuestStateChanged OnQuestStateChanged;

    UPROPERTY(BlueprintAssignable, Category = "Quest|Events")
    FOnQuestStageChanged OnQuestStageChanged;

    UPROPERTY(BlueprintAssignable, Category = "Quest|Events")
    FOnQuestObjectiveToggled OnQuestObjectiveToggled;

    // --- Query ---
    UFUNCTION(BlueprintPure, Category = "Quest")
    EThreadQuestState GetQuestState(FThreadQuestID QuestId) const;

    UFUNCTION(BlueprintPure, Category = "Quest")
    bool GetQuestProgress(FThreadQuestID QuestId, FThreadQuestProgress& OutProgress) const;

    UFUNCTION(BlueprintPure, Category = "Quest")
    bool IsObjectiveComplete(FThreadQuestID QuestId, FName ObjectiveId) const;

    // --- Control ---
    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool StartQuest(UThreadQuestAsset* QuestDef);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool SetObjectiveComplete(FThreadQuestID QuestId, FName ObjectiveId, bool bCompleted);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool AdvanceStage(FThreadQuestID QuestId); // bookkeeping only (optional)

    // New: authoritative stage advance API
    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool AdvanceToStage(UThreadQuestAsset* QuestDef, FName NewStageId);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool CompleteQuest(FThreadQuestID QuestId);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool FailQuest(FThreadQuestID QuestId);

    // --- Save/Load (simple key-value) ---
    UFUNCTION(BlueprintCallable, Category = "Quest|Save")
    void GetAllProgress(TMap<FName, FThreadQuestProgress>& OutAll) const { OutAll = Progress; }

    UFUNCTION(BlueprintCallable, Category = "Quest|Save")
    void SetAllProgress(const TMap<FName, FThreadQuestProgress>& InAll) { Progress = InAll; }

private:
    // QuestId -> progress
    UPROPERTY()
    TMap<FName, FThreadQuestProgress> Progress;

    bool EnsureStageInit(const UThreadQuestAsset* Def, FThreadQuestProgress& InOut);
};
