# Power of Three

## 1. Problem Statement
[LeetCode 326](https://leetcode.com/problems/power-of-three/) — return `true` if `n` is a power of three (`1, 3, 9, 27, …`).

- **Inputs:** `int n`.
- **Output:** bool.
- **Valid answer:** exact power of three in the positive integers.
- **Edges:** `n <= 0`; `1` (`3^0`); largest `3^k` fitting in 32-bit int.

## 2. Intuition
Repeatedly divide by 3 while divisible; end at 1. Or check divisibility against the max `3^k` in `int` range.

## 3. Brute Force → Optimal
- **Brute / loop:** while `n % 3 == 0`, `n /= 3`; return `n == 1`.
- **O(1):** `n > 0 && 1162261467 % n == 0` where `1162261467 = 3^19` (max in 32-bit signed).

## 4. Data Structure / Approach Justification
**Chosen:** max-power divisibility — O(1), no loops.

- **vs loop:** clearer for teaching; same asymptotic for fixed bit width.
- **vs log:** floating error risk.

## 5. Logic Walkthrough
Reject non-positive. Return whether max `3^19` is divisible by `n` (only powers of three divide it among positives ≤ that value).

## 6. Dry Run
`27` → `1162261467 % 27 == 0` → **true**. `45` → nonzero remainder → **false**.

## 7. Time & Space Complexity
Time **O(1)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Loop is safer if the language int width is unknown.

## 9. Common Mistakes / Edge Cases
`n <= 0`; floating `log` rounding; wrong max exponent for the type width.

## 10. Interview Follow-ups / Variations
Power of Two (231); Power of Four (342).

## 11. Tags
`math`, `integer`, `difficulty:easy`
