# Range Module

## 1. Problem Statement
[LeetCode 715](https://leetcode.com/problems/range-module/) — track ranges; support `addRange`, `queryRange`, `removeRange` on half-open intervals.

- **Inputs:** interval ops on `[left, right)`.
- **Output:** bool for queries; void for add/remove.
- **Valid answer:** query true iff entire `[left,right)` is tracked.
- **Edges:** adjacent merges; partial overlaps; empty module.

## 2. Intuition
Maintain disjoint sorted intervals (or a segment tree over compressed coords). Add merges overlapping; remove splits; query checks full coverage.

## 3. Brute Force → Optimal
- **Brute:** bool array — impossible on large coords.
- **Optimal:** `std::map` of intervals or dynamic segtree — O(K log K) per op.

## 4. Data Structure / Approach Justification
**Chosen:** ordered map `start→end` of disjoint intervals.

- **vs dynamic segtree:** map is shorter for interviews; segtree fits huge sparse universes.

## 5. Logic Walkthrough
`add`: find overlap, erase, insert merged. `remove`: split/crop. `query`: find covering interval.

## 6. Dry Run
add[10,20), remove[14,16), query[10,14)→true, query[13,15)→false.

## 7. Time & Space Complexity
Time **O(K log K)** per op with K intervals. Space **O(K)**.

## 8. Trade-offs & Alternatives
Dynamic segtree is better when coords are huge and ops are dense.

## 9. Common Mistakes / Edge Cases
Forgetting half-open semantics; not merging adjacent; query requiring exact interval equality.

## 10. Interview Follow-ups / Variations
My Calendar III; Range Sum 2D Mutable (premium).

## 11. Tags
`segment-tree`, `ordered-map`, `intervals`, `leetcode-715`, `difficulty:hard`
