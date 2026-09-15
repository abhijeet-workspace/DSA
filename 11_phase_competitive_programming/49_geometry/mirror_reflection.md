# Mirror Reflection (LC 858)

## 1. Problem Statement
[LeetCode 858 — Mirror Reflection](https://leetcode.com/problems/mirror-reflection/): laser from (0,0) at 45° in square room side p with receptors; return which receptor is hit first.

- **Inputs:** p, q (extension height).
- **Output:** 0, 1, or 2.
- **Edges:** q=p → 1.

## 2. Intuition
Reflect room instead of ray; find least m,n with m*p = n*q parity rules → receptor.

## 3. Brute Force → Optimal
- **Brute:** simulate reflections.
- **Optimal:** reduce by gcd; parity of p/g and q/g.

## 4. Data Structure / Approach Justification
**Chosen:** while both even divide; then classify.

**Pedagogy:** reflection principle geometry.

## 5. Logic Walkthrough
Divide p,q by 2 while even; if p odd q odd → 1; p odd q even → 0; p even q odd → 2.

## 6. Dry Run
`p=2,q=1` → **2**.

## 7. Time & Space Complexity
Time **O(log)**.

## 8. Trade-offs & Alternatives
Simulation with floats fragile.

## 9. Common Mistakes / Edge Cases
Wrong receptor mapping.

## 10. Interview Follow-ups / Variations
Billiard unfoldings.

## 11. Tags
`geometry`, `math`, `leetcode-858`, `difficulty:medium`
