// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Asset)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ThreadQuestTypes.h"
#include "ThreadQuestAsset.generated.h"

UCLASS(BlueprintType)
class SAGE_THREADQUESTS_API UThreadQuestAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    // Unique quest id (must be stable)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
    FThreadQuestID QuestId;

    // Display info
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
    FText Summary;

    // Authoring stages
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
    TArray<FThreadQuestStage> Stages;

    // Initial stage
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
    FName StartStageId = NAME_None;

    // Lookup
    const FThreadQuestStage* FindStage(FName StageId) const
    {
        for (const FThreadQuestStage& S : Stages)
        {
            if (S.StageId == StageId) return &S;
        }
        return nullptr;
    }
};
