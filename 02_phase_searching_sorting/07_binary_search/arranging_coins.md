# Arranging Coins

## Problem Statement
[LeetCode 441](https://leetcode.com/problems/arranging-coins/) — n coins form a staircase; row i needs i coins. Return how many complete rows you can build.

- **Inputs:** `int n`.
- **Output:** `int` complete rows.
- **Valid answer:** max `k` with `k(k+1)/2 <= n`.
- **Edges:** `n=1`; exact triangle; overflow on `k*(k+1)`.

## Intuition
Prefix sums of rows are monotone → binary search `k`.

## Brute Force → Optimal
- **Brute:** subtract i=1,2,... — O(√n).
- **Optimal:** binary search / closed form `(-1+sqrt(1+8n))/2`.

## Data Structure / Approach Justification
**Chosen:** search-on-answer with `long long` triangular number.

- **vs formula:** needs careful floating conversion
- **vs linear:** fine for small n only

## Logic Walkthrough
If `mid*(mid+1)/2 <= n`, try larger k.

## Dry Run
`n=8` → k=3 uses 6, k=4 needs 10 → 3.

## Time & Space Complexity
Time **O(log n)**. Space **O(1)**. Why: binary search k in [0,n].

## Trade-offs & Alternatives
Closed form is O(1) if sqrt is trusted.

## Common Mistakes / Edge Cases
32-bit overflow; off-by-one on exact triangles.

## Interview Follow-ups / Variations
Sqrt(x); valid perfect square.

## Tags
`binary-search`, `math`, `leetcode-441`, `difficulty:easy`
