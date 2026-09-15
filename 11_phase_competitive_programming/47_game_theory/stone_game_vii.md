# Stone Game VII (LC 1690)

## 1. Problem Statement
[LeetCode 1690 — Stone Game VII](https://leetcode.com/problems/stone-game-vii/): remove end; score += remaining sum; return Alice-Bob diff.

## 2. Intuition
Interval DP with prefix sums.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** pref + dp[i][j].

**Pedagogy:** Another ends scoring variant.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
[5,3,1,4,2] → 6.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-1690`, `dp`, `difficulty:medium`
