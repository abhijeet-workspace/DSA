# Iterators

## 1. Problem Statement
Traverse a `vector` and `list` with `begin`/`end`, use iterators with `sort`/`find`, and note that iterator subtraction requires random-access iterators.

- **Input:** none
- **Output:** unsorted then sorted vector; index of `3`; list printout
- **Valid answer:** algorithms are iterator-range based: `[begin, end)`
- **Edges:** using invalidated iterators after erase/reallocation is UB

## 2. Intuition
Iterators are a uniform “pointer-like” interface to container elements so the same algorithm can run on many containers.

## 3. Brute Force → Optimal
- **Naive:** rewrite sort/search for each container API.
- **This approach:** containers expose iterators; `<algorithm>` consumes ranges.

## 4. Data Structure / Approach Justification
`vector` (random-access) vs `list` (bidirectional).

| Alternative | Why it loses here |
|-------------|-------------------|
| Index loops only | Won’t work for `list` |
| Ranges (C++20) | Modern layer over the same idea |

## 5. Logic Walkthrough
1. Walk vector with explicit iterators.
2. `sort` the vector range.
3. `find` value 3; compute index via `it - begin`.
4. Walk list; note subtraction is illegal.

## 6. Dry Run
| Step | vector state |
|------|--------------|
| init | 4 1 3 2 |
| sort | 1 2 3 4 |
| find 3 | index 2 |

## 7. Time & Space Complexity
- **sort:** O(n log n)
- **find:** O(n)
- **Space:** O(1) extra for these demos (sort may use some)
- Why: standard algorithm complexities

## 8. Trade-offs & Alternatives
- Prefer range-for when you only need elements.
- Prefer explicit iterators when the algorithm API requires them.
- Prefer knowing category limits (input/forward/bidirectional/random-access).

## 9. Common Mistakes / Edge Cases
- Dereferencing `end()`
- Using vector iterators after `push_back` reallocates
- Assuming all iterators support `it + n` / `it1 - it2`

## 10. Interview Follow-ups / Variations
- Iterator invalidation rules for vector/list/map?
- `const_iterator` vs `iterator`?
- Reverse iterators (`rbegin`/`rend`)?

## 11. Tags
`stl`, `iterators`, `algorithms`, `beginner`
