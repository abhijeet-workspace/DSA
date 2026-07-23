# FFT Polynomial Multiply

## Problem Statement
Multiply two polynomials (coefficient convolution) in near-linear time via FFT.

- **Inputs:** coefficient vectors `a`, `b` (low degree first).
- **Output:** product coefficients (length ≥ deg(a)+deg(b)+1).
- **Valid answer:** exact integers after rounding complex DFT results (small coeffs).
- **Edges:** empty poly; pad to power of two; large coeffs → precision risk.

## Intuition
DFT turns convolution into pointwise products. Evaluate both polys at roots of unity (FFT), multiply values, inverse FFT back to coefficients.

## Brute Force → Optimal
- **Brute:** schoolbook Σ a[i]b[k−i] — O(N²).
- **Optimal:** recursive Cooley–Tukey FFT — O(N log N).

## Data Structure / Approach Justification
**Chosen:** `complex<double>` recursive FFT with in-place butterfly merge.

- **vs NTT:** modular exactness when working mod prime with root of unity.
- **vs Karatsuba:** O(N^{1.58}) without trig; still slower asymptotically than FFT.

## Logic Walkthrough
Pad both to next power of two ≥ |a|+|b|. FFT both; pointwise multiply; inverse FFT; `llround` reals to integer coeffs.

## Dry Run
`(1+2x+3x²)·(2+3x)`:
- schoolbook: 2 + (3+4)x + (6+6)x² + 9x³ = `2,7,12,9`
- FFT path yields same after round.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)** for buffers. Why: each FFT level O(N), log N levels (section 4).

## Trade-offs & Alternatives
Float FFT needs care with large ints; prefer NTT for modular contests. Iterative bit-reversal FFT reduces recursion overhead.

## Common Mistakes / Edge Cases
Forgetting pad length; skipping invert divide-by-2 (or /n); using size |a| not |a|+|b|; precision overflow.

## Interview Follow-ups / Variations
String matching via FFT; online convolution; NTT template; multipoint evaluation.

## Tags
`fft`, `polynomial`, `convolution`, `divide-conquer`, `difficulty:hard`
