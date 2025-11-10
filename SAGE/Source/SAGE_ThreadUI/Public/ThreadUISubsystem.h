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
#include "Subsystems/WorldSubsystem.h"
#include "GameplayTagContainer.h"
#include "ThreadUITypes.h"
#include "ThreadUISubsystem.generated.h"

class UUserWidget;
class UThreadUISettings;

DECLARE_LOG_CATEGORY_EXTERN(LogThreadUI, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHUDVisibilityChanged, bool, bVisible);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLetterboxChanged, bool, bEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFadeChanged, float, NormalizedAlpha);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNotification, FThreadUINotification, Notification);

/**
 * Single source of truth for SAGE UI. Manages HUD, overlays, fade/letterbox,
 * and broadcasts events for widgets to react to.
 */
UCLASS(BlueprintType)
class SAGE_THREADUI_API UThreadUISubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    // Lifecycle
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintPure, Category = "SAGE|UI", meta = (WorldContext = "WorldContext"))
    static UThreadUISubsystem* Get(const UObject* WorldContext);

    // HUD visibility
    UFUNCTION(BlueprintCallable, Category = "SAGE|UI")
    void ShowHUD();

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI")
    void HideHUD();

    UFUNCTION(BlueprintPure, Category = "SAGE|UI")
    bool IsHUDVisible() const { return bHUDVisible; }

    // Overlays
    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (DisplayName = "Push Overlay"))
    void PushOverlay(UUserWidget* OverlayWidget, FGameplayTag Tag);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI", meta = (DisplayName = "Pop Overlay By Tag"))
    void PopOverlayByTag(FGameplayTag Tag);

    // Letterbox + Fade
    UFUNCTION(BlueprintCallable, Category = "SAGE|UI")
    void SetLetterboxEnabled(bool bEnable, FThreadUIBlendParams Blend);

    UFUNCTION(BlueprintCallable, Category = "SAGE|UI")
    void FadeScreen(float TargetAlpha, FThreadUIBlendParams Blend);

    // Notifications
    UFUNCTION(BlueprintCallable, Category = "SAGE|UI")
    void ShowNotification(const FThreadUINotification& Notification);

    // Delegates
    UPROPERTY(BlueprintAssignable, Category = "SAGE|UI")
    FOnHUDVisibilityChanged OnHUDVisibilityChanged;

    UPROPERTY(BlueprintAssignable, Category = "SAGE|UI")
    FOnLetterboxChanged OnLetterboxChanged;

    UPROPERTY(BlueprintAssignable, Category = "SAGE|UI")
    FOnFadeChanged OnFadeChanged;

    UPROPERTY(BlueprintAssignable, Category = "SAGE|UI")
    FOnNotification OnNotification;

private:
    UPROPERTY()
    UThreadUISettings* Settings = nullptr;

    UPROPERTY(Transient)
    bool bHUDVisible = true;

    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<UUserWidget>> OverlayStack;

    UPROPERTY(Transient)
    bool bLetterbox = false;

    UPROPERTY(Transient)
    float FadeAlpha = 0.f; // 0 = clear, 1 = fully black

    void LogVerbose(const TCHAR* Fmt, ...) const;
};
