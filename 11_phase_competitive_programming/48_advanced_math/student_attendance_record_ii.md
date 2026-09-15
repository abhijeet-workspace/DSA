# Student Attendance Record II (LC 552)

## 1. Problem Statement
[LeetCode 552 — Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/): count records length n with <2 A and no 3 consecutive L, mod 1e9+7.

## 2. Intuition
DP (absences, trailing lates).

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** 2×3 state rolling DP.

**Pedagogy:** Linear DP / matrix-exp candidate.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
n=1→3; n=2→8.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-552`, `dp`, `difficulty:hard`
