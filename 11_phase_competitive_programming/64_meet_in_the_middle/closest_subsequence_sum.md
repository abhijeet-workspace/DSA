# Closest Subsequence Sum (LC 1755)

## 1. Problem Statement
Find a subsequence sum closest to `goal` (minimize absolute difference).

- **Inputs:** array `nums`, integer `goal`.
- **Output:** minimum `|sum - goal|`.
- **Valid answer:** [LC 1755](https://leetcode.com/problems/closest-subsequence-sum/).
- **Edges:** goal far from all; empty subsequence; negatives.
- **Link:** [LC 1755](https://leetcode.com/problems/closest-subsequence-sum/)

## 2. Intuition
MITM: all left sums vs all right sums; for each left, binary-search right closest to `goal-left`.

## 3. Brute Force → Optimal
- **Brute:** 2^N.
- **MITM:** 2^(N/2) log.

## 4. Data Structure / Approach Justification
**Chosen:** enumerate halves; sort right; lower_bound per left.

| Alternative | Note |
|-------------|------|
| DP if sums tiny | Different constraint |

## 5. Logic Walkthrough
1. Split; enum sumsL/sumsR.
2. Sort R.
3. Track min |L+R-goal|.

## 6. Dry Run
`[5,7,2]`, goal 6 → 5 or 7 → diff **1**.

## 7. Time & Space Complexity
**O(2^(N/2) · N)**.

## 8. Trade-offs & Alternatives
N≤40 typical.

## 9. Common Mistakes / Edge Cases
Forgetting empty sums; int overflow.

## 10. Interview Follow-ups / Variations
Count closest; XOR version.

## 11. Tags
`meet-in-the-middle`, `lc-1755`, `difficulty:hard`
