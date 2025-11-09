# SAGE Engine — Roadmap
> **STYNTHREAD Advanced Game Engine (SAGE)**  
> “Born from Making Reality from Your Imagination.”

**Current Track:** v0.2.x — *The Thread Stirs*  
**Focus:** Gameplay & World Systems complete, Editor tools phase begins, Blueprint integration.

---

## Vision
SAGE is a narrative-reactive layer on top of Unreal Engine that tracks emotion, memory, and consequence (ThreadPrint) and lets systems (Dialogue, Quests, Cinematics, UI, AI, etc.) react in sync.

---

## Versioning
- **vMAJOR.MINOR.PATCH – Codename**
- v0.1.x — *The Thread Awakens* (foundation bootstraps)
- **v0.2.x — *The Thread Stirs*** (you are here)
- v0.3.x — *The Thread Weaves* (system layer + tooling)
- v0.4.x — *The Thread Learns* (authoring tools, data assets)
- v0.5.x — *The Thread Walks* (playable vertical slice)
- v0.6.x+ — *The Thread Sings* (perf, multiplayer, beta prep)

---

## Module Status Matrix
**Legend:** ✅ Done  |  🔧 In progress  |  🧭 Planned  |  🧪 Experimental

### Foundation
- ✅ `SAGE_ThreadCore` — Core lifecycle/events, subsystem boot.
- ✅ `SAGE_ThreadPrint` — Emotional memory & decision tracking.
- ✅ `SAGE_ThreadLore` — Narrative state & dialogue memory.
- ✅ `SAGE_ThreadSense` — Perception/aura/presence data.
- ✅ `SAGE_ThreadTime` — Real-world ↔ in-game sync (Thread TimeSync).
- ✅ `SAGE_ThreadAudio` — Reactive audio hooks.
- ✅ `SAGE_ThreadData` — Save-state and data serialization.
- ✅ `SAGE_ThreadPhysics` — Thread-based motion/impact affordances.
- ✅ `SAGE_ThreadNetwork` — (base stubs) multiplayer aura sharing.

### Gameplay & World
- ✅ `SAGE_ThreadPlayer`
- ✅ `SAGE_ThreadWorld`
- ✅ `SAGE_ThreadCombat`
- ✅ `SAGE_ThreadClasses`
- ✅ `SAGE_ThreadInventory`
- ✅ `SAGE_ThreadDialogue`
- ✅ `SAGE_ThreadCinematics`
- ✅ `SAGE_ThreadQuests`
- ✅ `SAGE_ThreadUI`
- 🔧 `SAGE_ThreadAI` — Thread-aware AI behaviors (feature growth)

### Tools / Editor
- ✅ `SAGE_ThreadCoreEditor` — Editor tab, settings, menus.

---

## v0.2.x — The Thread Stirs (Now)
**Goal:** Lock core gameplay/world modules, enable end-to-end Blueprint usage, and stabilize Editor surface.

### Delivered
- All core gameplay/world subsystems compile and link together.
- Dialogue ↔ Print ↔ Quests ↔ Cinematics ↔ UI handshakes.
- Letterbox/HUD control through Cinematics + UI.
- Core Editor module with tab, menus, and project settings.
- Warnings cleanup (UE 5.6 include order, API deprecations).

### In Flight (0.2.1–0.2.3)
- 🔧 ThreadAI behavior hooks (perception → mood → action).
- 🔧 Debug overlay panel (ThreadSync, mood, quest step, cine state).
- 🔧 Event Bus (`UThreadEventHub`) for low-coupling cross-talk.
- 🔧 Boot Profiles (configurable init order + health checks).
- 🔧 Sample Blueprints per module (BP library parity).

### Acceptance for 0.2.x
- Play-in-Editor demo map: start → talk → quest tick → micro-cinematic → UI feedback loop.
- All public Blueprint functions documented in tooltips.
- Zero build errors on UE 5.6 + VS2022; warnings triaged.

---

## v0.3.x — The Thread Weaves (Next)
**Goal:** System Layer & Authoring

- 🧭 Authoring Assets:
  - Dialogue Graph Assets (speaker tags, conditional branches).
  - Quest Graph Assets (stages, conditions, rewards, ThreadPrint deltas).
  - Cinematic Profiles (camera rigs, mood curves, HUD policy).
- 🧭 Editor Utilities:
  - Thread Inspector (live view: mood, flags, recent deltas).
  - Event Trace (who emitted what, when).
- 🧭 Data Validation rules (soft fails with actionable messages).
- 🧭 Pluginization pass (clean public/private headers, module deps).

---

## v0.4.x — The Thread Learns
**Goal:** Tooling polish & creator experience.

- 🧭 Data-driven balancing (scalars for mood/aggro/loot/XP).
- 🧭 Asset templates & wizards (create quest/dialogue/cinematic in one click).
- 🧭 Sample Project: **“ThreadTest Island”** with fully playable loop.

---

## v0.5.x — The Thread Walks
**Goal:** Vertical Slice

- 🧭 Feature-locked content slice (15–30 min).
- 🧭 Performance pass (stat commands + built-in profile presets).
- 🧭 Packaging & distribution pipeline (Win64 first).

---

## Tech Debt / Risks
- Keep UE include-order current (`EngineIncludeOrderVersion.Unreal5_6`).
- Track UE deprecations (array RemoveAt/RemoveAll swap → `EAllowShrinking`).
- Hard ref checks between modules; prefer event hub to avoid cycles.

---

## Contributing
We accept PRs aligned with the roadmap.

**Style**  
- C++: UE code style, SAGE headers with version/codename.  
- Blueprint: Contextual categories (`SAGE|Dialogue`, etc.), rich tooltips.

**Branching**  
- `main` — stable.  
- `develop` — integration.  
- `feature/<module>-<short>` — focused changes.  
- `docs/roadmap` — roadmap and docs updates.

**Commit prefix**  
- `feat(Dialogue):` `fix(Cinematics):` `refactor(Core):` `docs(Roadmap):` etc.

---

## Legal
All code, names, and assets are **Intellectual Property of C38 ImagineWorks, LLC**.  
Clones/forks retain original copyright headers. PRs are contributions under the repository license unless otherwise stated.

**Contact:** info@c38imagineworks.com

---
_Last updated: {{TODAY}} — Maintainer: C38 ImagineWorks, LLC_