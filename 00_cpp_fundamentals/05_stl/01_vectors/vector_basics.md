# Vector Basics

## 1. Problem Statement
Demonstrate `std::vector`: construction forms, element access, `reserve`/`emplace_back`, capacity growth, erase-remove, and sort+unique dedupe.

- **Input:** hard-coded demo sequences in `main`
- **Output:** sizes/capacities and transformed vectors
- **Valid answer:** contiguous dynamic array with amortized O(1) `push_back`
- **Edge cases:** reallocation invalidates iterators/references; `at` throws on OOB

## 2. Intuition
Need a resizable array with random access and cache-friendly layout? `vector` owns a contiguous buffer and grows geometrically when full.

## 3. Brute Force → Optimal
- **Naive:** raw `new[]` + manual resize/copy.
- **This approach:** `std::vector` handles allocation, size, and destruction (RAII).

## 4. Data Structure / Approach Justification
**Chosen:** `std::vector<T>` as the default sequential container.

| Alternative | Why it loses here |
|-------------|-------------------|
| `std::deque` | Not strictly contiguous; weaker cache locality |
| `std::list` | O(n) indexing; poor locality |
| C array / `unique_ptr<T[]>` | Fixed or manual growth |

Trade-off: mid inserts are O(n); prefer `list`/`deque` only when that dominates.

## 5. Logic Walkthrough
1. Show empty / sized / filled / initializer-list constructors.
2. Access via `[]`, `at`, `front`, `back`.
3. `reserve` then `emplace_back` to limit reallocations.
4. Push 1..8 and print when `capacity` jumps.
5. Erase-remove all `2`s; sort then unique-erase duplicates.

## 6. Dry Run
| er before | remove 2 | after erase |
|-----------|----------|-------------|
| 1 2 3 2 4 2 5 | compact non-2s | 1 3 4 5 |

| du sorted | unique erase |
|-----------|--------------|
| 1 2 3 3 4 5 5 | 1 2 3 4 5 |

## 7. Time & Space Complexity
- **Random access / back push (amortized):** O(1)
- **Insert/erase middle:** O(n)
- **sort:** O(n log n); **unique+erase:** O(n)
- **Space:** O(n) elements + spare capacity
- Why: contiguous buffer; growth copies on reallocate

## 8. Trade-offs & Alternatives
- Prefer `reserve` when final size is known.
- Prefer `emplace_back` to avoid temporaries.
- Avoid `vector<bool>` proxy quirks; use `vector<char>`/`bitset` as needed.

## 9. Common Mistakes / Edge Cases
- Holding iterators across `push_back` that reallocates
- Using `[]` unchecked vs `at`
- Forgetting erase after `remove`/`unique`
- Assuming `capacity == size` always

## 10. Interview Follow-ups / Variations
- Why amortized O(1) push_back?
- Iterator invalidation rules summary?
- `shrink_to_fit` vs swap-trick?

## 11. Tags
`stl`, `vector`, `dynamic-array`, `erase-remove`, `difficulty:easy`
