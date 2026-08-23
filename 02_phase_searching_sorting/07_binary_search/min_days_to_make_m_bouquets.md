# Minimum Number of Days to Make m Bouquets

## Problem Statement
[LeetCode 1482](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) — flower i blooms on `bloomDay[i]`; a bouquet needs `k` adjacent bloomed flowers. Min day to make `m` bouquets, or -1.

- **Inputs:** `bloomDay`, `m`, `k`.
- **Output:** `int` day or -1.
- **Valid answer:** smallest day where a greedy adjacent count reaches m.
- **Edges:** not enough flowers; k=1; m*k overflow.

## Intuition
Later days only add bloomed flowers → monotone. Binary search the day.

## Brute Force → Optimal
- **Brute:** simulate every day — O(maxDay · N).
- **Optimal:** search-on-answer — O(N log MaxDay).

## Data Structure / Approach Justification
**Chosen:** adjacent-streak feasibility check.

- **vs Koko:** same outer loop; different greedy
- **vs union-find by day:** overkill

## Logic Walkthrough
If `m*k > n` return -1. Else search `[minDay, maxDay]`.

## Dry Run
`[1,10,3,10,2]`, m=3, k=1 → day 3.

## Time & Space Complexity
Time **O(N log D)**. Space **O(1)**. Why: D is the bloom-day range.

## Trade-offs & Alternatives
Reset streak on unbloomed flowers — adjacency is mandatory.

## Common Mistakes / Edge Cases
Ignoring adjacency; 32-bit `m*k`.

## Interview Follow-ups / Variations
Koko; ship packages; magnetic force.

## Tags
`binary-search`, `search-on-answer`, `leetcode-1482`, `difficulty:medium`
