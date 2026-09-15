# N-th Tribonacci via Matrix (LC 1137)

## 1. Problem Statement
[LeetCode 1137 — N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/): T0=0,T1=1,T2=1,Tn=sum of previous three.

## 2. Intuition
3×3 companion matrix.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** matrix pow order 3.

**Pedagogy:** Order-3 linear recurrence extension.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
T4=4; T25=1389537.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-1137`, `matrix`, `difficulty:easy`
