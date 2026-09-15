# Meet in the Middle

## 1. Problem Statement
Decide whether any subset of `arr` sums to `target` when `N` is too large for `2^N` (e.g. `N ≈ 40`) but `2^(N/2)` is feasible.

- **Inputs:** integer array, target sum.
- **Output:** whether a subset hits `target`.
- **Edges:** empty subset (target 0); negatives (still works if careful); duplicates.

## 2. Intuition
`2^40` is impossible; split into two halves of ~20, enumerate both (`~2·2^20`), sort one side, binary-search complements.

## 3. Brute Force → Optimal
- **Brute:** all subsets O(2^N).
- **MITM:** O(2^(N/2) · N) generate + O(2^(N/2) log 2^(N/2)) match.

## 4. Data Structure / Approach Justification
**Chosen:** bitmasks for each half + sorted right sums + binary search.

| Alternative | Note                        |
|-------------|-----------------------------|
| DP knapsack | Needs bounded sum magnitude |
| Full 2^N    | Impossible near N=40        |

## 5. Logic Walkthrough
Split `arr`. Enumerate all subset sums of left and right. For each left sum `s`, search `target - s` in sorted right sums.

## 6. Dry Run
`{3,34,4,12,5,2}`, target `9`: left/right sums include `4` and `5` → match → **yes**.

## 7. Time & Space Complexity
Time **O(2^(N/2) · N)**. Space **O(2^(N/2))**.

## 8. Trade-offs & Alternatives
Memory heavy. Prefer DP when sums are small; prefer meet-in-middle when `N≤40` and sums are large.

## 9. Common Mistakes / Edge Cases
Forgetting empty subset sum `0`; integer overflow on sums; uneven split off-by-one.

## 10. Interview Follow-ups / Variations
Count subsets; closest sum to target; XOR meet-in-middle; 4-sum style splits.

## 11. Tags
`meet-in-the-middle`, `subset-sum`, `bitmask`, `competitive-programming`, `difficulty:hard`
