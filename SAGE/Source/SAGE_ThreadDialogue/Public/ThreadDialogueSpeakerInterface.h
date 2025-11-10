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
#include "UObject/Interface.h"
#include "ThreadDialogueSpeakerInterface.generated.h"

UINTERFACE(BlueprintType, MinimalAPI)
class UThreadDialogueSpeakerInterface : public UInterface
{
    GENERATED_BODY()
};

class SAGE_THREADDIALOGUE_API IThreadDialogueSpeakerInterface
{
    GENERATED_BODY()
public:
    // Give UI a display name for the current speaker (can be dynamic)
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SAGE|Dialogue")
    FText GetSpeakerDisplayName() const;
};
