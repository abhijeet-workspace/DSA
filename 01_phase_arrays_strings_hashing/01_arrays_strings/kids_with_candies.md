# Kids With the Greatest Number of Candies

## Problem Statement
[LeetCode 1431](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) — for each kid, return whether giving them all `extraCandies` would make them have the max among all kids.

- **Inputs:** `vector<int> candies`, `int extraCandies`.
- **Output:** `vector<bool>` same length.
- **Edges:** all equal; one kid; `extraCandies = 0`.

## Intuition
Find global max once. Kid `i` succeeds iff `candies[i] + extraCandies >= maxCandies`.

## Brute Force → Optimal
- **Brute:** for each kid, recompute max after adding extras — O(N²).
- **Optimal:** one max pass, one result pass — O(N).

## Data Structure / Approach Justification
**Chosen:** single max + comparison. No fancy structure needed.

## Logic Walkthrough
1. `mx = max(candies)`.
2. For each `c`, push `c + extra >= mx`.

## Dry Run
`candies=[2,3,5,1,3]`, `extra=3` → max=5 → `[true,true,true,false,true]`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** for output (O(1) aux).

## Trade-offs & Alternatives
None meaningful — this is the natural solution.

## Common Mistakes / Edge Cases
Strict `>` instead of `>=` (ties after extras still count).

## Interview Follow-ups / Variations
Kids with the greatest number after any redistribution.

## Tags
`array`, `easy`, `leetcode-1431`
