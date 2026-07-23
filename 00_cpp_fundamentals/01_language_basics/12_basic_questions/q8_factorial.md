# Q8 — Factorial

## 1. Problem Statement
Read a non-negative integer `num` and print `num!` using recursion and using a loop (`unsigned long long`).

- **Input:** `num`
- **Output:** error if negative; otherwise both recursive and iterative results
- **Valid answer:** both methods equal for small n (before overflow)
- **Edges:** `0! = 1`; negatives rejected; overflow beyond ~20! for 64-bit

## 2. Intuition
`n! = n * (n-1)!` with base `0!/1! = 1`. Iteration multiplies upward from 1.

## 3. Brute Force → Optimal
- Both are O(n) multiplications for standard factorial.
- Iterative form is preferred (no stack risk).
- True “optimal” for huge n needs big-integer libraries — out of scope.

## 4. Data Structure / Approach Justification
`unsigned long long` accumulator/return — wider than `int`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `int` only | Overflows very early |
| Recursion | Clear definition; O(n) stack |
| Loop | Same time, O(1) space — better default |

## 5. Logic Walkthrough
1. Reject `num < 0`.
2. `factorialRecursive`: base 0/1 → 1; else `n * f(n-1)`.
3. `factorialLoop`: `fact` starts 1; multiply `i=2..n`.

## 6. Dry Run
`num=5`: recursion `5*4*3*2*1=120`; loop accumulates to 120.

## 7. Time & Space Complexity
| Method | Time | Space |
|--------|------|-------|
| Recursive | O(n) | O(n) stack |
| Loop | O(n) | O(1) |

## 8. Trade-offs & Alternatives
Prefer iterative in production; use big int for n>20; memoization irrelevant for single queries.

## 9. Common Mistakes / Edge Cases
Forgetting `0!`; negative input; silent overflow; missing return in recursion.

## 10. Interview Follow-ups / Variations
Trailing zeros of `n!`; modular factorial; gamma function for reals.

## 11. Tags
`cpp-basics`, `recursion`, `loops`, `factorial`, `beginner`, `practice`
