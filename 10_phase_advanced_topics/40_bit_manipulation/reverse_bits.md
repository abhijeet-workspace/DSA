# Reverse Bits

## Problem Statement
[LeetCode 190](https://leetcode.com/problems/reverse-bits/) — reverse the bits of a 32-bit unsigned integer.

- **Inputs:** `uint32_t n`.
- **Output:** bit-reversed `uint32_t`.
- **Valid answer:** exact 32-bit reverse (leading zeros become trailing).
- **Edges:** `0`; all ones; already palindromic bits.

## Intuition
Build `res` by repeatedly taking `n`'s LSB and shifting it into `res` from the left — always exactly 32 iterations.

## Brute Force → Optimal
- **Brute / loop:** 32 steps (fixed width) — already optimal for clarity.
- **Faster:** parallel swap halves/bytes/nibbles or lookup tables.

## Data Structure / Approach Justification
**Chosen:** 32-iter shift loop.

- **vs byte lookup:** faster in hot paths.
- **vs early exit when n==0:** wrong — drops high zero bits in output.

## Logic Walkthrough
For `i in 0..31`: `res = (res<<1)|(n&1)`; `n>>=1`.

## Dry Run
`43261596` → `964176192`. `0` → `0`.

## Time & Space Complexity
Time **O(1)** — 32 iterations. Space **O(1)**. Why: fixed word width (section 4).

## Trade-offs & Alternatives
Parallel reverse is cooler systems trivia; loop is the interview default.

## Common Mistakes / Edge Cases
Breaking early when `n` becomes 0; using signed shifts; running only while `n` is nonzero.

## Interview Follow-ups / Variations
Reverse bytes only? Variable bit-width? Reverse in place with masks.

## Tags
`bit-manipulation`, `difficulty:easy`
