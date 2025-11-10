// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadCinematicsTypes.h"
#include "ThreadCinematicsBlueprintLibrary.generated.h"

class UThreadCinematicsProfile;
class ULevelSequence;

UCLASS()
class SAGE_THREADCINEMATICS_API UThreadCinematicsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    static void Cine_SetMood(const UObject* WorldContext, EThreadCineMood Mood, FThreadCineBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    static void Cine_BlendToProfile(const UObject* WorldContext, UThreadCinematicsProfile* Profile, FThreadCineBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    static class ULevelSequencePlayer* Cine_PlaySequence(const UObject* WorldContext, ULevelSequence* Sequence, bool bHideHUD);

    UFUNCTION(BlueprintCallable, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    static void Cine_StopSequence(const UObject* WorldContext, bool bRestoreHUD);

    UFUNCTION(BlueprintPure, Category = "SAGE|Cinematics", meta = (WorldContext = "WorldContext"))
    static bool Cine_IsSequencePlaying(const UObject* WorldContext);
};
