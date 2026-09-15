# Sum of Two Integers

## 1. Problem Statement
[LeetCode 371](https://leetcode.com/problems/sum-of-two-integers/) — return `a+b` without using `+` or `-`.

- **Inputs:** ints `a`, `b` (may be negative).
- **Output:** their sum.
- **Valid answer:** exact two’s-complement sum.
- **Edges:** zero; negatives; carry into sign bit.

## 2. Intuition
`a^b` is sum without carry; `(a&b)<<1` is the carry. Repeat until carry is zero — same as a hardware ripple adder.

## 3. Brute Force → Optimal
- **Brute:** increment loops — O(|b|).
- **Optimal:** bitwise adder — O(word size).

## 4. Data Structure / Approach Justification
**Chosen:** loop with unsigned carry shift (avoids signed `<<` UB).

- **vs using `+`:** disallowed.
- **vs asm ADC:** not portable / not interview-friendly.

## 5. Logic Walkthrough
While `b!=0`: `carry=(a&b)<<1` (unsigned); `a^=b`; `b=carry`. Return `a`.

## 6. Dry Run
`3+5`: `3^5=6`, carry `(3&5)<<1=2` → continue → **8**. `-2+3` → **1**.

## 7. Time & Space Complexity
Time **O(1)** word-size iterations. Space **O(1)**. Why: fixed-width adder (section 4).

## 8. Trade-offs & Alternatives
Interview bit-trick; production just uses `+`. Subtract via `getSum(a, ~b+1)` style.

## 9. Common Mistakes / Edge Cases
Left-shifting a signed negative (UB) — cast carry to unsigned; infinite loop if carry mishandled.

## 10. Interview Follow-ups / Variations
Subtract / multiply via bits? Add without loops (intrinsics)?

## 11. Tags
`bit-manipulation`, `math`, `difficulty:medium`
