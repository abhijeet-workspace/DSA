# Q6 — Multiplication Table

## 1. Problem Statement
Read `num` and `limit`; print `num * i = product` for `i = 1..limit`.

- **Input:** two integers
- **Output:** `limit` product lines
- **Valid answer:** ith line uses multiplier `i`
- **Edges:** `limit <= 0` prints nothing; overflow on large products

## 2. Intuition
Counted `for` loop when the upper bound is known.

## 3. Brute Force → Optimal
- **Naive:** hardcode 10 lines.
- **This approach:** parameterized helper `multiplicationTable(number, limit)`.

## 4. Data Structure / Approach Justification
No container — loop arithmetic.

| Alternative | Why it loses here |
|-------------|-------------------|
| Recursion | Extra stack, no clarity win |
| Store products in a vector | Unnecessary for print-only |

## 5. Logic Walkthrough
1. Read `num`, `limit`.
2. Loop `i` from 1 to `limit`, print `number * i`.

## 6. Dry Run
`num=5`, `limit=3` → lines for 5, 10, 15.

## 7. Time & Space Complexity
- **Time:** O(limit)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Use `long long` for products; validate positive `limit`.

## 9. Common Mistakes / Edge Cases
Off-by-one; overflow; negative limit.

## 10. Interview Follow-ups / Variations
Full n×n grid; addition-only multiplication.

## 11. Tags
`cpp-basics`, `loops`, `arithmetic`, `beginner`, `practice`
