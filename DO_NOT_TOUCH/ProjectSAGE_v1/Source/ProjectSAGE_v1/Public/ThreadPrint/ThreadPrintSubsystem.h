#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ThreadPrintTypes.h"
#include "ThreadPrintSubsystem.generated.h"

UCLASS()
class PROJECTSAGE_V1_API UThreadPrintSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "ThreadPrint|Log")
    void LogThreadEvent(EThreadEventKind Kind, FName EventKey, const FString& Note,
        const TArray<FThreadTag>& Tags, const FThreadContext& Context);

    UFUNCTION(BlueprintCallable, Category = "ThreadPrint|Query")
    void GetEventsByTag(FName TagName, TArray<FThreadEvent>& OutEvents) const;

    UFUNCTION(BlueprintCallable, Category = "ThreadPrint|Query")
    void GetEventsByKey(FName Key, TArray<FThreadEvent>& OutEvents) const;

    UFUNCTION(BlueprintPure, Category = "ThreadPrint|Query")
    int32 GetEventCount() const { return Events.Num(); }

    UFUNCTION(BlueprintPure, Category = "ThreadPrint|Query")
    const TArray<FThreadEvent>& GetAllEvents() const { return Events; }

private:
    UPROPERTY()
    TArray<FThreadEvent> Events;

    float ComputeScore(const TArray<FThreadTag>& Tags) const;
    int64 NowUTC() const;
};
