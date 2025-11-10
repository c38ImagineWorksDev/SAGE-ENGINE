// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================

#include "ThreadAIBlueprintLibrary.h"
#include "ThreadAISubsystem.h"

void UThreadAIBlueprintLibrary::ThreadAI_EmitSimpleStimulus(const UObject* WorldContext, AActor* Source, AActor* Target, EThreadAIIntent Intent)
{
    if (UThreadAISubsystem* Sys = UThreadAISubsystem::Get(WorldContext))
    {
        Sys->EmitSimpleStimulus(Source, Target, Intent);
    }
}

void UThreadAIBlueprintLibrary::ThreadAI_EmitStimulus(const UObject* WorldContext, const FThreadAIStimulus& Stimulus)
{
    if (UThreadAISubsystem* Sys = UThreadAISubsystem::Get(WorldContext))
    {
        Sys->EmitStimulus(Stimulus);
    }
}

void UThreadAIBlueprintLibrary::ThreadAI_GetAgents(const UObject* WorldContext, TArray<AActor*>& OutAgents)
{
    OutAgents.Reset();
    if (UThreadAISubsystem* Sys = UThreadAISubsystem::Get(WorldContext))
    {
        Sys->GetAgentList(OutAgents);
    }
}
