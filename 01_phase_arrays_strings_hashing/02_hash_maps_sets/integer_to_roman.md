# Integer to Roman

## Problem Statement
[LeetCode 12](https://leetcode.com/problems/integer-to-roman/) — convert an integer `num` in `[1, 3999]` to its Roman numeral string.

- **Inputs:** `int num` (`1 ≤ num ≤ 3999`).
- **Output:** Roman string using `I V X L C D M` and subtractive pairs `IV, IX, XL, XC, CD, CM`.
- **Edges:** pure additive (`3 → III`); mix with subtractives (`1994 → MCMXCIV`); single place values (`58 → LVIII`).

## Intuition
Roman numerals are a place-value system with a fixed ordered list of tokens (including the six subtractive pairs). Always emit the largest token that does not exceed the remaining value.

## Brute Force → Optimal
- **Brute:** hardcode digit→Roman maps for thousands / hundreds / tens / ones — correct, repetitive.
- **Optimal:** one descending table of `(value, symbol)` including subtractives; greedy subtract — O(1) tokens, O(length) output.

## Data Structure / Approach Justification
**Chosen:** static vector of 13 `(value, symbol)` pairs (greedy + lookup table; pairs with hash-map/string topic).

| Alternative | Why it loses here |
|-------------|-------------------|
| Per-digit switch maps | Same result; more branches, less uniform |
| Recursion / DP | Overkill for fixed alphabet and range |

## Logic Walkthrough
1. Table (desc): `M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I`.
2. For each `(val, sym)`: while `num >= val`, append `sym` and subtract `val`.
3. Return the built string.

## Dry Run
`1994`: `M` → 994; `CM` → 94; `XC` → 4; `IV` → 0 → **MCMXCIV**.

## Time & Space Complexity
Time **O(1)** relative to input magnitude (at most a few dozen appends for `≤ 3999`); output length **O(1)** bounded. Space **O(1)** aux + output string.

## Trade-offs & Alternatives
Digit-bucket maps are fine in interviews if you remember the tables; the unified greedy table is easier to recall and verify.

## Common Mistakes / Edge Cases
Forgetting subtractive tokens (`4` as `IIII`); emitting smaller before larger incorrectly; off-by-one when `num` equals a table value.

## Interview Follow-ups / Variations
Roman to Integer (13); validate a Roman string; extend beyond 3999 with overline notation.

## Tags
`greedy`, `string`, `math`, `hash-map`, `leetcode-12`, `difficulty:medium`
