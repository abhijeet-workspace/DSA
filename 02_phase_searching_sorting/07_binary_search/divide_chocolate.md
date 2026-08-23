# Divide Chocolate

## Problem Statement
[LeetCode 1231](https://leetcode.com/problems/divide-chocolate/) — cut the bar into `k+1` contiguous pieces; you eat the piece with minimum sweetness. Maximize that minimum. Premium.

- **Inputs:** `sweetness`, `k` friends.
- **Output:** `int` maximized min piece.
- **Valid answer:** largest T such that we can form ≥ k+1 pieces each summing to ≥ T.
- **Edges:** k=0 (whole bar); k=n-1 (min element).

## Intuition
Maximize-the-minimum: feasibility is monotone in T. Greedy cut whenever the running sum hits T.

## Brute Force → Optimal
- **Brute:** try every T — O(sum · N).
- **Optimal:** binary search — O(N log Sum).

## Data Structure / Approach Justification
**Chosen:** search-on-answer (max min), dual of split-array (min max).

- **vs 410:** 410 minimizes the max; 1231 maximizes the min
- **vs magnetic force:** same max-min template on positions

## Logic Walkthrough
If we can make k+1 chunks ≥ mid, try a sweeter mid.

## Dry Run
`[1..9]`, k=5 → 6.

## Time & Space Complexity
Time **O(N log Sum)**. Space **O(1)**. Why: log of total sweetness times a linear cut.

## Trade-offs & Alternatives
Aggressive cows / magnetic force is the geometric cousin.

## Common Mistakes / Edge Cases
Checking `parts >= k` instead of `k+1`; stopping the last leftover chunk from counting.

## Interview Follow-ups / Variations
Split array largest sum; aggressive cows.

## Tags
`binary-search`, `search-on-answer`, `premium`, `leetcode-1231`, `difficulty:hard`
