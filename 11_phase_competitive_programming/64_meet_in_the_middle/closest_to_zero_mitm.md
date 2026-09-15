# Closest Subset Sum to Zero (MITM)

## 1. Problem Statement
Find a nonempty subset whose sum is closest to zero (minimize absolute sum).

- **Inputs:** array of ints (may include negatives).
- **Output:** minimum `|subset_sum|` over nonempty subsets.
- **Edges:** all positive; zeros present.

## 2. Intuition
Same MITM as closest to goal with goal=0; exclude both-empty if required.

## 3. Brute Force → Optimal
- **Brute:** 2^N.
- **MITM:** 2^(N/2) log.

## 4. Data Structure / Approach Justification
**Chosen:** halves + binary search for nearest complement of `-s`.

| Alternative | Note |
|-------------|------|
| DP | If range small |

## 5. Logic Walkthrough
1. Enum sums including 0.
2. For each left s, find right closest to -s.
3. Skip (0,0) if nonempty required — handle by checking masks or tracking.

## 6. Dry Run
`[1,-1,2]` → 0 via `{1,-1}`.

## 7. Time & Space Complexity
**O(2^(N/2) log)**.

## 8. Trade-offs & Alternatives
Watch empty subset.

## 9. Common Mistakes / Edge Cases
Returning 0 from empty always.

## 10. Interview Follow-ups / Variations
Exactly k elements; positive-only.

## 11. Tags
`meet-in-the-middle`, `closest-sum`, `difficulty:hard`
