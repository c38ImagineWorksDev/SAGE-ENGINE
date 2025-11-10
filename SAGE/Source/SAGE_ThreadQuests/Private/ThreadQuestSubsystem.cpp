// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadQuests (Subsystem Impl)
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadQuestSubsystem.h"
#include "ThreadQuestAsset.h"
#include "Engine/Engine.h"

void UThreadQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
}

void UThreadQuestSubsystem::Deinitialize()
{
    Super::Deinitialize();
}

EThreadQuestState UThreadQuestSubsystem::GetQuestState(FThreadQuestID QuestId) const
{
    if (const FThreadQuestProgress* P = Progress.Find(QuestId.Id))
    {
        return P->State;
    }
    return EThreadQuestState::NotStarted;
}

bool UThreadQuestSubsystem::GetQuestProgress(FThreadQuestID QuestId, FThreadQuestProgress& OutProgress) const
{
    if (const FThreadQuestProgress* P = Progress.Find(QuestId.Id))
    {
        OutProgress = *P;
        return true;
    }
    return false;
}

bool UThreadQuestSubsystem::IsObjectiveComplete(FThreadQuestID QuestId, FName ObjectiveId) const
{
    if (const FThreadQuestProgress* P = Progress.Find(QuestId.Id))
    {
        if (const bool* b = P->ObjectiveState.Find(ObjectiveId))
        {
            return *b;
        }
    }
    return false;
}

bool UThreadQuestSubsystem::StartQuest(UThreadQuestAsset* QuestDef)
{
    if (!QuestDef || !QuestDef->QuestId.IsValid()) return false;

    FThreadQuestProgress& P = Progress.FindOrAdd(QuestDef->QuestId.Id);
    if (P.State == EThreadQuestState::Active || P.State == EThreadQuestState::Completed) return false;

    P.State = EThreadQuestState::Active;
    P.CurrentStageId = QuestDef->StartStageId;

    EnsureStageInit(QuestDef, P);

    OnQuestStateChanged.Broadcast(QuestDef->QuestId, P.State);

    const FThreadQuestStage* Stage = QuestDef->FindStage(P.CurrentStageId);
    if (Stage)
    {
        OnQuestStageChanged.Broadcast(QuestDef->QuestId, P.CurrentStageId, *Stage);
    }
    return true;
}

bool UThreadQuestSubsystem::SetObjectiveComplete(FThreadQuestID QuestId, FName ObjectiveId, bool bCompleted)
{
    if (FThreadQuestProgress* P = Progress.Find(QuestId.Id))
    {
        P->ObjectiveState.FindOrAdd(ObjectiveId) = bCompleted;
        OnQuestObjectiveToggled.Broadcast(QuestId, ObjectiveId, bCompleted);
        return true;
    }
    return false;
}

bool UThreadQuestSubsystem::AdvanceStage(FThreadQuestID /*QuestId*/)
{
    // Kept for API completeness; not used in this pass.
    return true;
}

bool UThreadQuestSubsystem::AdvanceToStage(UThreadQuestAsset* QuestDef, FName NewStageId)
{
    if (!QuestDef || !QuestDef->QuestId.IsValid()) return false;

    FThreadQuestProgress* P = Progress.Find(QuestDef->QuestId.Id);
    if (!P) return false;

    P->CurrentStageId = NewStageId;
    P->ObjectiveState.Reset();

    const FThreadQuestStage* Stage = QuestDef->FindStage(NewStageId);
    if (!Stage) return false;

    // Seed objectives for the new stage
    for (const FThreadQuestObjective& Obj : Stage->Objectives)
    {
        P->ObjectiveState.FindOrAdd(Obj.ObjectiveId) = false;
    }

    OnQuestStageChanged.Broadcast(QuestDef->QuestId, NewStageId, *Stage);
    return true;
}

bool UThreadQuestSubsystem::CompleteQuest(FThreadQuestID QuestId)
{
    if (FThreadQuestProgress* P = Progress.Find(QuestId.Id))
    {
        P->State = EThreadQuestState::Completed;
        OnQuestStateChanged.Broadcast(QuestId, P->State);
        return true;
    }
    return false;
}

bool UThreadQuestSubsystem::FailQuest(FThreadQuestID QuestId)
{
    if (FThreadQuestProgress* P = Progress.Find(QuestId.Id))
    {
        P->State = EThreadQuestState::Failed;
        OnQuestStateChanged.Broadcast(QuestId, P->State);
        return true;
    }
    return false;
}

bool UThreadQuestSubsystem::EnsureStageInit(const UThreadQuestAsset* Def, FThreadQuestProgress& InOut)
{
    if (!Def) return false;
    const FThreadQuestStage* Stage = Def->FindStage(InOut.CurrentStageId);
    if (!Stage) return false;

    for (const FThreadQuestObjective& Obj : Stage->Objectives)
    {
        InOut.ObjectiveState.FindOrAdd(Obj.ObjectiveId) = false;
    }
    return true;
}
