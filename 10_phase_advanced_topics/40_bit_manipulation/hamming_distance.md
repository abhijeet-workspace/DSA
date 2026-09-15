# Hamming Distance

## 1. Problem Statement
[LeetCode 461](https://leetcode.com/problems/hamming-distance/) — Hamming distance of two integers is the number of differing bits.

- **Inputs:** `int x`, `int y`.
- **Output:** count of differing bits.
- **Valid answer:** `popcount(x ^ y)`.
- **Edges:** equal values; one zero; large 32-bit values.

## 2. Intuition
XOR marks differing bits; count set bits in the XOR.

## 3. Brute Force → Optimal
- **Brute:** compare each of 32 bits.
- **Optimal:** `popcount(x^y)` / Brian Kernighan.

## 4. Data Structure / Approach Justification
**Chosen:** Kernighan `n &= n-1` loop on `x^y`.

- **vs `__builtin_popcount`:** fine in contests; portable loop is clearer for teaching.

## 5. Logic Walkthrough
`n = x^y`; while n: clear lowest set bit, ++ans.

## 6. Dry Run
`x=1,y=4` → `101` vs `001` → XOR `100` → **1**.

## 7. Time & Space Complexity
Time **O(set bits) ≤ O(32)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Hardware popcount is faster; same idea.

## 9. Common Mistakes / Edge Cases
Comparing bits without XOR; infinite loop if not clearing bits.

## 10. Interview Follow-ups / Variations
Total Hamming Distance (477); Hamming weight (191).

## 11. Tags
`bit-manipulation`, `popcount`, `leetcode-461`, `difficulty:easy`
