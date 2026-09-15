# Range Module

## 1. Problem Statement
[LeetCode 715](https://leetcode.com/problems/range-module/) — maintain a set of half-open intervals; support `addRange`, `queryRange` (fully covered?), `removeRange`.

- **Inputs:** mix of add/query/remove on `[left,right)`.
- **Output:** bool for queries.
- **Valid answer:** merge/split disjoint intervals in an ordered map.
- **Edges:** adjacent merge; remove middle of one interval; empty module.

## 2. Intuition
Store disjoint intervals keyed by start. On add, merge all overlapping into one. On remove, split/crop. Query checks one interval covers `[left,right)`.

## 3. Brute Force → Optimal
- **Brute:** boolean array if coordinates small.
- **Optimal:** `map<int,int>` of disjoint ranges — O(K log N) per op.

## 4. Data Structure / Approach Justification
**Chosen:** `std::map` start→end.

- **vs segment tree / lazy:** better for huge coordinate ranges with few intervals.

## 5. Logic Walkthrough
add: find first overlapping, erase through right, insert merged. query: predecessor must end ≥ right. remove: crop left piece, erase fully covered, crop right piece.

## 6. Dry Run
add[10,20), remove[14,16) → covers [10,14) U [16,20); query[13,15) false.

## 7. Time & Space Complexity
Each op **O(N log N)** worst (many merges). Space **O(N)**. Why: tree of intervals (section 4).

## 8. Trade-offs & Alternatives
Hard design staple for interval modules; pairs with Calendar I.

## 9. Common Mistakes / Edge Cases
Half-open mistakes; forgetting to split on remove; not merging touching intervals on add (`prev->second >= left`).

## 10. Interview Follow-ups / Variations
My Calendar I–III; Insert Interval.

## 11. Tags
`intervals`, `ordered-map`, `design`, `leetcode-715`, `difficulty:hard`
