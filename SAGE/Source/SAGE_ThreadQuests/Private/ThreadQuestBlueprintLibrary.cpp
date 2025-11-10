// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Blueprint API Impl)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadQuestBlueprintLibrary.h"
#include "ThreadQuestSubsystem.h"
#include "ThreadQuestAsset.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

static UThreadQuestSubsystem* GetQuestSys(const UObject* WorldContext)
{
    if (!WorldContext) return nullptr;
    if (const UWorld* W = WorldContext->GetWorld())
    {
        if (UGameInstance* GI = W->GetGameInstance())
        {
            return GI->GetSubsystem<UThreadQuestSubsystem>();
        }
    }
    return nullptr;
}

bool UThreadQuestBlueprintLibrary::StartQuest(const UObject* WorldContext, UThreadQuestAsset* QuestDef)
{
    if (UThreadQuestSubsystem* Sys = GetQuestSys(WorldContext))
    {
        return Sys->StartQuest(QuestDef);
    }
    return false;
}

bool UThreadQuestBlueprintLibrary::CompleteObjective(const UObject* WorldContext, FThreadQuestID QuestId, FName ObjectiveId, bool bCompleted)
{
    if (UThreadQuestSubsystem* Sys = GetQuestSys(WorldContext))
    {
        return Sys->SetObjectiveComplete(QuestId, ObjectiveId, bCompleted);
    }
    return false;
}

bool UThreadQuestBlueprintLibrary::CompleteQuest(const UObject* WorldContext, FThreadQuestID QuestId)
{
    if (UThreadQuestSubsystem* Sys = GetQuestSys(WorldContext))
    {
        return Sys->CompleteQuest(QuestId);
    }
    return false;
}

bool UThreadQuestBlueprintLibrary::FailQuest(const UObject* WorldContext, FThreadQuestID QuestId)
{
    if (UThreadQuestSubsystem* Sys = GetQuestSys(WorldContext))
    {
        return Sys->FailQuest(QuestId);
    }
    return false;
}
