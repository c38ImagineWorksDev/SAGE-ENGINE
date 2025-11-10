/*
 * ============================================================
 * 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
 *  “Born from Making Reality from Your Imagination.”
 * ============================================================
 * Module: SAGE_ThreadCore
 * Version: 0.1.0 – The Thread Awakens
 * Author: C38 ImagineWorks LLC
 * Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
 */


#pragma once

#include "CoreMinimal.h"
#include "ThreadCoreTypes.generated.h"

 /** Enum defining thread message severity */
UENUM(BlueprintType)
enum class EThreadMessageSeverity : uint8
{
    Info,
    Warning,
    Error
};

/** Struct for standardized inter-module communication */
USTRUCT(BlueprintType)
struct FThreadMessage
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadCore")
    FString Source;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadCore")
    FString Content;

    UPROPERTY(BlueprintReadWrite, Category = "SAGE|ThreadCore")
    EThreadMessageSeverity Severity;

    FThreadMessage()
        : Source(TEXT("Unknown")), Content(TEXT("")), Severity(EThreadMessageSeverity::Info)
    {
    }

    FThreadMessage(const FString& InSource, const FString& InContent, EThreadMessageSeverity InSeverity = EThreadMessageSeverity::Info)
        : Source(InSource), Content(InContent), Severity(InSeverity)
    {
    }
};
