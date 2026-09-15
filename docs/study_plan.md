# DSA Study Plan — Primary Curriculum

This is the **primary learning path** for this repository. Follow it in order.

Do **not** start from Blind 75 / NeetCode checklists. Those are post-fluency drills after you can solve from the progressive topics below. See [`core_sheet/blind_75.md`](./core_sheet/blind_75.md) only after phases through DP feel comfortable.

**Language:** Modern C++17 (`g++ -std=c++17`)  
**Contract:** every problem is a paired `{name}.cpp` + `{name}.md` (11-section teaching note)  
**Floor:** each study-plan topic has **≥15** problems

---

## Prerequisite tracks (not in the 68-topic floor)

Complete or skim these before (or in parallel with early) the solving sequence. They are **not** counted in the 68-topic / 15-problem floor.

| Track | Path | Role |
|---|---|---|
| C++ language | [`00_cpp_fundamentals/`](../00_cpp_fundamentals/) | Syntax, STL, memory, OOP |
| DAA theory | [`00_daa_foundations/`](../00_daa_foundations/) | Asymptotics, recurrences, design techniques, amortized analysis |

---

## How to use this plan

1. Finish topics **in order** within a phase; finish a phase before skipping ahead unless a prereq note says otherwise.
2. For each problem: attempt blank → check `.md` intuition → study `.cpp` → re-solve later.
3. Topic folders link below; open the topic `README.md` for the local study order.
4. After interview patterns (through ~topic 37), use Blind 75 as a **checklist**, not a curriculum.

---

## Phase prerequisites

```text
00_cpp_fundamentals ─┐
00_daa_foundations  ─┼─→ 00_phase_problem_fundamentals (topics 1–4)
                     │
                     └─→ 01 … 10  (topics 01–44, interview patterns)
                                    │
                                    └─→ 11_phase_competitive_programming (topics 45–64)
```

| From | Into | Why |
|---|---|---|
| C++ / DAA tracks | Problem fundamentals | Need language + complexity vocabulary |
| Problem fundamentals (1–4) | Phase 01 patterns | Index / string / count / recursion fluency before named patterns |
| Two pointers (03) + arrays | Sliding window, prefix, later intervals | Shared scan vocabulary |
| Phases 01–10 | Phase 11 CP | Mo’s, centroid, suffix, etc. assume graph/DP/segtree comfort |

---

## Study-plan topics (68) — all ≥15 problems

### Phase 00 — Problem fundamentals (local IDs 1–4)

*Solving practice before named interview patterns. Not the same as `00_cpp_fundamentals` / `00_daa_foundations`.*

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 1 | Basic array traversal | **15** | [`01_basic_array_traversal/README.md`](../00_phase_problem_fundamentals/01_basic_array_traversal/README.md) |
| 2 | Basic string manipulation | **15** | [`02_basic_string_manipulation/README.md`](../00_phase_problem_fundamentals/02_basic_string_manipulation/README.md) |
| 3 | Frequency counting | **15** | [`03_frequency_counting/README.md`](../00_phase_problem_fundamentals/03_frequency_counting/README.md) |
| 4 | Recursion fundamentals | **15** | [`04_recursion_fundamentals/README.md`](../00_phase_problem_fundamentals/04_recursion_fundamentals/README.md) |

Phase overview: [`00_phase_problem_fundamentals/README.md`](../00_phase_problem_fundamentals/README.md)

---

### Phase 01 — Arrays, strings, hashing (topics 01–05)

**Prereq:** fundamentals 1–3 (array/string/count fluency).

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 01 | Arrays & strings | **29** (≥15) | [`01_arrays_strings/README.md`](../01_phase_arrays_strings_hashing/01_arrays_strings/README.md) |
| 02 | Hash maps & sets | **21** (≥15) | [`02_hash_maps_sets/README.md`](../01_phase_arrays_strings_hashing/02_hash_maps_sets/README.md) |
| 03 | Two pointers | **15** | [`03_two_pointers/README.md`](../01_phase_arrays_strings_hashing/03_two_pointers/README.md) |
| 04 | Sliding window | **15** | [`04_sliding_window/README.md`](../01_phase_arrays_strings_hashing/04_sliding_window/README.md) |
| 05 | Prefix sum | **15** | [`05_prefix_sum/README.md`](../01_phase_arrays_strings_hashing/05_prefix_sum/README.md) |

---

### Phase 02 — Searching & sorting (topics 06–08)

**Prereq:** phase 01.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 06 | Sorting techniques | **15** | [`06_sorting_techniques/README.md`](../02_phase_searching_sorting/06_sorting_techniques/README.md) |
| 07 | Binary search | **45** (≥15) | [`07_binary_search/README.md`](../02_phase_searching_sorting/07_binary_search/README.md) |
| 08 | Cyclic sort | **15** | [`08_cyclic_sort/README.md`](../02_phase_searching_sorting/08_cyclic_sort/README.md) |

---

### Phase 03 — Linked lists (topics 09–10)

**Prereq:** two pointers (03); recursion fundamentals (4) helpful.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 09 | Fast & slow pointers | **15** | [`09_fast_and_slow_pointers/README.md`](../03_phase_linked_lists/09_fast_and_slow_pointers/README.md) |
| 10 | Linked list manipulation | **15** | [`10_linked_list_manipulation/README.md`](../03_phase_linked_lists/10_linked_list_manipulation/README.md) |

---

### Phase 04 — Stacks & queues (topics 11–13)

**Prereq:** arrays / two pointers.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 11 | Stacks | **18** (≥15) | [`11_stacks/README.md`](../04_phase_stacks_queues/11_stacks/README.md) |
| 12 | Queues & deque | **15** | [`12_queues_deque/README.md`](../04_phase_stacks_queues/12_queues_deque/README.md) |
| 13 | Monotonic stack | **15** | [`13_monotonic_stack/README.md`](../04_phase_stacks_queues/13_monotonic_stack/README.md) |

---

### Phase 05 — Trees (topics 14–17)

**Prereq:** recursion (4), queues (12) for BFS.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 14 | Binary trees | **15** | [`14_binary_trees/README.md`](../05_phase_trees/14_binary_trees/README.md) |
| 15 | Tree DFS pattern | **15** | [`15_tree_dfs_pattern/README.md`](../05_phase_trees/15_tree_dfs_pattern/README.md) |
| 16 | Tree BFS pattern | **15** | [`16_tree_bfs_pattern/README.md`](../05_phase_trees/16_tree_bfs_pattern/README.md) |
| 17 | Binary search trees | **15** | [`17_binary_search_trees/README.md`](../05_phase_trees/17_binary_search_trees/README.md) |

---

### Phase 06 — Heaps & intervals (topics 18–21)

**Prereq:** sorting (06); two pointers (03) for interval endpoints; heaps for top-K / two-heaps.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 18 | Top-K elements | **15** | [`18_top_k_elements/README.md`](../06_phase_heaps_intervals/18_top_k_elements/README.md) |
| 19 | Two heaps | **15** | [`19_two_heaps/README.md`](../06_phase_heaps_intervals/19_two_heaps/README.md) |
| 20 | Merge intervals | **15** | [`20_merge_intervals/README.md`](../06_phase_heaps_intervals/20_merge_intervals/README.md) |
| 21 | K-way merge | **15** | [`21_k_way_merge/README.md`](../06_phase_heaps_intervals/21_k_way_merge/README.md) |

---

### Phase 07 — Recursion & backtracking (topics 22–23)

**Prereq:** recursion fundamentals (4).

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 22 | Subsets pattern | **15** | [`22_subsets_pattern/README.md`](../07_phase_recursion_backtracking/22_subsets_pattern/README.md) |
| 23 | Backtracking | **15** | [`23_backtracking/README.md`](../07_phase_recursion_backtracking/23_backtracking/README.md) |

---

### Phase 08 — Graphs (topics 24–29)

**Prereq:** BFS/DFS tree intuition (15–16); union-find after graph basics.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 24 | Graph basics | **15** | [`24_graph_basics/README.md`](../08_phase_graphs/24_graph_basics/README.md) |
| 25 | DFS on graphs | **15** | [`25_dfs_on_graphs/README.md`](../08_phase_graphs/25_dfs_on_graphs/README.md) |
| 26 | BFS on graphs | **15** | [`26_bfs_on_graphs/README.md`](../08_phase_graphs/26_bfs_on_graphs/README.md) |
| 27 | Topological sort | **15** | [`27_topological_sort/README.md`](../08_phase_graphs/27_topological_sort/README.md) |
| 28 | Union-find | **15** | [`28_union_find/README.md`](../08_phase_graphs/28_union_find/README.md) |
| 29 | Classic graph algorithms | **15** | [`29_classic_graph_algorithms/README.md`](../08_phase_graphs/29_classic_graph_algorithms/README.md) |

---

### Phase 09 — Dynamic programming (topics 30–37)

**Prereq:** recursion (4); graphs helpful for DP-on-trees / paths.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 30 | 1D DP | **15** | [`30_1d_dp/README.md`](../09_phase_dynamic_programming/30_1d_dp/README.md) |
| 31 | 2D DP | **15** | [`31_2d_dp/README.md`](../09_phase_dynamic_programming/31_2d_dp/README.md) |
| 32 | Grid DP | **15** | [`32_grid_dp/README.md`](../09_phase_dynamic_programming/32_grid_dp/README.md) |
| 33 | Knapsack pattern | **15** | [`33_knapsack_pattern/README.md`](../09_phase_dynamic_programming/33_knapsack_pattern/README.md) |
| 34 | Longest sequence pattern | **15** | [`34_longest_sequence_pattern/README.md`](../09_phase_dynamic_programming/34_longest_sequence_pattern/README.md) |
| 35 | DP on strings | **15** | [`35_dp_on_strings/README.md`](../09_phase_dynamic_programming/35_dp_on_strings/README.md) |
| 36 | Bitmask DP | **15** | [`36_bitmask_dp/README.md`](../09_phase_dynamic_programming/36_bitmask_dp/README.md) |
| 37 | DP on trees | **15** | [`37_dp_on_trees/README.md`](../09_phase_dynamic_programming/37_dp_on_trees/README.md) |

---

### Phase 10 — Advanced topics (topics 38–44)

**Prereq:** solid graphs + DP; bit / math / strings as needed per topic.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 38 | Trie | **15** | [`38_trie/README.md`](../10_phase_advanced_topics/38_trie/README.md) |
| 39 | Greedy algorithms | **15** | [`39_greedy_algorithms/README.md`](../10_phase_advanced_topics/39_greedy_algorithms/README.md) |
| 40 | Bit manipulation | **15** | [`40_bit_manipulation/README.md`](../10_phase_advanced_topics/40_bit_manipulation/README.md) |
| 41 | Mathematical algorithms | **15** | [`41_mathematical_algorithms/README.md`](../10_phase_advanced_topics/41_mathematical_algorithms/README.md) |
| 42 | Shortest paths & flows | **20** (≥15) | [`42_shortest_paths_flows/README.md`](../10_phase_advanced_topics/42_shortest_paths_flows/README.md) |
| 43 | Segment tree & Fenwick | **15** | [`43_segment_tree_fenwick_tree/README.md`](../10_phase_advanced_topics/43_segment_tree_fenwick_tree/README.md) |
| 44 | String algorithms | **15** | [`44_string_algorithms/README.md`](../10_phase_advanced_topics/44_string_algorithms/README.md) |

---

### Phase 11 — Competitive programming (topics 45–64)

**Prereq:** phases 01–10 (especially graphs, DP, segment trees, strings). Each CP folder is its own 15-problem topic.

| # | Topic | Problems | Folder README |
|---:|---|---:|---|
| 45 | Number theory | **15** | [`45_number_theory/README.md`](../11_phase_competitive_programming/45_number_theory/README.md) |
| 46 | Combinatorics | **15** | [`46_combinatorics/README.md`](../11_phase_competitive_programming/46_combinatorics/README.md) |
| 47 | Game theory | **15** | [`47_game_theory/README.md`](../11_phase_competitive_programming/47_game_theory/README.md) |
| 48 | Advanced math | **15** | [`48_advanced_math/README.md`](../11_phase_competitive_programming/48_advanced_math/README.md) |
| 49 | Geometry | **15** | [`49_geometry/README.md`](../11_phase_competitive_programming/49_geometry/README.md) |
| 50 | CP templates | **15** | [`50_cp_templates/README.md`](../11_phase_competitive_programming/50_cp_templates/README.md) |
| 51 | Mo’s algorithm | **15** | [`51_mos_algorithm/README.md`](../11_phase_competitive_programming/51_mos_algorithm/README.md) |
| 52 | Coordinate compression | **15** | [`52_coordinate_compression/README.md`](../11_phase_competitive_programming/52_coordinate_compression/README.md) |
| 53 | Sweep line | **15** | [`53_sweep_line/README.md`](../11_phase_competitive_programming/53_sweep_line/README.md) |
| 54 | Euler tour / LCA | **15** | [`54_euler_tour_lca/README.md`](../11_phase_competitive_programming/54_euler_tour_lca/README.md) |
| 55 | Centroid decomposition | **15** | [`55_centroid_decomposition/README.md`](../11_phase_competitive_programming/55_centroid_decomposition/README.md) |
| 56 | Topological DP | **15** | [`56_topological_dp/README.md`](../11_phase_competitive_programming/56_topological_dp/README.md) |
| 57 | Bipartite matching | **15** | [`57_bipartite_matching/README.md`](../11_phase_competitive_programming/57_bipartite_matching/README.md) |
| 58 | Johnson APSP | **15** | [`58_johnson_apsp/README.md`](../11_phase_competitive_programming/58_johnson_apsp/README.md) |
| 59 | Suffix structures | **15** | [`59_suffix_structures/README.md`](../11_phase_competitive_programming/59_suffix_structures/README.md) |
| 60 | Aho–Corasick | **15** | [`60_aho_corasick/README.md`](../11_phase_competitive_programming/60_aho_corasick/README.md) |
| 61 | Persistent structures | **15** | [`61_persistent_structures/README.md`](../11_phase_competitive_programming/61_persistent_structures/README.md) |
| 62 | Skip list / Bloom | **15** | [`62_skip_list_bloom/README.md`](../11_phase_competitive_programming/62_skip_list_bloom/README.md) |
| 63 | Randomized complexity lab | **15** | [`63_randomized_complexity_lab/README.md`](../11_phase_competitive_programming/63_randomized_complexity_lab/README.md) |
| 64 | Meet in the middle | **15** | [`64_meet_in_the_middle/README.md`](../11_phase_competitive_programming/64_meet_in_the_middle/README.md) |

---

## Floor status

| Scope | Topics | Status |
|---|---:|---|
| Problem fundamentals (1–4) | 4 | All ≥15 |
| Interview topics (01–44) | 44 | All ≥15 |
| CP topics (45–64) | 20 | All ≥15 |
| **Study-plan total** | **68** | **Complete** |

Some older topics intentionally exceed 15 (e.g. binary search, arrays). The floor is a minimum, not a cap.

---

## Related docs

| Doc | Role |
|---|---|
| **This file** | Primary curriculum |
| [`core_sheet/blind_75.md`](./core_sheet/blind_75.md) | Post-fluency checklist |
| [`company_packs/`](./company_packs/) | Company frequency packs |
| [`legacy_study_plan.md`](./legacy_study_plan.md) | Legacy draft — prefer this file instead |
| [`README.md`](./README.md) | Docs hub |
| [`../README.md`](../README.md) | Repo overview & how to compile |

---

## Compile gate

```bash
bash test/compile_all.sh
```

Uses `g++ -std=c++17` (override with `CXX=clang++`) across foundations, problem fundamentals, and phases 01–11.
