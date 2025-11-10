// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Types)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once

#include "CoreMinimal.h"
#include "ThreadQuestTypes.generated.h"

UENUM(BlueprintType)
enum class EThreadQuestState : uint8
{
    NotStarted UMETA(DisplayName = "Not Started"),
    Active     UMETA(DisplayName = "Active"),
    Completed  UMETA(DisplayName = "Completed"),
    Failed     UMETA(DisplayName = "Failed")
};

USTRUCT(BlueprintType)
struct FThreadQuestID
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FName Id = NAME_None;

    bool IsValid() const { return Id != NAME_None; }
    bool operator==(const FThreadQuestID& Other) const { return Id == Other.Id; }
    friend uint32 GetTypeHash(const FThreadQuestID& V) { return GetTypeHash(V.Id); }
};

USTRUCT(BlueprintType)
struct FThreadQuestObjective
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FName ObjectiveId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    bool bOptional = false;
};

USTRUCT(BlueprintType)
struct FThreadQuestStage
{
    GENERATED_BODY()

    // Stage key
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FName StageId = NAME_None;

    // Narrative text for UI
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TArray<FThreadQuestObjective> Objectives;

    // Next stage on success (NAME_None ends quest as Completed)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FName NextStageId = NAME_None;

    // If set, advances automatically on reaching this stage
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    bool bAutoAdvanceWhenAllObjectivesComplete = true;
};

USTRUCT(BlueprintType)
struct FThreadQuestProgress
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    EThreadQuestState State = EThreadQuestState::NotStarted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FName CurrentStageId = NAME_None;

    // ObjectiveId -> completed?
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TMap<FName, bool> ObjectiveState;
};
