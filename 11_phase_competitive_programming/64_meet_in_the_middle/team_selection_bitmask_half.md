# Team Selection Bitmask Half (MITM)

## 1. Problem Statement
Teaching: select a team of exactly `k` people from `n≤40` with scores `a[i]`, maximizing score sum under sum≤`budget` (or report best sum ≤ budget). Uses sized subset MITM.

- **Inputs:** scores, k, budget.
- **Output:** max sum ≤ budget with exactly k items (or -1).
- **Edges:** k=0; k>n; impossible.

## 2. Intuition
Sized subset sums on halves; combine counts k1+k2=k.

## 3. Brute Force → Optimal
- **C(n,k).**
- **MITM sized:** 2^(n/2).

## 4. Data Structure / Approach Justification
**Chosen:** vector of sums per popcount each half; sort and two-pointer/binary search.

| Alternative | Note |
|-------------|------|
| DP knapsack | Small budget |

## 5. Logic Walkthrough
1. Enum left/right with (count,sum).
2. For c=0..k, match left c with right k-c best ≤ budget-left.

## 6. Dry Run
scores `[6,3,2,5]`, k=2, budget=8 → 6+2=8.

## 7. Time & Space Complexity
**O(2^(n/2) · n)**.

## 8. Trade-offs & Alternatives
Useful contest pattern for exact-k + capacity.

## 9. Common Mistakes / Edge Cases
Wrong popcount; not sorting for upper_bound.

## 10. Interview Follow-ups / Variations
Minimize sum ≥ budget; pair constraints.

## 11. Tags
`bitmask`, `meet-in-the-middle`, `team-selection`, `teaching`, `difficulty:hard`
