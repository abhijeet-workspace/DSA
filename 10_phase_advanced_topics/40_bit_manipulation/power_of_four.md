# Power of Four

## Problem Statement
[LeetCode 342](https://leetcode.com/problems/power-of-four/) — return `true` if `n` is a power of four (`1, 4, 16, 64, …`).

- **Inputs:** `int n`.
- **Output:** bool.
- **Valid answer:** exact power of four.
- **Edges:** `n <= 0`; `1`; powers of two that are not powers of four (`2, 8, 32`).

## Intuition
Must be a power of two, and the single set bit must sit on an even index (0-based from the LSB): bits `0, 2, 4, …`.

## Brute Force → Optimal
- **Brute:** divide by 4 while divisible.
- **Optimal:** power-of-two check plus mask `0x55555555` (bits in even positions).

## Data Structure / Approach Justification
**Chosen:** `(n & (n-1)) == 0` and `(n & 0x55555555) != 0`.

- **vs loop:** O(1) bit check.
- **vs `n % 3 == 1` among powers of two:** also valid; mask is explicit about bit position.

## Logic Walkthrough
Reject non-positive / non-power-of-two. Require overlap with even-position mask.

## Dry Run
`16 = 10000b` → power of two; bit index 4 even → **true**. `8 = 1000b` → bit index 3 odd → **false**.

## Time & Space Complexity
Time **O(1)**. Space **O(1)**.

## Trade-offs & Alternatives
Division loop is fine for readability.

## Common Mistakes / Edge Cases
Accepting any power of two; wrong mask (`0xAAAAAAAA` is odd positions).

## Interview Follow-ups / Variations
Power of Two (231); Power of Three (326).

## Tags
`bit-manipulation`, `math`, `difficulty:easy`
