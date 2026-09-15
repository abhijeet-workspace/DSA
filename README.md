# DSA + DAA Learning Repository (Modern C++17)

Structured path from **C++ language mastery** and **DAA theory** → **problem fundamentals** → interview patterns → advanced algorithms → competitive programming.

**Start here:** [`docs/study_plan.md`](docs/study_plan.md) — primary 68-topic curriculum (all topics ≥15 paired problems).

Each teaching solution is a paired `{name}.cpp` + `{name}.md`: runnable Modern C++17 with a walkthrough (intuition, complexity, edge cases, interview follow-ups).

---

## Documentation

| Doc | Role |
|---|---|
| **[`docs/study_plan.md`](docs/study_plan.md)** | **Primary curriculum** — ordered phases, prereqs, topic README links |
| [`docs/core_sheet/blind_75.md`](docs/core_sheet/blind_75.md) | Post-fluency checklist (not a starting path) |
| [`docs/company_packs/`](docs/company_packs/) | Company frequency packs |
| [`docs/legacy_study_plan.md`](docs/legacy_study_plan.md) | Legacy draft — prefer `docs/study_plan.md` |
| [`docs/README.md`](docs/README.md) | Docs hub |

---

## Coverage (live scan)

| Area | Topics | `.cpp` |
|---|---:|---:|
| C++ fundamentals | 11 | 92 |
| DAA foundations | 4 | 4 |
| Problem fundamentals (`00_phase_problem_fundamentals`) | 4 | 60 |
| Phases 01–10 (interview patterns, topics 01–44) | 44 | 718 |
| Phase 11 (competitive programming, topics 45–64) | 20 | **300** |
| **Teaching total** | — | **~1,174** |

- Study-plan floor: **68 topics**, each with **≥15** paired `.cpp` / `.md` problems (~1,078 pairs in the solving path).
- Language standard: **C++17** (`g++ -std=c++17`).
- CI compiles teaching sources on push/PR (`test/compile_all.sh`), including problem fundamentals.

---

## Repository structure

```
DSA/
├── docs/                              Study plan, Blind 75, company packs
│   └── study_plan.md                  Primary curriculum (start here)
├── 00_cpp_fundamentals/               C++ language mastery (prereq track)
├── 00_daa_foundations/                Asymptotics, recurrences, design, amortized
├── 00_phase_problem_fundamentals/    Topics 1–4 (study-plan start)
├── 01_phase_arrays_strings_hashing/   Topics 01–05
├── 02_phase_searching_sorting/        Topics 06–08
├── 03_phase_linked_lists/             Topics 09–10
├── 04_phase_stacks_queues/            Topics 11–13
├── 05_phase_trees/                    Topics 14–17
├── 06_phase_heaps_intervals/          Topics 18–21
├── 07_phase_recursion_backtracking/   Topics 22–23
├── 08_phase_graphs/                   Topics 24–29
├── 09_phase_dynamic_programming/      Topics 30–37
├── 10_phase_advanced_topics/          Topics 38–44
├── 11_phase_competitive_programming/  Topics 45–64 (20 topics × 15 = 300 .cpp)
├── projects/order-book-exchange/      Applied C++17 project (order book)
├── test/compile_all.sh                Repo-wide compile gate
└── .github/workflows/ci.yml           GitHub Actions CI
```

Topic IDs **01–64** are globally unique under phases 01–11. Problem fundamentals use local IDs **1–4** under `00_phase_problem_fundamentals/` (separate from global 01–64).

---

## Curriculum map

### Prerequisite tracks (not in the 68-topic floor)

| Phase | Focus | Topics |
|---|---|---|
| `00_cpp_fundamentals` | Language mastery | language basics, pointers/memory, structs/unions, OOP, STL, files/preprocessor, classic algorithms, builtins, modern C++, bit manipulation, mathematics |
| `00_daa_foundations` | Algorithm analysis | asymptotic analysis, recurrence relations, design techniques, amortized analysis |

### Study-plan solving sequence

| Phase | Topics |
|---|---|
| **00 problem fundamentals** | `1` array traversal · `2` string manipulation · `3` frequency counting · `4` recursion fundamentals |
| **01** Arrays / strings / hashing | `01` arrays & strings · `02` hash maps/sets · `03` two pointers · `04` sliding window · `05` prefix sum |
| **02** Searching / sorting | `06` sorting techniques · `07` binary search · `08` cyclic sort |
| **03** Linked lists | `09` fast & slow pointers · `10` list manipulation |
| **04** Stacks / queues | `11` stacks · `12` queues & deque · `13` monotonic stack |
| **05** Trees | `14` binary trees · `15` DFS pattern · `16` BFS pattern · `17` BSTs |
| **06** Heaps / intervals | `18` top-K · `19` two heaps · `20` merge intervals · `21` k-way merge |
| **07** Recursion / backtracking | `22` subsets pattern · `23` backtracking |
| **08** Graphs | `24` basics · `25` DFS · `26` BFS · `27` topological sort · `28` union-find · `29` classic algorithms |
| **09** Dynamic programming | `30` 1D · `31` 2D · `32` grid · `33` knapsack · `34` longest sequence · `35` strings · `36` bitmask · `37` trees |
| **10** Advanced | `38` trie · `39` greedy · `40` bits · `41` math algorithms · `42` shortest paths / flows · `43` segment & Fenwick · `44` string algorithms |
| **11** Competitive programming | `45`–`64` (number theory → meet-in-the-middle); **300** `.cpp` files |

Full ordered tables and topic README links: [`docs/study_plan.md`](docs/study_plan.md).

---

## Learning tracks

### Track 1 — Software engineering interview (~8–10 weeks)

Problem fundamentals → arrays/hashing → linked lists / stacks / binary search → trees / heaps → graphs → 1D/2D DP (follow [`docs/study_plan.md`](docs/study_plan.md)).

Then drill [Blind 75](docs/core_sheet/blind_75.md) as a checklist.

### Track 2 — Product company / onsite depth (~12–14 weeks)

Track 1 + advanced graphs (**29**, **42**) + grid / bitmask / tree DP + tries / segment trees / string algorithms (**38–44**) + mocks.

### Track 3 — Competitive programming (~20 weeks)

Track 2 + phase **11** (topics **45–64**). After starters, drill on CSES / Codeforces.

---

## How to run a solution

```bash
# Single file
g++ -std=c++17 -Wall -Wextra -O2 \
  01_phase_arrays_strings_hashing/01_arrays_strings/best_time_to_buy_sell_stock.cpp \
  -o /tmp/demo && /tmp/demo

# Repo-wide compile check (matches CI)
bash test/compile_all.sh
```

CI flags (from `test/compile_all.sh`):

```text
-std=c++17 -Wall -Wextra -Werror -O0
```

Override compiler with `CXX=clang++ bash test/compile_all.sh` if needed.

---

## Solution format

Every teaching problem follows the same contract.

**`{name}.md`** — problem statement, intuition, brute → optimal, justification, walkthrough, dry run, complexity, trade-offs, edge cases, interview follow-ups, tags (`## 1.` … `## 11.`).

**`{name}.cpp`** — C++17 implementation with a small `main()` demo and expected outputs in comments/prints.

Conventions:

1. Paired files: `{name}.cpp` + `{name}.md` in the same topic folder.
2. No `using namespace std;` in teaching solutions.
3. Prefer `const` references and clear naming over clever one-liners.
4. Topic folder IDs are unique within the study-plan numbering scheme above.

Example:

```text
01_phase_arrays_strings_hashing/01_arrays_strings/
  best_time_to_buy_sell_stock.cpp
  best_time_to_buy_sell_stock.md
```

---

## Applied project

[`projects/order-book-exchange/`](projects/order-book-exchange/) — C++17 order-book / trading engine sketch (CMake, core types, tests).

```bash
cd projects/order-book-exchange
# see CMakeLists.txt / run.sh for local build
```

---

## Coding standards

| Rule | Detail |
|---|---|
| Standard | C++17 |
| Pairing | Every teaching `.cpp` ships with a `.md` |
| Namespace | Qualify `std::` explicitly |
| Warnings | Treat warnings as errors in CI (`-Werror`) |
| Naming | `snake_case` problem files; numbered topic folders (`NN_topic_name`) |
| Scope | Prefer minimal, readable demos over framework code |

---

## Contributing (local workflow)

1. Pick the correct phase / topic ID from [`docs/study_plan.md`](docs/study_plan.md).
2. Add `{name}.cpp` and `{name}.md` together.
3. Keep the `.md` sections consistent with neighboring problems (`## 1.`–`## 11.`).
4. Run `bash test/compile_all.sh` before committing.
5. Do not commit binaries (`*.out`, `a.out`) — already gitignored.

---

## Quick navigation

| Area | Path |
|---|---|
| **Study plan** | [`docs/study_plan.md`](docs/study_plan.md) |
| C++ fundamentals | [`00_cpp_fundamentals/`](00_cpp_fundamentals/) |
| DAA foundations | [`00_daa_foundations/`](00_daa_foundations/) |
| Problem fundamentals | [`00_phase_problem_fundamentals/`](00_phase_problem_fundamentals/) |
| Arrays → hashing | [`01_phase_arrays_strings_hashing/`](01_phase_arrays_strings_hashing/) |
| Searching / sorting | [`02_phase_searching_sorting/`](02_phase_searching_sorting/) |
| Linked lists | [`03_phase_linked_lists/`](03_phase_linked_lists/) |
| Stacks / queues | [`04_phase_stacks_queues/`](04_phase_stacks_queues/) |
| Trees | [`05_phase_trees/`](05_phase_trees/) |
| Heaps / intervals | [`06_phase_heaps_intervals/`](06_phase_heaps_intervals/) |
| Recursion / backtracking | [`07_phase_recursion_backtracking/`](07_phase_recursion_backtracking/) |
| Graphs | [`08_phase_graphs/`](08_phase_graphs/) |
| Dynamic programming | [`09_phase_dynamic_programming/`](09_phase_dynamic_programming/) |
| Advanced topics | [`10_phase_advanced_topics/`](10_phase_advanced_topics/) |
| Competitive programming | [`11_phase_competitive_programming/`](11_phase_competitive_programming/) |
| Blind 75 checklist | [`docs/core_sheet/blind_75.md`](docs/core_sheet/blind_75.md) |
| Company packs | [`docs/company_packs/`](docs/company_packs/) |
| Order book project | [`projects/order-book-exchange/`](projects/order-book-exchange/) |
| Compile gate | [`test/compile_all.sh`](test/compile_all.sh) |

---

## License / intent

Personal learning and interview preparation library. Use the solutions to study patterns, not to submit elsewhere as your own work during assessments.
