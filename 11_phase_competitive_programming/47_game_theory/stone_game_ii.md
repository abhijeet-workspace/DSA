# Stone Game II (LC 1140)

## 1. Problem Statement
[LeetCode 1140 — Stone Game II](https://leetcode.com/problems/stone-game-ii/): take X in [1,2M] piles from front; M:=max(M,X); return Alice stones.

## 2. Intuition
DP(i,M): maximize suffix[i]-opponent.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** suffix + memo dfs.

**Pedagogy:** Stateful stone game beyond LC877 triviality.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
[2,7,9,4,4] → 10.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-1140`, `dp`, `difficulty:medium`
