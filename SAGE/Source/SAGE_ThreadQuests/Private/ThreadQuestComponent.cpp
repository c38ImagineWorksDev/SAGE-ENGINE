// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Component Impl)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadQuestComponent.h"
#include "ThreadQuestSubsystem.h"
#include "ThreadQuestAsset.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UThreadQuestSubsystem* UThreadQuestComponent::GetSys() const
{
    if (const UWorld* W = GetWorld())
    {
        if (UGameInstance* GI = W->GetGameInstance())
        {
            return GI->GetSubsystem<UThreadQuestSubsystem>();
        }
    }
    return nullptr;
}

FThreadQuestID UThreadQuestComponent::GetQuestId() const
{
    return (QuestDefinition) ? QuestDefinition->QuestId : FThreadQuestID{};
}

bool UThreadQuestComponent::OfferQuestToPlayer()
{
    if (!QuestDefinition) return false;
    if (UThreadQuestSubsystem* Sys = GetSys())
    {
        return Sys->StartQuest(QuestDefinition);
    }
    return false;
}

bool UThreadQuestComponent::CompleteObjective(FName ObjectiveId, bool bCompleted)
{
    if (!QuestDefinition) return false;
    if (UThreadQuestSubsystem* Sys = GetSys())
    {
        return Sys->SetObjectiveComplete(QuestDefinition->QuestId, ObjectiveId, bCompleted);
    }
    return false;
}

bool UThreadQuestComponent::AdvanceOrComplete()
{
    if (!QuestDefinition) return false;
    if (UThreadQuestSubsystem* Sys = GetSys())
    {
        FThreadQuestProgress P;
        if (!Sys->GetQuestProgress(QuestDefinition->QuestId, P)) return false;

        const FThreadQuestStage* Stage = QuestDefinition->FindStage(P.CurrentStageId);
        if (!Stage) return false;

        // Check if all non-optional objectives complete
        bool bAll = true;
        for (const FThreadQuestObjective& Obj : Stage->Objectives)
        {
            if (Obj.bOptional) continue;
            if (!Sys->IsObjectiveComplete(QuestDefinition->QuestId, Obj.ObjectiveId))
            {
                bAll = false; break;
            }
        }

        if (!bAll) return false;

        if (Stage->NextStageId == NAME_None)
        {
            return Sys->CompleteQuest(QuestDefinition->QuestId);
        }
        else
        {
            // Use the subsystem’s authoritative API now
            return Sys->AdvanceToStage(QuestDefinition, Stage->NextStageId);
        }
    }
    return false;
}
