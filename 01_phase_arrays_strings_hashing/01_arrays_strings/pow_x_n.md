# Pow(x, n)

## Problem Statement
[LeetCode 50](https://leetcode.com/problems/powx-n/) — compute `x` raised to the power `n` (integer exponent, possibly negative).

- **Inputs:** `double x`, `int n` (use `long long` internally for `-INT_MIN`).
- **Output:** `double` approximation of `x^n`.
- **Valid answer:** within floating tolerance of true power.
- **Edges:** `n=0`; `n=INT_MIN`; `x=0`; negative `n`.

## Intuition
Binary exponentiation: `x^n = (x^2)^(n/2)` with an extra `x` when `n` is odd. Negative `n` → compute `(1/x)^|n|`.

## Brute Force → Optimal
- **Brute:** multiply `x` by itself `|n|` times — O(|n|), TLE for large `|n|`.
- **Optimal:** binary exponentiation — O(log |n|).

## Data Structure / Approach Justification
**Chosen:** iterative binary exponentiation with `long long n`.

- **vs recursive `pow`:** same asymptotics; iterative avoids stack depth.
- **vs `std::pow`:** fine in production; interview wants the algorithm.

## Logic Walkthrough
If `n<0`, invert `x` and negate `n`. While `n`: if LSB set, `ans*=x`; then `x*=x`, `n>>=1`.

## Dry Run
`x=2`, `n=10` (`1010b`): square path yields **1024**.

## Time & Space Complexity
Time **O(log |n|)**. Space **O(1)**. Why: one step per bit of `n` (section 4).

## Trade-offs & Alternatives
Recursive form is cleaner to explain; iterative is safer for extreme `|n|`.

## Common Mistakes / Edge Cases
`n = -2147483648` overflowing when negated as `int`; forgetting negative-exponent invert; using `int` for `n` loop.

## Interview Follow-ups / Variations
Modular exponentiation; matrix exponentiation; fractional powers.

## Tags
`math`, `binary-exponentiation`, `bit-manipulation`, `difficulty:medium`
