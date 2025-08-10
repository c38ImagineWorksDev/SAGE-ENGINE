#pragma once
#include "CoreMinimal.h"
#include "ThreadPrintTypes.generated.h"

UENUM(BlueprintType)
enum class EThreadEventKind : uint8
{
    Decision     UMETA(DisplayName = "Decision"),
    Combat       UMETA(DisplayName = "Combat"),
    Social       UMETA(DisplayName = "Social"),
    Exploration  UMETA(DisplayName = "Exploration"),
    System       UMETA(DisplayName = "System")
};

USTRUCT(BlueprintType)
struct FThreadTag
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name = NAME_None;           // ? correct macro

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Weight = 1.f;
};

USTRUCT(BlueprintType)
struct FThreadContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Map = NAME_None;            // ? correct

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector_NetQuantize Location = FVector::ZeroVector;

    // e.g., QuestID, NPCID, FactionID
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, FString> Meta;
};

USTRUCT(BlueprintType)
struct FThreadEvent
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EThreadEventKind Kind = EThreadEventKind::System;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName EventKey = NAME_None;       // ? correct

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Note;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int64 UTCTimestamp = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FThreadTag> Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FThreadContext Context;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    float Score = 0.f;
};
