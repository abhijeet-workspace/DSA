# Reverse Integer

## Problem Statement
[LeetCode 7](https://leetcode.com/problems/reverse-integer/) — reverse digits of a 32-bit signed integer; return `0` if the reversed value overflows `int`.

- **Inputs:** `int x`.
- **Output:** reversed `int`, or `0` on overflow.
- **Valid answer:** digit reverse with sign preserved via `%` toward zero in C++.
- **Edges:** trailing zeros (`120` → `21`); `INT_MIN`/`INT_MAX` overflow; negative numbers.

## Intuition
Pop digits with `%10` / `/10` and push into `ans`. Before `ans = ans*10 + d`, check against `INT_MAX/10` and `INT_MIN/10` bounds.

## Brute Force → Optimal
- **Brute:** to-string reverse — easy overflow handling via `stoll` checks.
- **Optimal:** pure arithmetic with pre-overflow checks — O(log |x|).

## Data Structure / Approach Justification
**Chosen:** integer pop/push with explicit overflow guards (no 64-bit cheat if constrained).

- **vs `long long` accumulator:** simpler; some interviewers disallow wider type.
- **vs string:** clearer but less “bit/math” flavored.

## Logic Walkthrough
While `x`: extract `d`, reject if `ans` would overflow, then `ans = ans*10 + d`.

## Dry Run
`123` → digits 3,2,1 → **321**. `1534236469` → overflow → **0**.

## Time & Space Complexity
Time **O(log |x|)** digits. Space **O(1)**. Why: process each digit once (section 4).

## Trade-offs & Alternatives
`long long` + range check is cleaner when allowed. String method for teaching digit order.

## Common Mistakes / Edge Cases
Checking overflow after multiply (UB in signed overflow); wrong thresholds `7`/`-8`; assuming `%` sign for negatives incorrectly.

## Interview Follow-ups / Variations
Reverse only within digit string without overflow; palindrome number (9).

## Tags
`math`, `overflow`, `integer`, `difficulty:medium`
