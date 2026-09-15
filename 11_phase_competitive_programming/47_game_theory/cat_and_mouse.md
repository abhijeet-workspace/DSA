# Cat and Mouse (LC 913)

## 1. Problem Statement
[LeetCode 913 — Cat and Mouse](https://leetcode.com/problems/cat-and-mouse/): mouse/cat on graph; return 1 mouse win, 2 cat, 0 draw.

## 2. Intuition
State (mouse,cat,turn) with draw on long games.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** memo DFS with turn limit 2n (teaching-complete).

**Pedagogy:** Hard graph game LC; full degree-BFS coloring is the contest-grade variant.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
Sample graph → 0 draw.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`leetcode-913`, `graph`, `difficulty:hard`
