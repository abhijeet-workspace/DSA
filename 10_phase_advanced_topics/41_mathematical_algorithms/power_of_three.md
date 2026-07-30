# Power of Three

## Problem Statement
[LeetCode 326](https://leetcode.com/problems/power-of-three/) — return `true` if `n` is a power of three (`1, 3, 9, 27, …`).

- **Inputs:** `int n`.
- **Output:** bool.
- **Valid answer:** exact power of three in the positive integers.
- **Edges:** `n <= 0`; `1` (`3^0`); largest `3^k` fitting in 32-bit int.

## Intuition
Repeatedly divide by 3 while divisible; end at 1. Or check divisibility against the max `3^k` in `int` range.

## Brute Force → Optimal
- **Brute / loop:** while `n % 3 == 0`, `n /= 3`; return `n == 1`.
- **O(1):** `n > 0 && 1162261467 % n == 0` where `1162261467 = 3^19` (max in 32-bit signed).

## Data Structure / Approach Justification
**Chosen:** max-power divisibility — O(1), no loops.

- **vs loop:** clearer for teaching; same asymptotic for fixed bit width.
- **vs log:** floating error risk.

## Logic Walkthrough
Reject non-positive. Return whether max `3^19` is divisible by `n` (only powers of three divide it among positives ≤ that value).

## Dry Run
`27` → `1162261467 % 27 == 0` → **true**. `45` → nonzero remainder → **false**.

## Time & Space Complexity
Time **O(1)**. Space **O(1)**.

## Trade-offs & Alternatives
Loop is safer if the language int width is unknown.

## Common Mistakes / Edge Cases
`n <= 0`; floating `log` rounding; wrong max exponent for the type width.

## Interview Follow-ups / Variations
Power of Two (231); Power of Four (342).

## Tags
`math`, `integer`, `difficulty:easy`
