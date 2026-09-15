# Stone Game IV (LC 1510)

## 1. Problem Statement
[LeetCode 1510 — Stone Game IV](https://leetcode.com/problems/stone-game-iv/): remove a positive square; unable to move loses. Alice starts.

## 2. Intuition
win[i] if some i-k^2 is losing.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** bool DP.

**Pedagogy:** Impartial square-subtraction game.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
n=2 false; n=7 true.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-1510`, `dp`, `difficulty:hard`
