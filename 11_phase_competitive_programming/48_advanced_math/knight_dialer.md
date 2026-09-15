# Knight Dialer (LC 935)

## 1. Problem Statement
[LeetCode 935 — Knight Dialer](https://leetcode.com/problems/knight-dialer/): n-length hop numbers on phone pad mod 1e9+7.

## 2. Intuition
10-state linear DP / transfer matrix.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** iterative hop DP.

**Pedagogy:** Matrix-exp applicable for huge n; O(n) for LC.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
n=1→10; n=2→20.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-935`, `dp`, `matrix`, `difficulty:medium`
