# Split Array Largest Sum

## Problem Statement
[LeetCode 410](https://leetcode.com/problems/split-array-largest-sum/) — split `nums` into `k` non-empty contiguous parts; minimize the maximum part sum.

- **Inputs:** `nums`, `k`.
- **Output:** `int` minimized max sum.
- **Valid answer:** same packing check as ship-packages with k days.
- **Edges:** k=1; k=n; one huge element.

## Intuition
Monotone in the candidate max sum. DP exists (O(k N²)) but BS+greedy is enough.

## Brute Force → Optimal
- **Brute:** DP split — O(k N²).
- **Optimal:** binary search + greedy — O(N log Sum). This is also the study-plan DP group sibling.

## Data Structure / Approach Justification
**Chosen:** search-on-answer identical to 1011.

- **vs DP:** needed if you must reconstruct or if monotonicity is unclear
- **vs ship packages:** same code with different names

## Logic Walkthrough
lo=max element, hi=sum. Feasible if we can cut into ≤ k parts each summing ≤ mid.

## Dry Run
`[7,2,5,10,8]`, k=2 → 18 (`[7,2,5]` and `[10,8]`).

## Time & Space Complexity
Time **O(N log Sum)**. Space **O(1)**. Why: log of the sum range times a linear scan.

## Trade-offs & Alternatives
DP is the follow-up when they ask “also give an O(kN²) recurrence”.

## Common Mistakes / Edge Cases
Using < k parts incorrectly as infeasible; 32-bit sum overflow (use long long in the check if needed).

## Interview Follow-ups / Variations
Ship packages; painter’s partition; book allocation.

## Tags
`binary-search`, `search-on-answer`, `dp`, `leetcode-410`, `difficulty:hard`
