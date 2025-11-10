// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCinematics
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadCinematicsSubsystem.h"
#include "ThreadCinematicsSettings.h"
#include "ThreadCinematicsProfile.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"

// 🔗 UI integration
#include "ThreadUISubsystem.h"

DEFINE_LOG_CATEGORY(LogThreadCinematics);

void UThreadCinematicsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Settings = GetMutableDefault<UThreadCinematicsSettings>();
    CurrentMood = Settings ? Settings->DefaultMood : EThreadCineMood::Neutral;
    UE_LOG(LogThreadCinematics, Log, TEXT("[Cinematics] Init | Mood=%d"), (int32)CurrentMood);
}

void UThreadCinematicsSubsystem::Deinitialize()
{
    UE_LOG(LogThreadCinematics, Log, TEXT("[Cinematics] Shutdown"));
    ActivePlayer.Reset();
    Settings = nullptr;
    Super::Deinitialize();
}

void UThreadCinematicsSubsystem::SetMood(EThreadCineMood NewMood)
{
    if (CurrentMood == NewMood) return;
    CurrentMood = NewMood;

    if (Settings && Settings->bVerboseLogs)
    {
        UE_LOG(LogThreadCinematics, Verbose, TEXT("[SetMood] -> %d"), (int32)CurrentMood);
    }
}

UThreadCinematicsSubsystem* UThreadCinematicsSubsystem::Get(const UObject* WorldContext)
{
    if (!WorldContext) return nullptr;
    if (const UWorld* World = WorldContext->GetWorld())
    {
        return World->GetSubsystem<UThreadCinematicsSubsystem>();
    }
    return nullptr;
}

// === API used by the Blueprint Library ===

void UThreadCinematicsSubsystem::SetCinematicMood(EThreadCineMood NewMood, FThreadCineBlendParams /*Blend*/)
{
    // Update mood immediately (future: honor blend timing)
    SetMood(NewMood);

    // Optional: auto-letterbox for non-neutral moods
    if (UThreadUISubsystem* UI = UThreadUISubsystem::Get(this))
    {
        const bool bCinematic = (NewMood != EThreadCineMood::Neutral);
        // Fixed: no dependency on Blend.Duration — using safe default values
        UI->SetLetterboxEnabled(bCinematic, { 0.35f, 1.0f });
    }
}

void UThreadCinematicsSubsystem::BlendToProfile(UThreadCinematicsProfile* Profile, FThreadCineBlendParams /*Blend*/)
{
    // Future: apply Profile fields (letterbox/FOV/exposure) with timed blend.
    if (Settings && Settings->bVerboseLogs)
    {
        UE_LOG(LogThreadCinematics, Verbose, TEXT("[BlendToProfile] Profile=%s"),
            Profile ? *Profile->GetName() : TEXT("<None>"));
    }
}

ULevelSequencePlayer* UThreadCinematicsSubsystem::PlayReactiveSequence(const UObject* WorldContext, ULevelSequence* Sequence, bool bHideHUD)
{
    UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
    if (!World || !Sequence)
    {
        UE_LOG(LogThreadCinematics, Warning, TEXT("[PlayReactiveSequence] Missing World or Sequence"));
        return nullptr;
    }

    // 🔻 UI hook: hide HUD + enable letterbox on start
    if (bHideHUD)
    {
        if (UThreadUISubsystem* UI = UThreadUISubsystem::Get(WorldContext))
        {
            UI->HideHUD();
            UI->SetLetterboxEnabled(true, { 0.35f, 1.0f }); // smooth fade-in
        }
    }

    ALevelSequenceActor* OutActor = nullptr;
    FMovieSceneSequencePlaybackSettings PlaybackSettings;
    ULevelSequencePlayer* Player = ULevelSequencePlayer::CreateLevelSequencePlayer(World, Sequence, PlaybackSettings, OutActor);

    if (Player)
    {
        Player->Play();
        ActivePlayer = Player;
        bHUDHidden = bHideHUD;

        if (Settings && Settings->bVerboseLogs)
        {
            UE_LOG(LogThreadCinematics, Verbose, TEXT("[PlayReactiveSequence] Playing %s"), *Sequence->GetName());
        }
    }

    return Player;
}

void UThreadCinematicsSubsystem::StopActiveSequence(bool /*bRestoreHUD*/)
{
    if (ActivePlayer.IsValid())
    {
        ActivePlayer->Stop();

        if (Settings && Settings->bVerboseLogs)
        {
            UE_LOG(LogThreadCinematics, Verbose, TEXT("[StopActiveSequence] Stopped"));
        }
    }

    // 🔺 UI hook: restore HUD + disable letterbox
    if (UThreadUISubsystem* UI = UThreadUISubsystem::Get(this))
    {
        if (bHUDHidden)
        {
            UI->ShowHUD();
        }
        UI->SetLetterboxEnabled(false, { 0.35f, 1.0f }); // smooth fade-out
    }

    ActivePlayer.Reset();
    bHUDHidden = false;
}

bool UThreadCinematicsSubsystem::IsSequencePlaying() const
{
    return ActivePlayer.IsValid() && ActivePlayer->IsPlaying();
}
