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
#include "GameplayTagContainer.h"
#include "Sound/SoundBase.h"
#include "ThreadDialogueTypes.generated.h"

UENUM(BlueprintType)
enum class EThreadSpeechMode : uint8
{
    Normal,
    Whisper,
    Shout,
};

USTRUCT(BlueprintType)
struct SAGE_THREADDIALOGUE_API FThreadDialogueLine
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Text = FText::GetEmpty();

    // Optional: tag to identify the speaker (Player, NPC.Blacksmith, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag SpeakerTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USoundBase> Voice;

    // Seconds to auto-advance after showing this line (<=0 means wait)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AutoAdvanceAfter = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EThreadSpeechMode SpeechMode = EThreadSpeechMode::Normal;
};

USTRUCT(BlueprintType)
struct SAGE_THREADDIALOGUE_API FThreadDialogueChoice
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Label = FText::FromString(TEXT("..."));

    // Name of the node to jump to if this choice is selected
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName NextNode;
};

USTRUCT(BlueprintType)
struct SAGE_THREADDIALOGUE_API FThreadDialogueNode
{
    GENERATED_BODY()

    // One or more lines (monologue or back-and-forth inside node)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FThreadDialogueLine> Lines;

    // Choices at the end of the node (empty = linear)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FThreadDialogueChoice> Choices;

    // Fallback next node if there are no choices (or after choice resolves)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName NextNode;

    // Optional requirements for this node to be valid (tags, states)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTagContainer Requirements;
};
