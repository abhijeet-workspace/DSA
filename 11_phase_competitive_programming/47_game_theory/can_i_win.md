# Can I Win (LC 464)

## 1. Problem Statement
[LeetCode 464 — Can I Win](https://leetcode.com/problems/can-i-win/): use 1..max once; reach desiredTotal; first force win?

## 2. Intuition
Bitmask of used numbers; memo force-win.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** DFS mask memo.

**Pedagogy:** Also in bitmask-DP elsewhere; here game-force-win framing.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
max=10,total=11 → false.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-464`, `bitmask-dp`, `difficulty:medium`
