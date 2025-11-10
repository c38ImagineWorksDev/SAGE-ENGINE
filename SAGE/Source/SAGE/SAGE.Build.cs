// ============================================================
// 🕸️  STYNTHREAD ADVANCED GAME ENGINE (SAGE)
//  “Born from Making Reality from Your Imagination.”
// ============================================================
// Module: SAGE (Root)
// Version: 0.1.0 – The Thread Awakens
// Author: C38 ImagineWorks LLC
// Copyright (c) 2025 C38 ImagineWorks LLC. All Rights Reserved.
// ============================================================


using UnrealBuildTool;

public class SAGE : ModuleRules
{
    public SAGE(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // ------------------------------------------------------------
        // Core Unreal Dependencies
        // ------------------------------------------------------------
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "UMG",
            "GameplayTags"
        });

        // ------------------------------------------------------------
        // C38 ImagineWorks | The SAGE Engine Family
        // ------------------------------------------------------------
        // Uncomment a line when its module exists to include it in the build.
        // This structure acts as a living roadmap of the entire SAGE ecosystem.
        // ------------------------------------------------------------

        PublicDependencyModuleNames.AddRange(new string[]
        {
            // --- [0] Core Layer ---
            "SAGE_ThreadCore",         // Core runtime, module bootstrap & comms
            "SAGE_ThreadCoreEditor", // Editor tooling for core systems

            // --- [1] Foundation Systems ---
            "SAGE_ThreadPrint",      // Emotional memory & decision tracking
            "SAGE_ThreadSense",      // Player perception, aura, and presence data
            "SAGE_ThreadLore",       // Narrative state manager / dialogue memory
            "SAGE_ThreadTime",       // Real-world & in-game time synchronization (Thread TimeSync)
            "SAGE_ThreadAudio",      // Sound design system & reactive audio events
            "SAGE_ThreadNetwork",    // Networking, multiplayer aura sharing
            "SAGE_ThreadData",       // Data serialization / save-state layer
            "SAGE_ThreadPhysics",    // Thread-based motion & impact feedback

            // --- [2] Gameplay & World Systems ------------------------------------------
        // Core layer for player, combat, and world interactivity in SAGE Engine
        // --------------------------------------------------------------------------

        "SAGE_ThreadPlayer",      // Player identity, input, and progression
        "SAGE_ThreadWorld",       // World grid, environmental threading
        "SAGE_ThreadCombat",      // Core combat logic, weapon scaling, impact data
        "SAGE_ThreadClasses",     // Player class system (skills, subclasses, etc.)
        "SAGE_ThreadInventory",   // Inventory, item metadata, and memory tagging
        "SAGE_ThreadAI",          // Thread-aware AI system (adaptive behaviors)
        "SAGE_ThreadCinematics",  // In-engine cutscenes, emotion-driven pacing
        "SAGE_ThreadDialogue",    // Conversation system with ThreadPrint responses
        "SAGE_ThreadQuests",      // Quest, mission, and consequence management
        "SAGE_ThreadUI",          // Custom UI framework for SAGE (menus, HUDs)


            // --- [3] Utility & Integration Layers ---
            //"SAGE_ThreadDebug",      // Debug visualization, diagnostics overlay
            //"SAGE_ThreadDevKit",     // Developer utilities for plugin & module creation
            //"SAGE_ThreadTools",      // Internal scripting tools (BP node extensions, etc.)
            //"SAGE_ThreadAnalytics",  // Gameplay analytics and player ThreadPrint analysis
            //"SAGE_ThreadBuild",      // Build/versioning and semantic logging
            //"SAGE_ThreadLocalization", // Multilingual text and voice threading
            //"SAGE_ThreadEditor",     // Full editor integration and custom tabs
            //"SAGE_ThreadVR",         // VR/AR layer (future extension)
            //"SAGE_ThreadXR",         // Full-dive XR integration (long-term SAGE vision)

            // --- [4] Experimental / Next-Gen Layers ---
            //"SAGE_ThreadAI_Voice",   // Voice-driven AI systems and NPC cognition
            //"SAGE_ThreadNetverse",   // Interconnected world data for shared universes
            //"SAGE_ThreadSim",        // Simulation systems for weather, emotion, and memory
            //"SAGE_ThreadOSBridge",   // Cross-layer connection to ThreadOS & ThreadUGL
            //"SAGE_ThreadVRLattice"   // Prototype neural link / real-time feedback system
        });

        // ------------------------------------------------------------
        // Private Dependencies
        // ------------------------------------------------------------
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Slate",
            "SlateCore",
            "Projects"
        });

        // ------------------------------------------------------------
        // ------------------------------------------------------------
        // 🛠️ Editor Dependencies (Optional)
        // ------------------------------------------------------------
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
        "UnrealEd",          // Editor core functionality
        "DeveloperSettings", // Needed for UDeveloperSettings subclasses (e.g., ThreadCoreSettings)
        "PropertyEditor",    // (Optional) Enables property editing in custom panels
        "SettingsEditor"     // (Optional) Lets SAGE expose custom settings categories
            });
        }


        // ------------------------------------------------------------
        // ⚙️ Build Settings | C38 ImagineWorks
        // ------------------------------------------------------------
        bUseUnity = true;
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
    }
}
