// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAudio
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadAudioSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

void UThreadAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadAudio] Subsystem Initialized."));
}

void UThreadAudioSubsystem::Deinitialize()
{
    StopAllReactiveSounds();
    Super::Deinitialize();
}

void UThreadAudioSubsystem::PlayReactiveSound(USoundCue* Cue, FVector Location, float Volume)
{
    if (!Cue) return;

    UWorld* World = GetWorld();
    if (World)
    {
        UAudioComponent* AC = UGameplayStatics::SpawnSoundAtLocation(World, Cue, Location, FRotator::ZeroRotator, Volume);
        if (AC)
        {
            ActiveSounds.Add(AC);
            UE_LOG(LogTemp, Log, TEXT("[Audio] Reactive sound played: %s"), *Cue->GetName());
        }
    }
}

void UThreadAudioSubsystem::StopAllReactiveSounds()
{
    for (UAudioComponent* AC : ActiveSounds)
    {
        if (AC && AC->IsPlaying())
            AC->Stop();
    }
    ActiveSounds.Empty();
    UE_LOG(LogTemp, Log, TEXT("[Audio] All reactive sounds stopped."));
}
