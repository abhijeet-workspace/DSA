# Reverse Bits

## 1. Problem Statement
[LeetCode 190](https://leetcode.com/problems/reverse-bits/) — reverse the bits of a 32-bit unsigned integer.

- **Inputs:** `uint32_t n`.
- **Output:** bit-reversed `uint32_t`.
- **Valid answer:** exact 32-bit reverse (leading zeros become trailing).
- **Edges:** `0`; all ones; already palindromic bits.

## 2. Intuition
Build `res` by repeatedly taking `n`'s LSB and shifting it into `res` from the left — always exactly 32 iterations.

## 3. Brute Force → Optimal
- **Brute / loop:** 32 steps (fixed width) — already optimal for clarity.
- **Faster:** parallel swap halves/bytes/nibbles or lookup tables.

## 4. Data Structure / Approach Justification
**Chosen:** 32-iter shift loop.

- **vs byte lookup:** faster in hot paths.
- **vs early exit when n==0:** wrong — drops high zero bits in output.

## 5. Logic Walkthrough
For `i in 0..31`: `res = (res<<1)|(n&1)`; `n>>=1`.

## 6. Dry Run
`43261596` → `964176192`. `0` → `0`.

## 7. Time & Space Complexity
Time **O(1)** — 32 iterations. Space **O(1)**. Why: fixed word width (section 4).

## 8. Trade-offs & Alternatives
Parallel reverse is cooler systems trivia; loop is the interview default.

## 9. Common Mistakes / Edge Cases
Breaking early when `n` becomes 0; using signed shifts; running only while `n` is nonzero.

## 10. Interview Follow-ups / Variations
Reverse bytes only? Variable bit-width? Reverse in place with masks.

## 11. Tags
`bit-manipulation`, `difficulty:easy`
