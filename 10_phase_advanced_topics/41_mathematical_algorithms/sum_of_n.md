# Sum of 1..n

## Problem Statement
Compute the sum of integers from 1 to `n` (inclusive).

- **Inputs:** non-negative integer `n`.
- **Output:** `1+2+…+n`.
- **Valid answer:** exact arithmetic sum (here as `long long`).
- **Edges:** `n=0` → 0; negative input; overflow for huge `n`.

## Intuition
Pair `1+(n)`, `2+(n-1)`, … → `n/2` pairs each summing to `n+1`, giving `n(n+1)/2`.

## Brute Force → Optimal
- **Brute:** loop accumulate — O(n).
- **Optimal:** closed form — O(1).

## Data Structure / Approach Justification
**Chosen:** arithmetic-series formula.

- **vs loop:** same answer, worse asymptotics.
- **vs Gauss pairing story:** same formula, useful interview narrative.

## Logic Walkthrough
If `n<0` reject; else return `n * (n + 1) / 2` using wide integer type.

## Dry Run
`n=10`: `10*11/2 = 55`. Verify: `1+…+10=55`.

## Time & Space Complexity
Time **O(1)**. Space **O(1)**. Why: direct formula (section 4).

## Trade-offs & Alternatives
Loop is clearer for absolute beginners; formula is interview-correct. For modular sums, multiply with modular inverse of 2.

## Common Mistakes / Edge Cases
`(n*(n+1))/2` overflowing `int`; integer division order when using mods.

## Interview Follow-ups / Variations
Sum of squares / cubes; sum in `[L,R]`; modular arithmetic series.

## Tags
`math`, `arithmetic-series`, `closed-form`, `difficulty:easy`
