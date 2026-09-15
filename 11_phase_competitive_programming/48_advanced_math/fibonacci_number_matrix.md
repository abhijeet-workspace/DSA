# Fibonacci Number via Matrix (LC 509)

## 1. Problem Statement
[LeetCode 509 — Fibonacci Number](https://leetcode.com/problems/fibonacci-number/): return F(n).

## 2. Intuition
Same 2×2 transition as toolkit.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** matrix pow without mod for small n.

**Pedagogy:** LC509 framing of matrix_exponentiation.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
F(10)=55.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-509`, `matrix`, `difficulty:easy`
