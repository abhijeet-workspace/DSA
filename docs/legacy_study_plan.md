# Legacy Study Plan — Zero → Advanced DSA & DAA

> **Superseded.** Use the primary curriculum: [`study_plan.md`](./study_plan.md).
> This file is kept only as a historical draft.

Single older curriculum draft. Prefer [`study_plan.md`](./study_plan.md), then [company packs](./company_packs/) when targeting a company.

**Language:** Modern C++17  
**Core drill set:** [Blind 75](./core_sheet/blind_75.md) (after Phase 01–09 basics)

---

## How to use

| Rule | Detail |
|---|---|
| Order | Finish each stage’s theory + demos before skipping ahead |
| Daily | 1–2 new problems + 1 review (45–90 min) |
| Blank solve | Re-solve without peeking after 1 day and 1 week |
| Company focus | After Stage 6, pick one [company pack](./company_packs/) |
| Complexity | Always state time/space and edge cases out loud |

Suggested total: **~16–20 weeks** at steady pace (faster if C++ is already solid).

---

## Stage 0 — C++ foundations (1–2 weeks)

**Folder:** [`00_cpp_fundamentals/`](../00_cpp_fundamentals/)

| Focus | Why |
|---|---|
| Types, control flow, functions, arrays/strings | Interview coding fluency |
| Pointers, heap vs stack, dynamic memory | Avoid segfaults / ownership bugs |
| Structs, OOP, STL containers | Write clean solutions fast |
| Classic search/sort demos + modern C++17 | Language tools you will reuse |

**Exit criteria:** You can implement two-pointers / hash-map solutions without fighting the language.

---

## Stage 1 — DAA foundations (3–5 days)

**Folder:** [`00_daa_foundations/`](../00_daa_foundations/)

| Topic | Folder |
|---|---|
| Asymptotic analysis (Big-O / Θ / Ω) | `01_asymptotic_analysis` |
| Recurrences / Master Theorem | `02_recurrence_relations` |
| Design techniques (divide & conquer, greedy, DP, backtracking) | `03_algorithm_design_techniques` |
| Amortized analysis | `04_amortized_analysis` |

**Exit criteria:** You can justify complexities and name the design paradigm for a new problem.

---

## Stage 2 — Core patterns (3–4 weeks)

| Week | Phase | Topics |
|---|---|---|
| 1 | [`01_phase_arrays_strings_hashing`](../01_phase_arrays_strings_hashing/) | Arrays/strings, hash maps/sets, two pointers, sliding window, prefix sum |
| 2 | [`02_phase_searching_sorting`](../02_phase_searching_sorting/) + [`03_phase_linked_lists`](../03_phase_linked_lists/) | Sorting, binary search, cyclic sort, fast/slow pointers, list manipulation |
| 3 | [`04_phase_stacks_queues`](../04_phase_stacks_queues/) | Stacks, queues/deque, monotonic stack |
| 4 | [`05_phase_trees`](../05_phase_trees/) + [`06_phase_heaps_intervals`](../06_phase_heaps_intervals/) | Tree DFS/BFS, BST, top-K, two heaps, intervals, k-way merge |

**Drill:** Start [Blind 75](./core_sheet/blind_75.md) sections 1–8 as you finish matching topics.

---

## Stage 3 — Search space & graphs (2–3 weeks)

| Focus | Phase |
|---|---|
| Subsets / backtracking | [`07_phase_recursion_backtracking`](../07_phase_recursion_backtracking/) |
| Graph basics → DFS/BFS → topo → Union-Find → classic algs | [`08_phase_graphs`](../08_phase_graphs/) |

**Must-do patterns:** Number of Islands, Course Schedule, Clone Graph, Word Ladder, Accounts Merge, Alien Dictionary.

---

## Stage 4 — Dynamic programming & greedy (2–3 weeks)

| Focus | Phase |
|---|---|
| 1D / 2D / grid / knapsack / LIS / string / bitmask / tree DP | [`09_phase_dynamic_programming`](../09_phase_dynamic_programming/) |
| Greedy + bits + math + trie + paths/flows + segment/Fenwick + strings | [`10_phase_advanced_topics`](../10_phase_advanced_topics/) |

**Must-do patterns:** Climbing Stairs → Coin Change → LIS → Edit Distance → Unique Paths → Knapsack family → Jump Game → Gas Station.

Finish remaining [Blind 75](./core_sheet/blind_75.md).

---

## Stage 5 — Product / FAANG interview depth (2 weeks)

1. Re-solve Blind 75 under timer (20–25 min Easy, 30–40 Medium, 45 Hard).
2. Pick **one** company pack and complete it: [company_packs/](./company_packs/).
3. Second company pack for your backup target.
4. Practice: complexity narration, edge cases, follow-up variants (space → time tradeoffs).

---

## Stage 6 — Advanced / CP (optional, 3–6 weeks)

**Folder:** [`11_phase_competitive_programming`](../11_phase_competitive_programming/)

| Block | Topics |
|---|---|
| 45–50 | Number theory, combinatorics, game theory, advanced math, geometry, templates |
| 51–58 | Mo’s, compression, sweep line, Euler/LCA, centroid, topo DP, matching, Johnson |
| 59–63 | Suffix structures, Aho-Corasick, persistent DS, skip list/Bloom, randomized/complexity lab |

Use after interviews stabilize, or if targeting hard onsite / CP contests.

---

## Milestone checklist

- [ ] Stage 0–1 complete (C++ + DAA theory comfortable)
- [ ] Stages 2–4 complete (patterns through DP)
- [ ] Blind 75 blank-solved once
- [ ] At least one company pack finished
- [ ] Can explain Big-O + approach + edges for every solved problem

---

## What this plan replaces

Previous archive held overlapping tracks (Blind 75 + NeetCode 150 + Top Interview 150 + Grind 169 + Striver + mocks). Those duplicated the same problems. **This file is the only study path.** Company packs are targeting overlays, not alternate curricula.
