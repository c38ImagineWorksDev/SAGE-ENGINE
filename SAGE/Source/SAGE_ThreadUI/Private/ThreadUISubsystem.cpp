// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadUISubsystem.h"
#include "ThreadUISettings.h"

#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/UnrealString.h"
#include "HAL/PlatformCrt.h"   // for va_list / va_start / va_end
#include "Misc/Char.h"

DEFINE_LOG_CATEGORY(LogThreadUI);

void UThreadUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Settings = GetMutableDefault<UThreadUISettings>();
    bHUDVisible = true;
    bLetterbox = false;
    FadeAlpha = 0.f;
    UE_LOG(LogThreadUI, Log, TEXT("[UI] Init | Theme=%d"), (int32)Settings->DefaultTheme);
}

void UThreadUISubsystem::Deinitialize()
{
    OverlayStack.Reset();
    Settings = nullptr;
    Super::Deinitialize();
}

UThreadUISubsystem* UThreadUISubsystem::Get(const UObject* WorldContext)
{
    if (!WorldContext) return nullptr;
    if (const UWorld* World = WorldContext->GetWorld())
    {
        return World->GetSubsystem<UThreadUISubsystem>();
    }
    return nullptr;
}

void UThreadUISubsystem::ShowHUD()
{
    if (bHUDVisible) return;
    bHUDVisible = true;
    OnHUDVisibilityChanged.Broadcast(true);
    LogVerbose(TEXT("[HUD] Show"));
}

void UThreadUISubsystem::HideHUD()
{
    if (!bHUDVisible) return;
    bHUDVisible = false;
    OnHUDVisibilityChanged.Broadcast(false);
    LogVerbose(TEXT("[HUD] Hide"));
}

void UThreadUISubsystem::PushOverlay(UUserWidget* OverlayWidget, FGameplayTag Tag)
{
    if (!OverlayWidget) return;
    OverlayStack.Add(OverlayWidget);
    LogVerbose(TEXT("[Overlay] Push | %s"), *Tag.ToString());
}

void UThreadUISubsystem::PopOverlayByTag(FGameplayTag Tag)
{
    for (int32 i = OverlayStack.Num() - 1; i >= 0; --i)
    {
        if (OverlayStack[i].IsValid())
        {
            OverlayStack.RemoveAtSwap(i);
            LogVerbose(TEXT("[Overlay] Pop | %s"), *Tag.ToString());
            return;
        }
        else
        {
            OverlayStack.RemoveAtSwap(i);
        }
    }
}

void UThreadUISubsystem::SetLetterboxEnabled(bool bEnable, FThreadUIBlendParams Blend)
{
    bLetterbox = bEnable;
    OnLetterboxChanged.Broadcast(bLetterbox);
    LogVerbose(TEXT("[Letterbox] %s in %.2fs"), bEnable ? TEXT("Enable") : TEXT("Disable"), Blend.Duration);
}

void UThreadUISubsystem::FadeScreen(float TargetAlpha, FThreadUIBlendParams Blend)
{
    FadeAlpha = FMath::Clamp(TargetAlpha, 0.f, 1.f);
    OnFadeChanged.Broadcast(FadeAlpha);
    LogVerbose(TEXT("[Fade] Alpha=%.2f in %.2fs"), FadeAlpha, Blend.Duration);
}

void UThreadUISubsystem::ShowNotification(const FThreadUINotification& Notification)
{
    OnNotification.Broadcast(Notification);
    if (Settings && Settings->bVerboseLogs)
    {
        UE_LOG(LogThreadUI, Log, TEXT("[Notify] '%s' (%.2fs, %s)"),
            *Notification.Message.ToString(),
            Notification.Duration,
            *Notification.StyleTag.ToString());
    }
}

void UThreadUISubsystem::LogVerbose(const TCHAR* Fmt, ...) const
{
    if (!(Settings && Settings->bVerboseLogs)) return;

    // format the varargs into a temp TCHAR buffer
    va_list Args;
    va_start(Args, Fmt);

    TCHAR Temp[1024];
    // FCString::GetVarArgs writes formatted text into Temp (null-terminated)
    FCString::GetVarArgs(Temp, UE_ARRAY_COUNT(Temp), Fmt, Args);

    va_end(Args);

    UE_LOG(LogThreadUI, Verbose, TEXT("%s"), Temp);
}
