# Sort Items by Groups Respecting Dependencies

## 1. Problem Statement
[LeetCode 1203](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/) — order `n` items with before-constraints; items in the same group must be contiguous.

- **Inputs:** `n`, `m`, `group[]`, `beforeItems`.
- **Output:** valid order or empty if impossible.
- **Edges:** all `group=-1`; cycles.

## 2. Intuition
Two-level topo: item graph + group graph; assign unique groups to orphans; emit items by group order.

## 3. Brute Force → Optimal
- **Brute:** permutations with filters.
- **Optimal:** dual Kahn — O(n+e).

## 4. Data Structure / Approach Justification
**Chosen:** item topo + group topo + bucket emit.

| Alternative | Note |
|-------------|------|
| Single graph with supernodes | Same idea |

## 5. Logic Walkthrough
Assign free groups; build edges; topo both; concatenate buckets in group order.

## 6. Dry Run
LC sample yields a size-`8` valid permutation.

## 7. Time & Space Complexity
Time **O(n + edges)**. Space **O(n + edges)**.

## 8. Trade-offs & Alternatives
Shows hierarchical topological constraints.

## 9. Common Mistakes / Edge Cases
Adding group edges within the same group; failing to unique-ize `-1`.

## 10. Interview Follow-ups / Variations
Soft group preferences; weighted priorities.

## 11. Tags
`leetcode-1203`, `topological-sort`, `groups`, `difficulty:hard`
