# Power of Two

## Problem Statement
[LeetCode 231](https://leetcode.com/problems/power-of-two/) — return `true` if `n` is a power of two (`1, 2, 4, …`).

- **Inputs:** `int n`.
- **Output:** bool.
- **Valid answer:** exact power of two in the positive integers.
- **Edges:** `n <= 0`; `1` (`2^0`); large powers near `INT_MAX`.

## Intuition
A positive power of two has exactly one set bit. Clearing the lowest set bit yields zero.

## Brute Force → Optimal
- **Brute:** divide by 2 while even — O(log n).
- **Optimal:** `n > 0 && (n & (n - 1)) == 0` — O(1).

## Data Structure / Approach Justification
**Chosen:** single-bit check via Kernighan idiom.

- **vs loop divide:** same result; bit check is constant-time.
- **vs `__builtin_popcount == 1`:** equivalent idea.

## Logic Walkthrough
Reject non-positive. Return whether `n & (n-1)` is zero.

## Dry Run
`16 = 10000b` → `16 & 15 = 0` → **true**. `6 = 110b` → `6 & 5 = 4` → **false**.

## Time & Space Complexity
Time **O(1)**. Space **O(1)**.

## Trade-offs & Alternatives
Division loop is more readable for interviews that ban bit tricks.

## Common Mistakes / Edge Cases
Forgetting `n > 0` (`0` and negatives); assuming `INT_MIN` bit tricks are safe.

## Interview Follow-ups / Variations
Power of Three (326); Power of Four (342); count set bits (191).

## Tags
`bit-manipulation`, `math`, `difficulty:easy`
