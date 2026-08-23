# Maximum Number of Events That Can Be Attended II

## Problem Statement
[LeetCode 1751](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/) — events `[start, end, value]`; attend at most `k` non-overlapping events (inclusive ends: next start must be `> end`). Max total value.

- **Inputs:** `events`, `k`.
- **Output:** `int` max value.
- **Valid answer:** DP over (index, remaining) with binary-searched next index.
- **Edges:** k=1 (just max value); dense overlaps.

## Intuition
Sort by start. `dp[i][t] = max(skip, value[i] + dp[next][t-1])`. `next` is the first event with `start > end_i`.

## Brute Force → Optimal
- **Brute:** O(N² k) linear next.
- **Optimal:** O(N k log N) with binary search next (or O(Nk) after precomputing next).

## Data Structure / Approach Justification
**Chosen:** DP + binary search, the second problem of the last study-plan group.

- **vs 1235:** 1235 is unlimited k with profits; 1751 caps k
- **vs greedy:** values differ; greedy fails

## Logic Walkthrough
Bottom-up from the right so `dp[next]` is ready. Inclusive intervals need `start > end`.

## Dry Run
`[[1,2,4],[3,4,3],[2,3,1]]`, k=2 → 7.

## Time & Space Complexity
Time **O(N k log N)**. Space **O(N k)**. Why: Nk states; log N next lookup.

## Trade-offs & Alternatives
Precompute `next[i]` to drop the log if k is large.

## Common Mistakes / Edge Cases
Allowing `start == end` (overlap); rolling k dimension off-by-one.

## Interview Follow-ups / Variations
Job scheduling (1235); weighted interval scheduling.

## Tags
`binary-search`, `dp`, `intervals`, `leetcode-1751`, `difficulty:hard`
