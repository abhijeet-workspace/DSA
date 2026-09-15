# Matrix Exponentiation

## 1. Problem Statement

Compute F_n mod 1e9+7 via 2×2 matrix power.

## 2. Intuition

Linear recurrence ↔ transition matrix^n.

## 3. Brute Force → Optimal

- **Brute:** O(n).
- **Optimal:** O(log n) matrix.

## 4. Data Structure / Approach Justification

**Chosen:** matrix mul + binary exp.

**Pedagogy:** General template; LC drills reuse transitions.

## 5. Logic Walkthrough

See implementation and dry run.

## 6. Dry Run

F_10=55.

## 7. Time & Space Complexity

O(D³ log n).

## 8. Trade-offs & Alternatives

Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases

Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations

Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags

`matrix-exponentiation`, `fibonacci`, `difficulty:medium`
