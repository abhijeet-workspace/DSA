# Design Hit Counter

## 1. Problem Statement
[LeetCode 362](https://leetcode.com/problems/design-hit-counter/) — record hits at timestamps; return count in window `[t-299, t]`.

- **Inputs:** increasing timestamps (per constraints).
- **Output:** `getHits` count in last 300 seconds.
- **Valid answer:** include hits at `t`, exclude older than 300s.
- **Edges:** many hits same second; empty window.

## 2. Intuition
Deque of `(time, count)` buckets; drop expired from front; maintain running total.

## 3. Brute Force → Optimal
- **Brute:** store every hit timestamp — O(H) space.
- **Optimal:** aggregate same-second hits; deque eviction — amortized O(1).

## 4. Data Structure / Approach Justification
**Chosen:** deque + total.

| Alternative | Note |
|-------------|------|
| Circular array of 300 | Also O(1) amortized, fixed memory |

## 5. Logic Walkthrough
1. On hit/getHits, pop front while `t - front >= 300`.
2. Merge same timestamp into back bucket.
3. Return total.

## 6. Dry Run
Hits at 1,2,3,300 → getHits(301) drops time 1 → 3.

## 7. Time & Space Complexity
- **Time:** amortized O(1) per op
- **Space:** O(min(H, 300)) buckets

## 8. Trade-offs & Alternatives
Fixed 300-slot circular buffer if timestamps dense.

## 9. Common Mistakes / Edge Cases
Off-by-one on 300; not merging same second.

## 10. Interview Follow-ups / Variations
Different window sizes; concurrent hit counters; recent calls (933).

## 11. Tags
`queue`, `design`, `sliding-window`, `leetcode-362`, `difficulty:medium`
