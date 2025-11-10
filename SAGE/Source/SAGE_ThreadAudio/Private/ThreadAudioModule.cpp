// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadAudio
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "Modules/ModuleManager.h"
#include "ThreadCoreSubsystem.h"
#include "Engine/Engine.h"

class FSAGE_ThreadAudioModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        if (GEngine && GEngine->GetWorldContexts().Num() > 0)
        {
            if (UWorld* World = GEngine->GetWorldContexts()[0].World())
            {
                if (UGameInstance* GI = World->GetGameInstance())
                {
                    if (UThreadCoreSubsystem* Core = GI->GetSubsystem<UThreadCoreSubsystem>())
                    {
                        Core->RegisterModule(TEXT("SAGE_ThreadAudio"));
                    }
                }
            }
        }

        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadAudio] Module Startup complete."));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadAudio] Module Shutdown complete."));
    }
};

IMPLEMENT_MODULE(FSAGE_ThreadAudioModule, SAGE_ThreadAudio)
