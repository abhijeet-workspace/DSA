# Map Basics

## 1. Problem Statement
Demonstrate `std::map` (sorted key-value tree) and `std::unordered_map` (hash table): insert, iterate, and lookup.

- **Input:** string→int ages and string→double prices
- **Output:** printed entries; successful finds for Rahul/Banana
- **Valid answer:** map iterates keys in order; unordered_map does not
- **Edge cases:** `operator[]` default-inserts missing keys; prefer `find`/`at` when that is unwanted

## 2. Intuition
Associate keys with values. Choose ordered tree maps for sorted traversal/ranges; choose hash maps for average O(1) point queries.

## 3. Brute Force → Optimal
- **Naive:** parallel vectors of keys/values + linear scan.
- **This approach:** associative containers with logarithmic or average-constant ops.

## 4. Data Structure / Approach Justification
**Chosen:** `map` vs `unordered_map` shown side by side.

| Alternative | Why it loses here |
|-------------|-------------------|
| `vector<pair>` + sort | Good bulk build; weaker for mixed updates |
| `set` of pairs | Awkward value updates |
| Always hash map | No ordered ranges / lower_bound |

Trade-off: trees slower but ordered; hashes faster average, unordered, need hashable keys.

## 5. Logic Walkthrough
1. Fill `ageMap` via `[]` and `insert`.
2. Range-for with structured bindings prints sorted keys.
3. `find("Rahul")` then read age.
4. Fill `priceMap`; iterate arbitrary order; `count` then read Banana.

## 6. Dry Run
| map keys sorted | Amit, Bob, Rahul, Zack |
|-----------------|------------------------|
| find Rahul | 21 |
| unordered prices | Apple/Banana/Orange any order |
| Banana | 0.59 |

## 7. Time & Space Complexity
- **map ops:** O(log n)
- **unordered_map average:** O(1); worst O(n)
- **Space:** O(n)
- Why: RB-tree vs hash buckets

## 8. Trade-offs & Alternatives
- Prefer `unordered_map` for hot point lookups without order.
- Prefer `map` for sorted reports / closest-key queries.
- Prefer `try_emplace`/`insert_or_assign` to avoid accidental default inserts.

## 9. Common Mistakes / Edge Cases
- `m[key]` creating zero/default entries during "contains" checks
- Assuming unordered iteration is stable across runs
- Using map where a plain `vector` of pairs suffices

## 10. Interview Follow-ups / Variations
- map vs unordered_map decision checklist?
- How does `operator[]` differ from `at`/`find`?
- Custom key types: comparator vs hash/eq?

## 11. Tags
`stl`, `map`, `unordered_map`, `hash-table`, `difficulty:easy`
