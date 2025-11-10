// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadUI
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================
#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadUITypes.h"
#include "ThreadUIBlueprintLibrary.generated.h"

class UUserWidget;
class UThreadUISubsystem;

UCLASS()
class SAGE_THREADUI_API UThreadUIBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_ShowHUD(const UObject* WorldContext);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_HideHUD(const UObject* WorldContext);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_SetLetterbox(const UObject* WorldContext, bool bEnable, FThreadUIBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_FadeScreen(const UObject* WorldContext, float TargetAlpha, FThreadUIBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_Notify(const UObject* WorldContext, const FThreadUINotification& Notification);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_PushOverlay(const UObject* WorldContext, UUserWidget* OverlayWidget, FGameplayTag Tag);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static void UI_PopOverlayByTag(const UObject* WorldContext, FGameplayTag Tag);
};
