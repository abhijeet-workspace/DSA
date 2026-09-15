# Number of Ways to Paint N×3 Grid (LC 1411)

## 1. Problem Statement
[LeetCode 1411 — Number of Ways to Paint N×3 Grid](https://leetcode.com/problems/number-of-ways-to-paint-n-x-3-grid/): 3 colors, adjacent differ, mod 1e9+7.

## 2. Intuition
Two pattern families with coupled recurrence.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** type121/type123 O(n) recurrence.

**Pedagogy:** Linear counting system.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
n=1→12; n=2→54.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-1411`, `dp`, `difficulty:hard`
