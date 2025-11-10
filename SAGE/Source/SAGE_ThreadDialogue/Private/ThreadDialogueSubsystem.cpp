// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadDialogue
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadDialogueSubsystem.h"
#include "ThreadDialogueAsset.h"
#include "ThreadDialogueSettings.h"

#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY(LogThreadDialogue);

void UThreadDialogueSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Settings = GetMutableDefault<UThreadDialogueSettings>();
    UE_LOG(LogThreadDialogue, Log, TEXT("[Dialogue] Init"));
}

void UThreadDialogueSubsystem::Deinitialize()
{
    ClearAutoAdvance();
    ActiveAsset = nullptr;
    Super::Deinitialize();
}

UThreadDialogueSubsystem* UThreadDialogueSubsystem::Get(const UObject* WorldContext)
{
    if (!WorldContext) return nullptr;
    if (const UWorld* World = WorldContext->GetWorld())
    {
        return World->GetSubsystem<UThreadDialogueSubsystem>();
    }
    return nullptr;
}

bool UThreadDialogueSubsystem::StartDialogue(UThreadDialogueAsset* Asset, FName Node /*=NAME_None*/)
{
    ClearAutoAdvance();

    if (!Asset)
    {
        UE_LOG(LogThreadDialogue, Warning, TEXT("[Dialogue] StartDialogue: Missing asset"));
        return false;
    }

    ActiveAsset = Asset;
    CurrentNode = (Node.IsNone() ? Asset->StartNode : Node);
    LineIndex = 0;

    UE_LOG(LogThreadDialogue, Log, TEXT("[Dialogue] Start '%s' @ Node '%s'"),
        *Asset->GetName(), *CurrentNode.ToString());

    return TryShowLine();
}

void UThreadDialogueSubsystem::Advance()
{
    if (!ActiveAsset) return;

    ClearAutoAdvance();
    const FThreadDialogueNode* Node = ActiveAsset->Nodes.Find(CurrentNode);
    if (!Node)
    {
        UE_LOG(LogThreadDialogue, Warning, TEXT("[Dialogue] Advance: Missing node '%s'"), *CurrentNode.ToString());
        OnEnded.Broadcast();
        ActiveAsset = nullptr;
        return;
    }

    // Next line in this node?
    if (++LineIndex < Node->Lines.Num())
    {
        TryShowLine();
        return;
    }

    // End of lines: show choices or follow NextNode
    ShowChoicesOrAdvance();
}

void UThreadDialogueSubsystem::Choose(int32 ChoiceIndex)
{
    if (!ActiveAsset) return;

    ClearAutoAdvance();
    const FThreadDialogueNode* Node = ActiveAsset->Nodes.Find(CurrentNode);
    if (!Node || Node->Choices.Num() == 0)
    {
        UE_LOG(LogThreadDialogue, Warning, TEXT("[Dialogue] Choose: No choices at node '%s'"), *CurrentNode.ToString());
        return;
    }

    if (!Node->Choices.IsValidIndex(ChoiceIndex))
    {
        UE_LOG(LogThreadDialogue, Warning, TEXT("[Dialogue] Choose: Invalid index %d"), ChoiceIndex);
        return;
    }

    CurrentNode = Node->Choices[ChoiceIndex].NextNode;
    LineIndex = 0;
    TryShowLine();
}

bool UThreadDialogueSubsystem::TryShowLine()
{
    if (!ActiveAsset) return false;

    const FThreadDialogueNode* Node = ActiveAsset->Nodes.Find(CurrentNode);
    if (!Node)
    {
        UE_LOG(LogThreadDialogue, Warning, TEXT("[Dialogue] TryShowLine: Missing node '%s'"), *CurrentNode.ToString());
        OnEnded.Broadcast();
        ActiveAsset = nullptr;
        return false;
    }

    if (!Node->Lines.IsValidIndex(LineIndex))
    {
        ShowChoicesOrAdvance();
        return true;
    }

    const FThreadDialogueLine& Line = Node->Lines[LineIndex];

    // Emit UI signal (speaker tag + text)
    OnLine.Broadcast(Line.SpeakerTag, Line.Text);

    // Auto advance?
    float Delay = Line.AutoAdvanceAfter;
    if (Delay <= 0.f) { Delay = Settings ? Settings->DefaultAutoAdvance : 0.f; }

    if (Delay > 0.f)
    {
        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().SetTimer(
                AutoAdvanceHandle,
                this, &UThreadDialogueSubsystem::Advance,
                Delay, false
            );
        }
    }

    return true;
}

void UThreadDialogueSubsystem::ShowChoicesOrAdvance()
{
    const FThreadDialogueNode* Node = ActiveAsset ? ActiveAsset->Nodes.Find(CurrentNode) : nullptr;
    if (!Node)
    {
        OnEnded.Broadcast();
        ActiveAsset = nullptr;
        return;
    }

    if (Node->Choices.Num() > 0)
    {
        OnChoices.Broadcast(Node->Choices);
        return;
    }

    if (Node->NextNode.IsNone())
    {
        UE_LOG(LogThreadDialogue, Log, TEXT("[Dialogue] Ended at '%s'"), *CurrentNode.ToString());
        OnEnded.Broadcast();
        ActiveAsset = nullptr;
        return;
    }

    // Linear progression
    CurrentNode = Node->NextNode;
    LineIndex = 0;
    TryShowLine();
}

void UThreadDialogueSubsystem::ClearAutoAdvance()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(AutoAdvanceHandle);
    }
}
