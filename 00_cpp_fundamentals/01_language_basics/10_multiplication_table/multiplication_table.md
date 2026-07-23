# Multiplication Table

## 1. Problem Statement
Read a base `number` and a `limit`, then print the multiplication table: `number * i = product` for `i = 1..limit`.

- **Input:** two integers — `number`, `limit`
- **Output:** `limit` lines of products
- **Valid answer:** line i shows `number * i`
- **Edges:** `limit <= 0` prints nothing; large products may overflow `int`

## 2. Intuition
A counted `for` loop is the natural fit when the iteration count is known up front (`limit`).

## 3. Brute Force → Optimal
- **Naive:** hardcode ten `cout` lines for a fixed table of 10.
- **This approach:** parameterize `number` and `limit` in a helper so any table size works.

## 4. Data Structure / Approach Justification
No container — loop + arithmetic.

| Alternative | Why it loses here |
|-------------|-------------------|
| Recursion | Extra stack risk; no clarity win |
| Precompute vector of products | Unnecessary storage for a print-only task |

## 5. Logic Walkthrough
1. Read `number` and `limit` in `main`.
2. `multiplicationTable` loops `i` from 1 to `limit`.
3. Each iteration prints `number`, `i`, and `number * i`.

## 6. Dry Run
`number = 3`, `limit = 4`:

| i | Printed |
|---|---------|
| 1 | `3 * 1 = 3` |
| 2 | `3 * 2 = 6` |
| 3 | `3 * 3 = 9` |
| 4 | `3 * 4 = 12` |

## 7. Time & Space Complexity
- **Time:** O(limit)
- **Space:** O(1)
- Why: one pass; constant extra memory

## 8. Trade-offs & Alternatives
- Use `long long` for products if overflow matters.
- Validate `limit > 0` before looping in production.
- Format with `iomanip` if aligned columns are required.

## 9. Common Mistakes / Edge Cases
- Off-by-one (`i < limit` vs `i <= limit`)
- Integer overflow on large `number * i`
- Negative `limit` (loop body skipped)
- Typos in function naming (older code had `multiplactionTable`)

## 10. Interview Follow-ups / Variations
- Print a full n×n grid instead of one row?
- Generate table without multiplication operator (addition only)?
- Stream results to a file?

## 11. Tags
`cpp-basics`, `loops`, `arithmetic`, `beginner`
