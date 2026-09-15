# NTT Polynomial Multiply — Teaching Lab

## 1. Problem Statement
**Teaching lab:** NTT multiply mod 998244353.

## 2. Intuition
Cooley–Tukey in modular arithmetic.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** iterative NTT, root 3.

**Pedagogy:** Exact modular companion to float FFT.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
[1,2]*[3,4] → 3,10,8.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`ntt`, `teaching-lab`, `difficulty:hard`
