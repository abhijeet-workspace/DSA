# Sqrt(x)

## Problem Statement
[LeetCode 69](https://leetcode.com/problems/sqrtx/) — return the integer square root of `x` (floor of √x) without floating `sqrt`.

- **Inputs:** `int x` in `[0, 2^31-1]`.
- **Output:** `int`.
- **Valid answer:** largest `y` with `y*y <= x`.
- **Edges:** `0`, `1`; non-squares; overflow.

## Intuition
Search-on-answer: feasibility `mid*mid <= x` is monotone.

## Brute Force → Optimal
- **Brute:** linear y=1,2,... — O(√x).
- **Optimal:** binary search — O(log x).

## Data Structure / Approach Justification
**Chosen:** keep the last feasible `mid`.

- **vs Newton integer:** faster constants; harder to get rounding right
- **vs valid perfect square:** here we want floor, not equality

## Logic Walkthrough
`hi = x/2` for `x>=2`. If square too small, record `ans` and go right.

## Dry Run
`x=8` → 2 because 3²=9>8.

## Time & Space Complexity
Time **O(log x)**. Space **O(1)**. Why: binary search the root.

## Trade-offs & Alternatives
Newton is an interview follow-up.

## Common Mistakes / Edge Cases
Overflow; returning mid after the loop instead of last feasible.

## Interview Follow-ups / Variations
Valid perfect square (367); pow(x,n).

## Tags
`binary-search`, `math`, `leetcode-69`, `difficulty:easy`
