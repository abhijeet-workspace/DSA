# Stone Game (LC 877)

## 1. Problem Statement
[LeetCode 877 — Stone Game](https://leetcode.com/problems/stone-game/): even piles; take ends; Alice starts; return if Alice wins.

## 2. Intuition
Alice can always force the better parity of indices → always wins under LC constraints.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** return true; also show interval DP diff.

**Pedagogy:** Partisan ends-game; contrast impartial Nim.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
[5,3,4,5] → true.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-877`, `dp`, `difficulty:medium`
