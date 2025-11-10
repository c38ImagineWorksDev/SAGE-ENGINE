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
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadDialogueBlueprintLibrary.generated.h"

class UThreadDialogueAsset;
class UThreadDialogueSubsystem;

UCLASS()
class SAGE_THREADDIALOGUE_API UThreadDialogueBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SAGE|Dialogue", meta = (WorldContext = "WorldContext"))
    static bool Dialogue_Start(const UObject* WorldContext, UThreadDialogueAsset* Asset, FName StartNode);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Dialogue", meta = (WorldContext = "WorldContext"))
    static void Dialogue_Advance(const UObject* WorldContext);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Dialogue", meta = (WorldContext = "WorldContext"))
    static void Dialogue_Choose(const UObject* WorldContext, int32 ChoiceIndex);
};
