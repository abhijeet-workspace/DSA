# Gaussian Elimination mod Prime — Teaching Lab

## 1. Problem Statement
**Teaching lab:** solve Ax=b mod prime.

## 2. Intuition
Row reduce with modular inverse.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** augmented matrix elimination.

**Pedagogy:** CP modular linear algebra lab.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
x+y=3, x+2y=5 → (1,2).

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`gaussian`, `teaching-lab`, `difficulty:hard`
