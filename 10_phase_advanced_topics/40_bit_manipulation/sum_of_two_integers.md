# Sum of Two Integers

## Problem Statement
[LeetCode 371](https://leetcode.com/problems/sum-of-two-integers/) — return `a+b` without using `+` or `-`.

- **Inputs:** ints `a`, `b` (may be negative).
- **Output:** their sum.
- **Valid answer:** exact two’s-complement sum.
- **Edges:** zero; negatives; carry into sign bit.

## Intuition
`a^b` is sum without carry; `(a&b)<<1` is the carry. Repeat until carry is zero — same as a hardware ripple adder.

## Brute Force → Optimal
- **Brute:** increment loops — O(|b|).
- **Optimal:** bitwise adder — O(word size).

## Data Structure / Approach Justification
**Chosen:** loop with unsigned carry shift (avoids signed `<<` UB).

- **vs using `+`:** disallowed.
- **vs asm ADC:** not portable / not interview-friendly.

## Logic Walkthrough
While `b!=0`: `carry=(a&b)<<1` (unsigned); `a^=b`; `b=carry`. Return `a`.

## Dry Run
`3+5`: `3^5=6`, carry `(3&5)<<1=2` → continue → **8**. `-2+3` → **1**.

## Time & Space Complexity
Time **O(1)** word-size iterations. Space **O(1)**. Why: fixed-width adder (section 4).

## Trade-offs & Alternatives
Interview bit-trick; production just uses `+`. Subtract via `getSum(a, ~b+1)` style.

## Common Mistakes / Edge Cases
Left-shifting a signed negative (UB) — cast carry to unsigned; infinite loop if carry mishandled.

## Interview Follow-ups / Variations
Subtract / multiply via bits? Add without loops (intrinsics)?

## Tags
`bit-manipulation`, `math`, `difficulty:medium`
