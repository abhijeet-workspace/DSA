# Divide Two Integers

## Problem Statement
[LeetCode 29](https://leetcode.com/problems/divide-two-integers/) — compute `dividend / divisor` truncated toward zero **without** using `*`, `/`, or `%`. If the true quotient overflows 32-bit signed range, return `INT_MAX`.

- **Inputs:** ints `dividend`, `divisor` (`divisor != 0`).
- **Output:** truncated quotient in `[-2^31, 2^31-1]`.
- **Edges:** `INT_MIN / -1` (overflow → `INT_MAX`); `INT_MIN / 1`; negatives; `|dividend| < |divisor|` → `0`.

## Intuition
Division is repeated subtraction. Subtracting one `divisor` at a time is too slow. Double the current chunk (`temp`, `multiple`) with left shifts so each step peels off the largest power-of-two multiple of `|divisor|` that still fits in the remainder — same idea as long division in binary.

## Brute Force → Optimal
- **Brute:** subtract `divisor` once per unit of quotient — O(|quotient|), TLE on large magnitudes.
- **Optimal:** exponential / bit-shift doubling — O(log |dividend| × log |dividend|) ≈ O(32²) for 32-bit ints.

## Data Structure / Approach Justification
**Chosen:** work in `long long` absolutes + shift-doubling subtract loop; track sign with XOR of positivity.

| Alternative | Why it loses here |
|-------------|-------------------|
| `dividend / divisor` | Forbidden |
| Float / `log` tricks | Precision / interview-hostile |
| Pure bit-by-bit from MSB | Also fine; shift-doubling is clearer |

## Logic Walkthrough
1. Special-case `INT_MIN / -1` → `INT_MAX`.
2. `negative = (dividend > 0) ^ (divisor > 0)`; take `llabs` of both into `a`, `b`.
3. While `a >= b`: find largest `temp = b << k` with `a >= temp`; add `1 << k` to quotient; `a -= temp`.
4. Negate quotient if `negative`; cast to `int`.

## Dry Run
`10 / 3`: `|a|=10`, `|b|=3` → peel `3*2=6` (multiple 2), rem 4 → peel `3` (multiple 1) → quotient **3**.  
`7 / -3` → abs quotient 2, sign negative → **-2**.  
`INT_MIN / -1` → clamp **INT_MAX**.

## Time & Space Complexity
Time **O(log² |dividend|)** (outer peels × inner doubling). Space **O(1)**.

## Trade-offs & Alternatives
MSB bit-building from bit 31 down is another O(32) style. Production uses hardware `/`.

## Common Mistakes / Edge Cases
Not handling `INT_MIN` abs (use `long long`); forgetting overflow clamp; truncating toward −∞ instead of zero; signed left-shift UB if staying in `int`.

## Interview Follow-ups / Variations
Multiply without `*`; remainder without `%`; 64-bit dividend / 32-bit divisor.

## Tags
`bit-manipulation`, `math`, `leetcode-29`, `difficulty:medium`
