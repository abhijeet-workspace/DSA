# Climbing Stairs via Matrix (LC 70)

## 1. Problem Statement
[LeetCode 70 — Climbing Stairs](https://leetcode.com/problems/climbing-stairs/): ways with 1/2 steps via matrix.

## 2. Intuition
ways(n)=ways(n-1)+ways(n-2).

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** apply T^{n-2} to [2,1].

**Pedagogy:** Matrix view; combo framing elsewhere; DP elsewhere.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
n=3→3; n=5→8.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-70`, `matrix`, `difficulty:easy`
