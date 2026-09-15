# Divisor Game (LC 1025)

## 1. Problem Statement
[LeetCode 1025 — Divisor Game](https://leetcode.com/problems/divisor-game/): choose divisor x, replace n with n-x; Alice wins?

## 2. Intuition
Alice wins iff n even.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** parity + DP check.

**Pedagogy:** Number-theoretic simple game.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
n=2 true; n=3 false.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-1025`, `math`, `difficulty:easy`
