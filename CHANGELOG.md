![UE 5.6](https://img.shields.io/badge/Unreal_Engine-5.6-blue)
![Version](https://img.shields.io/badge/Version-v0.2.0--The_Thread_Stirs-orange)
![Status](https://img.shields.io/badge/Build-Stable-success)

# 🕸️ SAGE Engine — Changelog
> **STYNTHREAD ADVANCED GAME ENGINE (SAGE)**  
> *"Born from Making Reality from Your Imagination."*  
> Maintained by **C38 ImagineWorks, LLC**

---

## [v0.2.0] — *The Thread Stirs* 🧠 *(Current)*
**Released:** November 2025  
**Status:** Active Development  
**Focus:** Stabilization of Core, Gameplay, and Editor systems.

### ✨ Added
- **Major Modules Online**
  - ✅ `SAGE_ThreadCore` — Central lifecycle manager with boot, pause, and sync events.
  - ✅ `SAGE_ThreadPrint` — Emotional memory + consequence system.
  - ✅ `SAGE_ThreadWorld` — Region, environment, and world subsystem.
  - ✅ `SAGE_ThreadCombat` — Core combat + damage event structure.
  - ✅ `SAGE_ThreadClasses` — Player archetypes and class data.
  - ✅ `SAGE_ThreadInventory` — Equipment, loot, and container logic.
  - ✅ `SAGE_ThreadDialogue` — Dialogue event flow and speaker interface.
  - ✅ `SAGE_ThreadCinematics` — Reactive camera + letterbox support.
  - ✅ `SAGE_ThreadUI` — HUD manager and cinematic overlay control.
  - ✅ `SAGE_ThreadQuests` — Quest tracking and progress subsystem.
  - ✅ `SAGE_ThreadCoreEditor` — Custom editor tab, settings menu, and toolbar integration.
- Introduced **ThreadEventHub** for clean cross-module communication.
- Added **Thread TimeSync** (real-world ↔ in-game environmental sync).
- Created initial **Blueprint Libraries** for Dialogue, Cinematics, and UI.

### 🔧 Improved
- Unified naming conventions (`SAGE_Thread*`) across all modules.
- Refactored build dependencies to resolve cyclic header issues.
- Implemented consistent version header blocks in all `.h`/`.cpp` files.
- Updated to **Unreal Engine 5.6 toolchain** compatibility.
- Optimized subsystem initialization order (Core → World → UI → Dialogue → Quests).

### 🐛 Fixed
- Header include order errors under `Unreal5_6` include rules.
- `UThreadCinematicsSubsystem` linking failures caused by missing Blueprint function definitions.
- Various access modifier and API macro mismatches (`SAGE_THREAD* _API`).

### 🧭 In Progress
- ThreadAI perception → mood → action bridge.
- Debug overlay (ThreadSync, quest, cinematic state indicators).
- Boot Profiles (configurable subsystem load order).

---

## [v0.1.0] — *The Thread Awakens* 🌱
**Released:** April 2025  
**Focus:** Initial engine skeleton.

### Added
- Established repository structure and build configuration.
- Implemented first Core, Print, and World subsystem prototypes.
- Created branding headers and documentation templates.
- Setup CI / CD GitHub Actions for build validation.
- Defined SAGE coding standards and naming grimoire.

---

## 🧾 Version Naming Convention
| Version | Codename | Theme | Purpose |
|----------|-----------|--------|----------|
| v0.1.x | *The Thread Awakens* | Genesis | Core architecture |
| v0.2.x | *The Thread Stirs* | Stabilization | Gameplay + editor layer |
| v0.3.x | *The Thread Weaves* | Connection | System finalization |
| v0.4.x | *The Thread Learns* | Reflection | Tooling & authoring |
| v0.5.x | *The Thread Walks* | Action | Vertical slice |
| v0.6.x+ | *The Thread Sings* | Expansion | Optimization + release |

---

👉 See the [Roadmap](./.github/ROADMAP.md) for milestone goals.

## 🧑🏾‍💻 Maintainer
**C38 ImagineWorks LLC**  
info@c38imagineworks.com  

© 2025 C38 ImagineWorks LLC. All Rights Reserved.