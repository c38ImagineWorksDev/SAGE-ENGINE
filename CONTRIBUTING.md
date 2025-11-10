# 🕸️ CONTRIBUTING TO SAGE
### SYNTHREAD ADVANCED GAME ENGINE (SAGE)
**“Born from Making Reality from Your Imagination.”**

---

## 🔒 Access & Contribution Policy
The **S.Y.N.T.H.R.E.A.D. Advanced Game Engine (SAGE)** is a proprietary framework maintained by **C38 ImagineWorks LLC**.  
At this time, contributions are **invitation-only** and limited to verified internal developers, approved collaborators, and licensed studio partners under active NDA.

If you believe your expertise aligns with SAGE’s development philosophy and you’d like to collaborate, reach out directly:  
📧 **c38imagineworks@gmail.com**

---

## 🔁 Branching & Version Control
SAGE uses a protected Git flow built around deliberate, stable iteration.

| Branch | Purpose |
|---------|----------|
| `main` | Production-ready, stable builds only. |
| `dev` | Active development branch — volatile, experimental. |
| `feature/*` | Dedicated feature branches (e.g. `feature/threadprint-refactor`). |
| `hotfix/*` | Critical fixes applied post-release. |
| `docs/*` | Documentation and Markdown updates only. |

All code is reviewed before merging to `main`.  
Pull requests must be descriptive, well-documented, and traceable to a specific version milestone.

---

## ⚙️ Structure & Style
Even in prototyping, discipline matters.  
Every line, node, and variable in SAGE carries narrative and mechanical consequence.

### 📁 Folder Hierarchy
Organize all assets under `/Source/` using this structure:

/SAGE_ThreadCore/
/SAGE_ThreadPrint/
/SAGE_ThreadUI/
/SAGE_ThreadCinematics/
/SAGE_ThreadDialogue/
/SAGE_ThreadWorld/
/SAGE_ThreadQuests/
etc.


### ✍🏾 Variable & Class Naming
- **C++:** PascalCase for classes, camelCase for variables.  
- **Blueprints:** PascalCase for public variables, `_` prefix for privates.  
- No “Temp1” or “Thingy.” Every name reflects its intent.  

### 💬 Comments & Documentation
- Use inline comments to explain *why*, not just *what*.  
- Blueprint graphs should flow logically with reroute nodes for readability.  
- Each function and event should have a description header.

---

## 🧵 Contribution Philosophy
> “This engine should not exist — but we’re building it anyway.”

SAGE is built on rebellion: against disposable code, soulless systems, and hollow design.  
Every module, every subsystem, every comment is part of the weave.  

Build with memory.  
Design with consequence.  
Respect the Thread.

---

## 🧠 Final Guidelines
- Never push directly to `main` without approval.  
- Keep all Blueprints and graphs clean, aligned, and labeled.  
- External libraries or assets must be cleared by **C38 ImagineWorks** before integration.  
- Each contribution should leave the engine more alive, not just more complex.

---

### 🪶 Closing Note
Thank you for helping weave the impossible.  
Together, we are building the first emotionally reactive engine in modern gaming.  

— **C38 ImagineWorks LLC**  
🕸️ *“The Thread Remembers.”*
