// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Blueprint API)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadQuestTypes.h"
#include "ThreadQuestBlueprintLibrary.generated.h"

class UThreadQuestAsset;
class UThreadQuestSubsystem;

UCLASS()
class SAGE_THREADQUESTS_API UThreadQuestBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "Quest", meta = (WorldContext = "WorldContext"))
    static bool StartQuest(const UObject* WorldContext, UThreadQuestAsset* QuestDef);

    UFUNCTION(BlueprintCallable, Category = "Quest", meta = (WorldContext = "WorldContext"))
    static bool CompleteObjective(const UObject* WorldContext, FThreadQuestID QuestId, FName ObjectiveId, bool bCompleted = true);

    UFUNCTION(BlueprintCallable, Category = "Quest", meta = (WorldContext = "WorldContext"))
    static bool CompleteQuest(const UObject* WorldContext, FThreadQuestID QuestId);

    UFUNCTION(BlueprintCallable, Category = "Quest", meta = (WorldContext = "WorldContext"))
    static bool FailQuest(const UObject* WorldContext, FThreadQuestID QuestId);
};
