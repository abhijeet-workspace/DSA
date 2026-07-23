# STL Utilities & Algorithms

## 1. Problem Statement
Demonstrate `std::pair`/`std::tuple` (access + `tie` unpack) and algorithms `sort`, `find`, `binary_search`, `lower_bound` on a vector.

- **Input:** sample pair/tuple and vector `{40,10,50,20,30}`
- **Output:** printed fields; sorted `10 20 30 40 50`; finds and lower_bound results
- **Valid answer:** binary search APIs used only after sorting
- **Edge cases:** `binary_search`/`lower_bound` on unsorted ranges are meaningless

## 2. Intuition
Small fixed heterogeneous bundles → `pair`/`tuple`. Generic iterator-based algorithms reuse the same logic across containers that expose the right iterators.

## 3. Brute Force → Optimal
- **Naive:** hand-rolled sort/search for every container type.
- **This approach:** `<utility>`/`<tuple>` + `<algorithm>` on iterator ranges.

## 4. Data Structure / Approach Justification
**Chosen:** `pair`/`tuple` for bundled values; `vector` as the algorithm host.

| Alternative | Why it loses here |
|-------------|-------------------|
| Custom structs always | Better names long-term; heavier for tiny demos |
| C `qsort`/`bsearch` | Less type-safe; not idiomatic C++ |
| Linear search only | Fine small n; misses log n sorted tools |

Trade-off: tuples are anonymous — prefer named structs in domain code.

## 5. Logic Walkthrough
1. Create pair; read `.first`/`.second`.
2. Create tuple; read via `std::get<i>`; unpack with `std::tie`.
3. `sort` vector ascending.
4. `find` 30 linearly; `binary_search` 50 on sorted range.
5. `lower_bound(25)` → first element ≥ 25 (30).

## 6. Dry Run
| vec after sort | 10 20 30 40 50 |
|----------------|----------------|
| find 30 | index 2 |
| binary_search 50 | true |
| lower_bound 25 | 30 at index 2 |

## 7. Time & Space Complexity
- **sort:** O(n log n) time, O(log n) typical recursion space
- **find:** O(n)
- **binary_search / lower_bound:** O(log n) on random-access sorted ranges
- **pair/tuple:** O(1) access
- Why: comparison sort + binary search on contiguous iterators

## 8. Trade-offs & Alternatives
- Prefer structured bindings (`auto [a,b,c]=...`) over `tie` in C++17+.
- Prefer `std::partition_point` / ranges algorithms in modern codebases.
- Prefer named structs when fields have lasting domain meaning.

## 9. Common Mistakes / Edge Cases
- Binary searching an unsorted vector
- Assuming `find` requires sorted input (it does not)
- Out-of-range `get<N>` on tuples (compile error if N too large)

## 10. Interview Follow-ups / Variations
- lower_bound vs upper_bound vs equal_range?
- When is `stable_sort` required?
- How do comparison customizers (`comp`) work?

## 11. Tags
`stl`, `pair`, `tuple`, `sort`, `binary-search`, `difficulty:easy`
