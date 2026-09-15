# Nim Game (LC 292)

## 1. Problem Statement
[LeetCode 292 — Nim Game](https://leetcode.com/problems/nim-game/): remove 1–3 from n; last move wins. Return if first wins.

## 2. Intuition
Losing positions are multiples of 4.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** `n % 4 != 0`.

**Pedagogy:** Simplest subtraction special case; multi-pile Nim is in toolkit.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
n=4 false; n=5 true.

## 7. Time & Space Complexity
O(1)

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-292`, `game-theory`, `difficulty:easy`
