# Q7 — Sum of Natural Numbers

## 1. Problem Statement
Given limit N, compute sum of first N natural numbers three ways: loop, recursion, and formula `N*(N+1)/2`.

- **Input:** `limit`
- **Output:** loop line, recursion line, formula line (same mathematical sum for N≥1)
- **Valid answer:** all three agree for reasonable N
- **Edges:** N≤0; recursion depth; formula overflow on large N

## 2. Intuition
Same quantity, three algorithmic styles: iterative accumulation, recursive decomposition, O(1) closed form.

## 3. Brute Force → Optimal
- **Loop / recursion:** O(N) work — brute teaching forms.
- **Formula:** O(1) — optimal for this exact series.
- Recursion loses on stack depth vs loop for large N.

## 4. Data Structure / Approach Justification
Scalars only.

| Approach | Why choose / lose |
|----------|-------------------|
| Loop | Clear, O(1) extra space |
| Recursion | Teaches base/recursive case; O(N) stack |
| Formula | Best asymptotics; needs overflow care / `long long` |

## 5. Logic Walkthrough
1. `sumOfNaturalNumbersByLoop`: `sum += i` for `i=1..limit`.
2. `sumOfNaturalNumbersByRecursion`: `limit + f(limit-1)` with base ≤1.
3. `sumOfNaturalNumbersByFormula`: `(limit * (limit + 1)) / 2`.

## 6. Dry Run
N=5 → 15 via all methods (`1+2+3+4+5`, recursion chain, `5*6/2`).

## 7. Time & Space Complexity
| Method | Time | Space |
|--------|------|-------|
| Loop | O(N) | O(1) |
| Recursion | O(N) | O(N) stack |
| Formula | O(1) | O(1) |

Tied to section 4: formula wins when overflow is handled.

## 8. Trade-offs & Alternatives
Prefer formula in interviews when N fits numeric type; prefer loop when generalizing to arbitrary series; avoid deep recursion for large N.

## 9. Common Mistakes / Edge Cases
Integer overflow in `limit*(limit+1)`; recursion on N=0 originally assumed base `==1` only; off-by-one loops.

## 10. Interview Follow-ups / Variations
Sum of squares formula; modular arithmetic; overflow-safe multiplication.

## 11. Tags
`cpp-basics`, `loops`, `recursion`, `math`, `beginner`, `practice`
