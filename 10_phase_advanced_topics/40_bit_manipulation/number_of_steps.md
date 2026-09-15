# Number of Steps to Reduce a Number to Zero

## 1. Problem Statement
[LeetCode 1342](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) — if even divide by 2, else subtract 1; return steps until `0`.

- **Inputs:** non-negative `int num`.
- **Output:** step count.
- **Edges:** `0`; powers of two; odd numbers.

## 2. Intuition
Each subtract clears a `1` bit; each divide shifts right. Steps = (#set bits − 1) + (bit length − 1) for `num > 0`.

## 3. Brute Force → Optimal
- **Simulate:** loop until zero — O(log num).
- **Bit formula:** `popcount(num) + floor(log2(num)) - 1` for `num > 0`.

## 4. Data Structure / Approach Justification
**Chosen:** simulation (clearest). Bit formula is O(1) with builtins.

## 5. Logic Walkthrough
While `num`: if odd `--num` else `num >>= 1`; `++steps`.

## 6. Dry Run
`14` → 7 → 6 → 3 → 2 → 1 → 0 → **6** steps.

## 7. Time & Space Complexity
Time **O(log num)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Bit formula avoids a loop when builtins are allowed.

## 9. Common Mistakes / Edge Cases
`num == 0` → 0 steps; off-by-one on the formula for `1`.

## 10. Interview Follow-ups / Variations
Integer replacement (397); Collatz-style variants.

## 11. Tags
`bit-manipulation`, `math`, `simulation`, `difficulty:easy`
