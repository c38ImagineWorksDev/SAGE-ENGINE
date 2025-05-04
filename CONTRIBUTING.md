# CONTRIBUTING TO SAGE
## SYNTHREAD ADVANCED GAME ENGINE – PRIVATE CONTRIBUTION GUIDELINES

Welcome to the inner sanctum.

The SYNTHREAD ADVANCED GAME ENGINE (SAGE) is a proprietary development framework maintained by **C38 ImagineWorks**. At this time, contributions are limited to internal developers, approved collaborators, or licensed partners working under signed agreements.

---

## 🔒 WHO CAN CONTRIBUTE?

Contributions are currently **invitation-only** and must be pre-approved by C38 ImagineWorks. Any collaborator must sign an NDA and a custom licensing agreement before gaining access.

If you are interested in contributing or collaborating, email:

**📧 c38imagineworks@gmail.com**

---

## 🔁 BRANCHING STRATEGY

We use a protected and deliberate Git flow structure:

- `master` — Stable production-ready code. Only reviewed & approved merges go here.
- `dev` — Experimental or ongoing work. Can be volatile.
- `feature/*` — Specific feature branches (e.g. `feature/threadprint-core`)
- `hotfix/*` — For emergency fixes or patch releases
- `docs/*` — For readme, wiki, and documentation updates

**All code must be reviewed by a lead developer before merging into `master`.**

---

## 🔧 BLUEPRINT AND C++ STRUCTURE

Even in early prototyping, we honor sacred conventions:

### 📁 Folder Structure
Use the following format:

/SAGE_Core/
/SAGE_Blueprints/
/SAGE_Structs/
/SAGE_Functions/
/SAGE_UI/
/SAGE_Docs/
/SAGE_DeveAssets/
/SAGE_Effects/
/SAGE_Tests/


### ✍🏾 Variable Naming (Blueprint)
- PascalCase for public variables (e.g. `TargetName`, `ThreadPrintLog`)
- Prefix private vars with `_` if needed
- Use clear, intention-driven names (no vague `Temp1`, `Stuff`, etc.)

### ⚙️ Commenting
- All major Blueprint sections must be commented
- Use reroute nodes to improve readability
- Custom events and dispatchers must have labels

---

## 🧵 CONTRIBUTION PHILOSOPHY

> "This engine should not exist…  
But we’re building it anyway."

SAGE is a rebellion against traditional design, memory-less code, and disposable interactions. Every node, function, and comment is a stitch in a larger weave.

Build with purpose.  
Design with consequence.  
Respect the Thread.

---

## 🧠 FINAL NOTES

- Do not push to `master` directly unless instructed.
- Keep your Blueprint graphs clean and readable.
- All Pull Requests will be reviewed before merging.
- Contact **C38 ImagineWorks** before integrating outside libraries or assets.

---

Thank you for helping thread the impossible.  
— C38 ImagineWorks
