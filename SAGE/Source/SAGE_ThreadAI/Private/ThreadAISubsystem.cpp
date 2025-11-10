// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================

#include "ThreadAISubsystem.h"
#include "ThreadAISettings.h"
#include "ThreadAIActorInterface.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "UObject/UObjectIterator.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogThreadAI);

void UThreadAISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    CachedSettings = GetMutableDefault<UThreadAISettings>();
    Agents.Reset();

    // Auto-discover any actors already in the world that implement our interface.
    for (TObjectIterator<AActor> It; It; ++It)
    {
        if (!It->GetWorld() || It->GetWorld() != GetWorld()) continue;
        if (It->GetClass()->ImplementsInterface(UThreadAIActorInterface::StaticClass()))
        {
            RegisterAgent(*It);
        }
    }

    UE_LOG(LogThreadAI, Log, TEXT("[ThreadAI] Init | Agents=%d"), Agents.Num());
}

void UThreadAISubsystem::Deinitialize()
{
    UE_LOG(LogThreadAI, Log, TEXT("[ThreadAI] Shutdown | Agents=%d"), Agents.Num());
    Agents.Reset();
    CachedSettings = nullptr;

    Super::Deinitialize();
}

void UThreadAISubsystem::RegisterAgent(AActor* Agent)
{
    if (!IsValid(Agent)) return;
    for (const TWeakObjectPtr<AActor>& Existing : Agents)
    {
        if (Existing.Get() == Agent) return;
    }
    Agents.Add(Agent);

    if (CachedSettings && CachedSettings->bVerboseLogs)
    {
        UE_LOG(LogThreadAI, Verbose, TEXT("[Register] %s (Total=%d)"), *GetNameSafe(Agent), Agents.Num());
    }
}

void UThreadAISubsystem::UnregisterAgent(AActor* Agent)
{
    if (!IsValid(Agent)) return;

    for (int32 i = Agents.Num() - 1; i >= 0; --i)
    {
        if (Agents[i].Get() == Agent)
        {
            Agents.RemoveAtSwap(i, 1, EAllowShrinking::No);
            if (CachedSettings && CachedSettings->bVerboseLogs)
            {
                UE_LOG(LogThreadAI, Verbose, TEXT("[Unregister] %s (Total=%d)"), *GetNameSafe(Agent), Agents.Num());
            }
            break;
        }
    }
}

bool UThreadAISubsystem::IsRegistered(AActor* Agent) const
{
    if (!IsValid(Agent)) return false;
    for (const TWeakObjectPtr<AActor>& Existing : Agents)
    {
        if (Existing.Get() == Agent) return true;
    }
    return false;
}

bool UThreadAISubsystem::CompactAgents()
{
    const int32 Before = Agents.Num();
    Agents.RemoveAllSwap([](const TWeakObjectPtr<AActor>& Ptr) { return !Ptr.IsValid(); }, EAllowShrinking::No);
    return Agents.Num() != Before;
}

void UThreadAISubsystem::GetAgentList(TArray<AActor*>& OutAgents) const
{
    OutAgents.Reset();
    for (const TWeakObjectPtr<AActor>& P : Agents)
    {
        if (AActor* A = P.Get())
        {
            OutAgents.Add(A);
        }
    }
}

void UThreadAISubsystem::EmitStimulus(const FThreadAIStimulus& Stimulus)
{
    if (!Stimulus.Source.IsValid() && !Stimulus.Target.IsValid())
    {
        UE_LOG(LogThreadAI, Warning, TEXT("[Stimulus] Ignored: no Source/Target"));
        return;
    }

    CompactAgents();

    for (const TWeakObjectPtr<AActor>& AgentPtr : Agents)
    {
        AActor* Agent = AgentPtr.Get();
        if (!IsValid(Agent)) continue;

        if (Agent->GetClass()->ImplementsInterface(UThreadAIActorInterface::StaticClass()))
        {
            IThreadAIActorInterface::Execute_OnThreadStimulus(Agent, Stimulus);
        }
    }

    if (CachedSettings && CachedSettings->bVerboseLogs)
    {
        UE_LOG(LogThreadAI, Verbose, TEXT("[Stimulus] %s -> %s | Intent=%d | Tags=%s | DeliveredTo=%d"),
            *GetNameSafe(Stimulus.Source.Get()), *GetNameSafe(Stimulus.Target.Get()),
            static_cast<int32>(Stimulus.Intent),
            *Stimulus.Tags.ToStringSimple(), Agents.Num());
    }
}

void UThreadAISubsystem::EmitSimpleStimulus(AActor* Source, AActor* Target, EThreadAIIntent Intent)
{
    FThreadAIStimulus S;
    S.Source = Source;
    S.Target = Target;
    S.Intent = Intent;

    if (CachedSettings)
    {
        S.Tags.AppendTags(CachedSettings->GlobalStimulusTags);
    }

    EmitStimulus(S);
}

UThreadAISubsystem* UThreadAISubsystem::Get(const UObject* WorldContext)
{
    if (!WorldContext) return nullptr;
    if (const UWorld* World = WorldContext->GetWorld())
    {
        return World->GetSubsystem<UThreadAISubsystem>();
    }
    return nullptr;
}
