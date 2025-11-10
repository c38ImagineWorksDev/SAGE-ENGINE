// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadCinematicsBlueprintLibrary.h"
#include "ThreadCinematicsSubsystem.h"
#include "LevelSequencePlayer.h"
#include "LevelSequence.h"

void UThreadCinematicsBlueprintLibrary::Cine_SetMood(const UObject* WorldContext, EThreadCineMood Mood, FThreadCineBlendParams Blend)
{
    if (UThreadCinematicsSubsystem* Sys = UThreadCinematicsSubsystem::Get(WorldContext))
    {
        Sys->SetCinematicMood(Mood, Blend);
    }
}

void UThreadCinematicsBlueprintLibrary::Cine_BlendToProfile(const UObject* WorldContext, UThreadCinematicsProfile* Profile, FThreadCineBlendParams Blend)
{
    if (UThreadCinematicsSubsystem* Sys = UThreadCinematicsSubsystem::Get(WorldContext))
    {
        Sys->BlendToProfile(Profile, Blend);
    }
}

ULevelSequencePlayer* UThreadCinematicsBlueprintLibrary::Cine_PlaySequence(const UObject* WorldContext, ULevelSequence* Sequence, bool bHideHUD)
{
    if (UThreadCinematicsSubsystem* Sys = UThreadCinematicsSubsystem::Get(WorldContext))
    {
        return Sys->PlayReactiveSequence(WorldContext, Sequence, bHideHUD);
    }
    return nullptr;
}

void UThreadCinematicsBlueprintLibrary::Cine_StopSequence(const UObject* WorldContext, bool bRestoreHUD)
{
    if (UThreadCinematicsSubsystem* Sys = UThreadCinematicsSubsystem::Get(WorldContext))
    {
        Sys->StopActiveSequence(bRestoreHUD);
    }
}

bool UThreadCinematicsBlueprintLibrary::Cine_IsSequencePlaying(const UObject* WorldContext)
{
    if (UThreadCinematicsSubsystem* Sys = UThreadCinematicsSubsystem::Get(WorldContext))
    {
        return Sys->IsSequencePlaying();
    }
    return false;
}
