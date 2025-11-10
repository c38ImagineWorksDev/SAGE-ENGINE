/*
 * ============================================================
 * 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
 *  “Born from Making Reality from Your Imagination.”
 * ============================================================
 * Module: SAGE_ThreadPrint
 * Version: 0.1.0 – The Thread Awakens
 * Author: C38 ImagineWorks LLC
 * Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
 */


#include "Modules/ModuleManager.h"
#include "Engine/Engine.h"
#include "ThreadCoreSubsystem.h"

class FSAGE_ThreadPrintModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        if (GEngine && GEngine->GetWorldContexts().Num() > 0)
        {
            UWorld* World = GEngine->GetWorldContexts()[0].World();
            if (World)
            {
                if (UGameInstance* GameInstance = World->GetGameInstance())
                {
                    if (UThreadCoreSubsystem* CoreSubsystem = GameInstance->GetSubsystem<UThreadCoreSubsystem>())
                    {
                        CoreSubsystem->RegisterModule(TEXT("SAGE_ThreadPrint"));
                    }
                }
            }
        }

        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPrint] Module Startup complete."));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("[SAGE_ThreadPrint] Module Shutdown complete."));
    }
};

IMPLEMENT_MODULE(FSAGE_ThreadPrintModule, SAGE_ThreadPrint)
