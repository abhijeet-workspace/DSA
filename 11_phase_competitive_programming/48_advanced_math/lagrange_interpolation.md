# Lagrange Interpolation — Teaching Lab

## 1. Problem Statement
**Teaching lab:** interpolate y at nodes 0..k; evaluate at x.

## 2. Intuition
P(x)=Σ y_i Π (x-j)/(i-j).

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** direct Lagrange.

**Pedagogy:** CP interpolation lab.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
y=[1,2,4] → P(3)=7.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`interpolation`, `teaching-lab`, `difficulty:medium`
