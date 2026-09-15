# Sum of 1..n

## 1. Problem Statement
Compute the sum of integers from 1 to `n` (inclusive).

- **Inputs:** non-negative integer `n`.
- **Output:** `1+2+…+n`.
- **Valid answer:** exact arithmetic sum (here as `long long`).
- **Edges:** `n=0` → 0; negative input; overflow for huge `n`.

## 2. Intuition
Pair `1+(n)`, `2+(n-1)`, … → `n/2` pairs each summing to `n+1`, giving `n(n+1)/2`.

## 3. Brute Force → Optimal
- **Brute:** loop accumulate — O(n).
- **Optimal:** closed form — O(1).

## 4. Data Structure / Approach Justification
**Chosen:** arithmetic-series formula.

- **vs loop:** same answer, worse asymptotics.
- **vs Gauss pairing story:** same formula, useful interview narrative.

## 5. Logic Walkthrough
If `n<0` reject; else return `n * (n + 1) / 2` using wide integer type.

## 6. Dry Run
`n=10`: `10*11/2 = 55`. Verify: `1+…+10=55`.

## 7. Time & Space Complexity
Time **O(1)**. Space **O(1)**. Why: direct formula (section 4).

## 8. Trade-offs & Alternatives
Loop is clearer for absolute beginners; formula is interview-correct. For modular sums, multiply with modular inverse of 2.

## 9. Common Mistakes / Edge Cases
`(n*(n+1))/2` overflowing `int`; integer division order when using mods.

## 10. Interview Follow-ups / Variations
Sum of squares / cubes; sum in `[L,R]`; modular arithmetic series.

## 11. Tags
`math`, `arithmetic-series`, `closed-form`, `difficulty:easy`
