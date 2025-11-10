// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE_ThreadCoreEditor
// Version: v0.2.0 – The Thread Stirs
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================

#include "ThreadCoreEditorModule.h"

#include "ToolMenus.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"
#include "Styling/AppStyle.h"
#include "Modules/ModuleManager.h"
#include "ISettingsModule.h"
#include "Editor.h"

// Pull Core status from GameInstance subsystem (not World subsystem)
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "ThreadCoreSubsystem.h" // make sure this is in SAGE_ThreadCore/Public

#define LOCTEXT_NAMESPACE "FThreadCoreEditorModule"

const FName FThreadCoreEditorModule::ThreadCoreTabName(TEXT("SAGE_ThreadCorePanel"));

IMPLEMENT_MODULE(FThreadCoreEditorModule, SAGE_ThreadCoreEditor)

void FThreadCoreEditorModule::StartupModule()
{
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
        ThreadCoreTabName,
        FOnSpawnTab::CreateRaw(this, &FThreadCoreEditorModule::SpawnThreadCoreTab)
    )
        .SetDisplayName(LOCTEXT("ThreadCoreTabTitle", "SAGE ThreadCore"))
        .SetTooltipText(LOCTEXT("ThreadCoreTabTooltip", "SAGE ThreadCore status and tools."))
        .SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"))
        .SetMenuType(ETabSpawnerMenuType::Hidden);

    RegisterMenus();
    RegisterSettings();
}

void FThreadCoreEditorModule::ShutdownModule()
{
    UnregisterSettings();

    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(ThreadCoreTabName);

    if (UToolMenus* TM = UToolMenus::Get())
    {
        TM->UnregisterOwner(this);
    }
}

TSharedRef<SDockTab> FThreadCoreEditorModule::SpawnThreadCoreTab(const FSpawnTabArgs& Args)
{
    FString VersionString = TEXT("v0.2.0 – The Thread Stirs");

    FString Status = TEXT("Idle");
    if (GEditor)
    {
        if (UWorld* World = GEditor->GetEditorWorldContext().World())
        {
            if (UGameInstance* GI = World->GetGameInstance())
            {
                if (UThreadCoreSubsystem* Core = GI->GetSubsystem<UThreadCoreSubsystem>())
                {
                    Status = TEXT("Core Subsystem: Ready");
                }
            }
        }
    }

    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(SBorder)
                .Padding(12)
                .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
                [
                    SNew(SBox)
                        .Padding(8)
                        [
                            SNew(STextBlock)
                                .AutoWrapText(true)
                                .Text(FText::FromString(
                                    FString::Printf(
                                        TEXT("🕸️ SAGE ThreadCore\nStatus: %s\nVersion: %s\n\nWindow ▸ SAGE ▸ ThreadCore Panel\nProject Settings ▸ SAGE ▸ ThreadCore"),
                                        *Status,
                                        *VersionString
                                    )
                                ))
                        ]
                ]
        ];
}

void FThreadCoreEditorModule::RegisterMenus()
{
    UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateLambda([this]()
        {
            if (UToolMenus* TM = UToolMenus::Get())
            {
                if (UToolMenu* WindowMenu = TM->ExtendMenu("LevelEditor.MainMenu.Window"))
                {
                    FToolMenuSection& Section = WindowMenu->AddSection("SAGE_Window", LOCTEXT("SAGEWindowSection", "SAGE"));
                    Section.AddMenuEntry(
                        "OpenThreadCorePanel",
                        LOCTEXT("OpenThreadCorePanel", "SAGE ▸ ThreadCore Panel"),
                        LOCTEXT("OpenThreadCorePanel_Tooltip", "Open the SAGE ThreadCore panel."),
                        FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"),
                        FUIAction(FExecuteAction::CreateLambda([]
                            {
                                FGlobalTabmanager::Get()->TryInvokeTab(FThreadCoreEditorModule::ThreadCoreTabName);
                            }))
                    );
                }

                if (UToolMenu* Toolbar = TM->ExtendMenu("LevelEditor.LevelEditorToolBar"))
                {
                    FToolMenuSection& Section = Toolbar->FindOrAddSection("Settings");
                    Section.AddEntry(FToolMenuEntry::InitToolBarButton(
                        "ThreadCoreToolbarButton",
                        FUIAction(FExecuteAction::CreateLambda([]
                            {
                                FGlobalTabmanager::Get()->TryInvokeTab(FThreadCoreEditorModule::ThreadCoreTabName);
                            })),
                        LOCTEXT("ThreadCoreToolbar_Label", "ThreadCore"),
                        LOCTEXT("ThreadCoreToolbar_Tooltip", "Open SAGE ThreadCore panel."),
                        FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details")
                    ));
                }
            }
        }));
}

void FThreadCoreEditorModule::RegisterSettings()
{
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        UClass* SettingsClass = FindObject<UClass>(nullptr, TEXT("/Script/SAGE_ThreadCore.ThreadCoreSettings"));
        if (!SettingsClass)
        {
            SettingsClass = FindFirstObject<UClass>(TEXT("ThreadCoreSettings"));
        }

        if (SettingsClass)
        {
            UObject* SettingsObj = GetMutableDefault<UObject>(SettingsClass);
            SettingsModule->RegisterSettings(
                "Project", "SAGE", "ThreadCore",
                LOCTEXT("ThreadCoreSettingsName", "ThreadCore"),
                LOCTEXT("ThreadCoreSettingsDesc", "Configure SAGE ThreadCore settings."),
                SettingsObj
            );
        }
    }
}

void FThreadCoreEditorModule::UnregisterSettings()
{
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "SAGE", "ThreadCore");
    }
}

#undef LOCTEXT_NAMESPACE
