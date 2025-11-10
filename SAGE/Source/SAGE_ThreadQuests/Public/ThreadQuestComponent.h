// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Component)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ThreadQuestTypes.h"
#include "ThreadQuestComponent.generated.h"

class UThreadQuestAsset;
class UThreadQuestSubsystem;

UCLASS(ClassGroup = (SAGE), meta = (BlueprintSpawnableComponent))
class SAGE_THREADQUESTS_API UThreadQuestComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
    UThreadQuestAsset* QuestDefinition = nullptr;

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool OfferQuestToPlayer();

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool CompleteObjective(FName ObjectiveId, bool bCompleted = true);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    bool AdvanceOrComplete();

    UFUNCTION(BlueprintPure, Category = "Quest")
    FThreadQuestID GetQuestId() const;

private:
    UThreadQuestSubsystem* GetSys() const;
};
