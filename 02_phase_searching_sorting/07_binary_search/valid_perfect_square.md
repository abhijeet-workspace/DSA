# Valid Perfect Square

## Problem Statement
[LeetCode 367](https://leetcode.com/problems/valid-perfect-square/) — return whether `num` is a perfect square without using library `sqrt`.

- **Inputs:** `int num` in `[1, 2^31-1]`.
- **Output:** `bool`.
- **Valid answer:** exists integer `x` with `x*x == num`.
- **Edges:** `1`; large non-square; overflow around `46340^2`.

## Intuition
Squares are monotone in `x`, so binary search `x` in `[1, num]`.

## Brute Force → Optimal
- **Brute:** try every x — O(√num).
- **Optimal:** binary search — O(log num).

## Data Structure / Approach Justification
**Chosen:** `long long` product to avoid overflow.

- **vs Newton:** also O(log); BS is simpler to prove
- **vs sqrt then square:** forbidden / precision issues

## Logic Walkthrough
Compare `mid*mid` to `num` and shrink.

## Dry Run
`16` → mid hits 4. `14` → never equals.

## Time & Space Complexity
Time **O(log num)**. Space **O(1)**. Why: binary search on the integer root.

## Trade-offs & Alternatives
Same as Sqrt(x) (69) but equality instead of floor.

## Common Mistakes / Edge Cases
32-bit overflow on `mid*mid`; starting hi at num/2 incorrectly for 1.

## Interview Follow-ups / Variations
Sqrt(x) (69); arranging coins (441).

## Tags
`binary-search`, `math`, `leetcode-367`, `difficulty:easy`
