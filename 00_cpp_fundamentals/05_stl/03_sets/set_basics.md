# STL Sets

## 1. Problem Statement
Compare `std::set`, `std::unordered_set`, and `std::multiset`: uniqueness, ordering, lookup, and erase-by-value vs erase-by-iterator.

- **Input:** none
- **Output:** contents and find/count/erase results
- **Valid answer:** set/unordered_set drop duplicates; multiset keeps them sorted
- **Edges:** `erase(key)` on multiset removes all matches; iterator erase removes one

## 2. Intuition
Need unique + ordered → tree `set` (O(log n)). Need unique + fast average lookup → hash `unordered_set`. Need duplicates sorted → `multiset`.

## 3. Brute Force → Optimal
- **Brute:** sorted `vector` + unique / linear scan.
- **This approach:** associative containers matching the access pattern.

## 4. Data Structure / Approach Justification
**Chosen:** three demos highlighting complexity tradeoffs.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Sorted vector | Better locality; costlier inserts |
| `unordered_multiset` | Hashed duplicates; no order |
| Bitset / bool array | Only for dense tiny universes |

## 5. Logic Walkthrough
1. Insert into `set`; show sorted unique + `find`.
2. `unordered_set` insert/count; order arbitrary.
3. `multiset` count; `erase(30)` all; `erase(it)` one `10`.

## 6. Dry Run
`set` inserts 40,10,30,10 → `{10,30,40}`.
`multiset` `{10,10,30,30,40}` → erase 30 → `{10,10,40}` → erase one 10 → `{10,40}`.

## 7. Time & Space Complexity
- **set / multiset:** O(log n) insert/find/erase
- **unordered_set:** average O(1); worst O(n)
- **Space:** O(n)
- Why: tree height vs hash buckets

## 8. Trade-offs & Alternatives
- Prefer `unordered_*` when order unused and hash is good.
- Prefer `set` for ordered ranges / predecessor queries.
- Custom hash/comparator needed for user types.

## 9. Common Mistakes / Edge Cases
- Assuming unordered iteration order is stable
- Erasing all multiset keys unintentionally
- Mutating set elements in place (keys are const)
- Relying on worst-case O(1) for unordered

## 10. Interview Follow-ups / Variations
- Lower/upper bound on `set`
- Load factor / rehash for unordered
- Policy-based data structures / fenwick alternatives

## 11. Tags
`stl`, `set`, `unordered_set`, `multiset`, `difficulty:easy`
