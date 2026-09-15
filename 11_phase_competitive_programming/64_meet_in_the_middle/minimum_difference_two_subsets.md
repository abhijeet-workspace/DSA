# Minimum Difference of Two Subsets

## 1. Problem Statement
Partition into two subsets (not necessarily equal size) minimizing `|sum1-sum2|` (= minimize `|total-2*subsetSum|`).

- **Inputs:** array of positive ints.
- **Output:** minimum difference.
- **Edges:** single element; all equal.
- **Note:** Classic DP when sums small; MITM when n small and sums large.

## 2. Intuition
Find subset sum closest to total/2 via MITM or DP.

## 3. Brute Force → Optimal
- **DP bitset** if sum≤1e5.
- **MITM** if n≤40.

## 4. Data Structure / Approach Justification
**Chosen:** MITM closest to total/2.

| Alternative | Note |
|-------------|------|
| DP | Small sums |

## 5. Logic Walkthrough
1. Enum half sums.
2. Match closest to total/2.
3. Answer |total-2*best|.

## 6. Dry Run
`[1,6,11,5]` → diff **1**.

## 7. Time & Space Complexity
**O(2^(n/2) log)**.

## 8. Trade-offs & Alternatives
Same family as partition problems.

## 9. Common Mistakes / Edge Cases
Empty-only; overflow.

## 10. Interview Follow-ups / Variations
Equal size constraint (LC 2035).

## 11. Tags
`partition`, `meet-in-the-middle`, `difficulty:medium`
