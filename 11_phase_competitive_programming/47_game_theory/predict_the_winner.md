# Predict the Winner (LC 486)

## 1. Problem Statement
[LeetCode 486 — Predict the Winner](https://leetcode.com/problems/predict-the-winner/): take ends; P1 wins if score ≥ P2.

## 2. Intuition
Interval DP on score difference.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** dp[i][j] best diff.

**Pedagogy:** General form of LC877.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
[1,5,2] false; [1,5,233,7] true.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-486`, `dp`, `difficulty:medium`
