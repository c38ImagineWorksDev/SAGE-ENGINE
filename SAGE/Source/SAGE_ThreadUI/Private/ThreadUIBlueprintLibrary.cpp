// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#include "ThreadUIBlueprintLibrary.h"
#include "ThreadUISubsystem.h"
#include "Blueprint/UserWidget.h"

static UThreadUISubsystem* GetUI(const UObject* WorldContext)
{
    return UThreadUISubsystem::Get(WorldContext);
}

void UThreadUIBlueprintLibrary::UI_ShowHUD(const UObject* WorldContext)
{
    if (auto* UI = GetUI(WorldContext)) UI->ShowHUD();
}

void UThreadUIBlueprintLibrary::UI_HideHUD(const UObject* WorldContext)
{
    if (auto* UI = GetUI(WorldContext)) UI->HideHUD();
}

void UThreadUIBlueprintLibrary::UI_SetLetterbox(const UObject* WorldContext, bool bEnable, FThreadUIBlendParams Blend)
{
    if (auto* UI = GetUI(WorldContext)) UI->SetLetterboxEnabled(bEnable, Blend);
}

void UThreadUIBlueprintLibrary::UI_FadeScreen(const UObject* WorldContext, float TargetAlpha, FThreadUIBlendParams Blend)
{
    if (auto* UI = GetUI(WorldContext)) UI->FadeScreen(TargetAlpha, Blend);
}

void UThreadUIBlueprintLibrary::UI_Notify(const UObject* WorldContext, const FThreadUINotification& Notification)
{
    if (auto* UI = GetUI(WorldContext)) UI->ShowNotification(Notification);
}

void UThreadUIBlueprintLibrary::UI_PushOverlay(const UObject* WorldContext, UUserWidget* OverlayWidget, FGameplayTag Tag)
{
    if (auto* UI = GetUI(WorldContext)) UI->PushOverlay(OverlayWidget, Tag);
}

void UThreadUIBlueprintLibrary::UI_PopOverlayByTag(const UObject* WorldContext, FGameplayTag Tag)
{
    if (auto* UI = GetUI(WorldContext)) UI->PopOverlayByTag(Tag);
}
