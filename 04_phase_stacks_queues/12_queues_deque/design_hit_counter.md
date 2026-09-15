# Design Hit Counter

## Problem Statement
[LeetCode 362](https://leetcode.com/problems/design-hit-counter/) — record hits at timestamps; return count in window `[t-299, t]`.

- **Inputs:** increasing timestamps (per constraints).
- **Output:** `getHits` count in last 300 seconds.
- **Valid answer:** include hits at `t`, exclude older than 300s.
- **Edges:** many hits same second; empty window.

## Intuition
Deque of `(time, count)` buckets; drop expired from front; maintain running total.

## Brute Force → Optimal
- **Brute:** store every hit timestamp — O(H) space.
- **Optimal:** aggregate same-second hits; binary search / deque eviction.

## Data Structure / Approach Justification
**Chosen:** deque + total.

- **vs circular array of 300:** also O(1) amortized, fixed memory.

## Logic Walkthrough
On hit/getHits, pop front while `t - front >= 300`; merge same timestamp; return total.

## Dry Run
Hits at 1,2,3,300 → getHits(301) drops time 1 → 3.

## Time & Space Complexity
Amortized **O(1)** per op. Space **O(min(H, 300))** buckets.

## Trade-offs & Alternatives
Fixed 300-slot circular buffer if timestamps dense.

## Common Mistakes / Edge Cases
Off-by-one on 300; not merging same second.

## Interview Follow-ups / Variations
Different window sizes; concurrent hit counters.

## Tags
`queue`, `design`, `sliding-window`, `leetcode-362`, `difficulty:medium`
