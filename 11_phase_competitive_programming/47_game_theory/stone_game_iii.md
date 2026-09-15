# Stone Game III (LC 1406)

## 1. Problem Statement
[LeetCode 1406 — Stone Game III](https://leetcode.com/problems/stone-game-iii/): take 1–3 from front (values may be negative); return Alice/Bob/Tie.

## 2. Intuition
DP best score difference from index i.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** O(n) backward DP.

**Pedagogy:** Stone-game series with negatives.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
[1,2,3,7] Bob; [1,2,3,-9] Alice.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-1406`, `dp`, `difficulty:hard`
