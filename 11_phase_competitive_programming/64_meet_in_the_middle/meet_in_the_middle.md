# Meet in the Middle

## Problem Statement
Decide whether any subset of `arr` sums to `target` when `N` is too large for `2^N` (e.g. `N ≈ 40`) but `2^(N/2)` is feasible.

- **Inputs:** integer array, target sum.
- **Output:** whether a subset hits `target`.
- **Edges:** empty subset (target 0); negatives (still works if careful); duplicates.

## Intuition
`2^40` is impossible; split into two halves of ~20, enumerate both (`~2·2^20`), sort one side, binary-search complements.

## Brute Force → Optimal
- **Brute:** all subsets O(2^N).
- **MITM:** O(2^(N/2) · N) generate + O(2^(N/2) log 2^(N/2)) match.

## Data Structure / Approach Justification
**Chosen:** bitmasks for each half + sorted right sums + binary search.

- **vs DP knapsack:** DP needs bounded sum magnitude; MITM depends on `N` only.
- Classic CP technique for subset / XOR / knapsack-with-large-N.

## Logic Walkthrough
Split `arr`. Enumerate all subset sums of left and right. For each left sum `s`, search `target - s` in sorted right sums.

## Dry Run
`{3,34,4,12,5,2}`, target `9`: left/right sums include `4` and `5` → match → **yes**.

## Time & Space Complexity
Time **O(2^(N/2) · N)**. Space **O(2^(N/2))**.

## Trade-offs & Alternatives
Memory heavy. Prefer DP when sums are small; prefer meet-in-middle when `N≤40` and sums are large.

## Common Mistakes / Edge Cases
Forgetting empty subset sum `0`; integer overflow on sums; uneven split off-by-one.

## Interview Follow-ups / Variations
Count subsets; closest sum to target; XOR meet-in-middle; 4-sum style splits.

## Tags
`meet-in-the-middle`, `subset-sum`, `bitmask`, `competitive-programming`, `difficulty:hard`
