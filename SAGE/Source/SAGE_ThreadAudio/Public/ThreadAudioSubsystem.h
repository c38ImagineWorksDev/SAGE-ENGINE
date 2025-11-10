// ============================================================
// ???  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAudio
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Sound/SoundCue.h"
#include "ThreadAudioSubsystem.generated.h"

UCLASS()
class SAGE_THREADAUDIO_API UThreadAudioSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadAudio")
    void PlayReactiveSound(USoundCue* Cue, FVector Location, float Volume = 1.0f);

    UFUNCTION(BlueprintCallable, Category = "SAGE|ThreadAudio")
    void StopAllReactiveSounds();

private:
    TArray<UAudioComponent*> ActiveSounds;
};
