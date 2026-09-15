# Kitamasa Method — Teaching Lab

## 1. Problem Statement
**Teaching lab:** n-th Fib via Kitamasa (x^n mod char poly). Berlekamp–Massey skipped as tooling-heavy.

## 2. Intuition
Multiply polys mod x²-x-1.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** double-and-add coeff vectors.

**Pedagogy:** Teaching lab; BM skipped if uncertain.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
Fib(10)=55; Fib(20)=6765.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`kitamasa`, `teaching-lab`, `difficulty:hard`
