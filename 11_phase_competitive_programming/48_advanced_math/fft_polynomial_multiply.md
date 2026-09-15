# FFT Polynomial Multiply

## 1. Problem Statement

Multiply polynomials via FFT (complex DFT).

- **Inputs:** coeff vectors a,b.
- **Output:** convolution.
- **Edges:** pad power-of-two; precision.

## 2. Intuition

DFT turns convolution into pointwise products.

## 3. Brute Force → Optimal

- **Brute:** O(N²).
- **Optimal:** O(N log N) FFT.

## 4. Data Structure / Approach Justification

**Chosen:** complex recursive FFT + llround.

**Pedagogy:** Core advanced-math tool; contrast naive and NTT labs in this folder.

## 5. Logic Walkthrough

See implementation and dry run.

## 6. Dry Run

(1+2x+3x²)(2+3x) → 2,7,12,9.

## 7. Time & Space Complexity

O(N log N) time, O(N) space.

## 8. Trade-offs & Alternatives

Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases

Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations

Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags

`fft`, `polynomial`, `difficulty:hard`
