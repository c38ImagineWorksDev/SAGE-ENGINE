#include "ThreadPrint/ThreadPrintSubsystem.h"
#include "Misc/DateTime.h"

void UThreadPrintSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Events.Reserve(256);
}

void UThreadPrintSubsystem::Deinitialize()
{
    Events.Empty();
    Super::Deinitialize();
}

int64 UThreadPrintSubsystem::NowUTC() const
{
    return FDateTime::UtcNow().ToUnixTimestamp();
}

float UThreadPrintSubsystem::ComputeScore(const TArray<FThreadTag>& Tags) const
{
    float Total = 0.f;
    for (const FThreadTag& T : Tags)
    {
        Total += T.Weight;
    }
    return Total;
}

void UThreadPrintSubsystem::LogThreadEvent(EThreadEventKind Kind, FName EventKey, const FString& Note,
    const TArray<FThreadTag>& Tags, const FThreadContext& Context)
{
    FThreadEvent Evt;
    Evt.Kind = Kind;
    Evt.EventKey = EventKey;
    Evt.Note = Note;
    Evt.Tags = Tags;
    Evt.Context = Context;
    Evt.UTCTimestamp = NowUTC();
    Evt.Score = ComputeScore(Tags);

    Events.Add(Evt);
    // TODO: broadcast delegate for live reactions; persist to save
}

void UThreadPrintSubsystem::GetEventsByTag(FName TagName, TArray<FThreadEvent>& OutEvents) const
{
    OutEvents.Reset();
    for (const FThreadEvent& E : Events)
    {
        for (const FThreadTag& T : E.Tags)
        {
            if (T.Name == TagName)
            {
                OutEvents.Add(E);
                break;
            }
        }
    }
}

void UThreadPrintSubsystem::GetEventsByKey(FName Key, TArray<FThreadEvent>& OutEvents) const
{
    OutEvents.Reset();
    for (const FThreadEvent& E : Events)
    {
        if (E.EventKey == Key)
        {
            OutEvents.Add(E);
        }
    }
}
