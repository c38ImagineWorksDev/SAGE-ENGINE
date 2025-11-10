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
#include "Engine/DataAsset.h"
#include "ThreadDialogueTypes.h"
#include "ThreadDialogueAsset.generated.h"

UCLASS(BlueprintType)
class SAGE_THREADDIALOGUE_API UThreadDialogueAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName StartNode = NAME_None;

    // Node name -> node data
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FName, FThreadDialogueNode> Nodes;
};
