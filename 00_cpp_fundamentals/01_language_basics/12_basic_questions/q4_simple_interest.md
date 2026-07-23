# Q4 — Simple Interest (Months)

## 1. Problem Statement
Compute simple interest when time is given in **months**:  
`SI = (principal * rate * time) / (100 * 12)`.

- **Input:** `principal`, `rate`, `time` (months)
- **Output:** `Simple Interest is: <value>`
- **Valid answer:** matches the monthly formula above
- **Edges:** zero/negative inputs; floating rounding

## 2. Intuition
Classic SI uses years. Here months are converted by dividing by 12 inside the formula so annual rate still applies correctly.

## 3. Brute Force → Optimal
- **Naive:** treat months as years (`/100` only) — wrong by 12×.
- **This approach:** divide by `100 * 12` and isolate the formula in `simpleInterest`.

## 4. Data Structure / Approach Justification
`double` parameters + helper function (no container).

| Alternative | Why it loses here |
|-------------|-------------------|
| Inline formula only in `main` | Harder to reuse/test |
| Integer arithmetic | Truncates money-like values |

## 5. Logic Walkthrough
1. Read `principal`, `rate`, `time`.
2. Call `simpleInterest` → `(P*R*T)/(100*12)`.
3. Print `interest`.

## 6. Dry Run
P=1200, R=10, T=12 months → `(1200*10*12)/(100*12) = 120`.

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Prefer integer cents for currency; prefer year input if the problem states years; compound interest is a different formula.

## 9. Common Mistakes / Edge Cases
Forgetting the `*12` for monthly time; integer division if all operands are `int`; naming typo `simpleIntrest`.

## 10. Interview Follow-ups / Variations
Compound interest; day-count conventions; fixed-point money types.

## 11. Tags
`cpp-basics`, `functions`, `math`, `beginner`, `practice`
