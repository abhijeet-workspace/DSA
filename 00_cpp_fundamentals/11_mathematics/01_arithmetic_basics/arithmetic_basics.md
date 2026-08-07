# Arithmetic Basics

## 1. Problem Statement
Practice core integer arithmetic used in every DSA problem:

1. Absolute value
2. Min / max of two values
3. Average of an array (integer + floating)
4. Safe multiply check for overflow risk (conceptual)
5. Sum of first `n` naturals via formula vs loop

- **Input:** demo values in `main`
- **Output:** results of each operation
- **Edges:** negative abs; empty average; `n=0` sum; overflow on large products

## 2. Intuition
Arithmetic is the substrate of algorithms. Prefer formulas when correct (`n(n+1)/2`), loops when the sequence is irregular. Watch signed overflow — undefined behavior in C++.

## 3. Brute Force → Optimal
- Sum of 1..n: loop O(n) vs closed form O(1).
- Min/max: branch or `std::min` / `std::max` — same asymptotics.
- Average: single pass accumulate then divide.

## 4. Data Structure / Approach Justification
Scalars and a small `int` array — no containers needed.

| Alternative | Why it loses here |
|-------------|-------------------|
| Big-integer libs | Overkill for fundamentals |
| Floating sum of integers | Precision noise; prefer exact formula when possible |

## 5. Logic Walkthrough
1. `absVal(-7)` → 7 via ternary / branch.
2. `minOf(3, 9)` / `maxOf(3, 9)`.
3. Sum array then divide for average.
4. Compare loop sum vs `n*(n+1)/2`.

## 6. Dry Run
| Op | Input | Result |
|----|-------|--------|
| abs | -7 | 7 |
| min/max | 3, 9 | 3 / 9 |
| avg | {2,4,6} | 4 |
| sum 1..5 | formula | 15 |

## 7. Time & Space Complexity
- Abs / min / max: O(1)
- Average of n elems: O(n) time, O(1) space
- Sum 1..n formula: O(1)

## 8. Trade-offs & Alternatives
Use `long long` for intermediate products. Prefer `std::abs` / `<algorithm>` min-max in real code; reimplement here for learning.

## 9. Common Mistakes / Edge Cases
- `abs(INT_MIN)` overflow on two’s complement
- Integer division truncating average
- Writing `n*(n+1)/2` with `int` when `n` is large

## 10. Interview Follow-ups / Variations
Running average online; Kahan summation; checked arithmetic APIs.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `arithmetic`, `beginner`

## 12. Next Steps
Continue to `02_divisors_gcd_lcm`. Advanced number theory lives in `10_phase_advanced_topics/41_mathematical_algorithms` and `11_phase_competitive_programming/45_number_theory`.
