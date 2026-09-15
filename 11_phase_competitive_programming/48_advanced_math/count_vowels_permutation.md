# Count Vowels Permutation (LC 1220)

## 1. Problem Statement
[LeetCode 1220 — Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/): count length-n vowel strings under transition rules mod 1e9+7.

## 2. Intuition
5-state transfer; linear recurrence.

## 3. Brute Force → Optimal
- **Brute:** slower method.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** rolling 5 counters.

**Pedagogy:** Transfer-matrix advanced math.

## 5. Logic Walkthrough
See implementation and dry run.

## 6. Dry Run
n=1→5; n=2→10.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Matrix/FFT/NTT choice depends on modulus, precision, and n size.

## 9. Common Mistakes / Edge Cases
Off-by-one exponents; overflow before mod; wrong identity matrix; FFT padding; singular pivots.

## 10. Interview Follow-ups / Variations
Higher-order recurrences; modular NTT; path counting; interpolation tricks.

## 11. Tags
`leetcode-1220`, `dp`, `difficulty:hard`
