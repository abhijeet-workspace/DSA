# Conditionals

## 1. Problem Statement
Demonstrate C++ branching: if/else ladders, nested if, `switch` with intentional fall-through, the ternary operator, and `&&` short-circuit safety.

- **Input:** none (hardcoded demo calls in `main`)
- **Output:** grade lines, voting eligibility, days-in-month, parity/divisibility
- **Valid answer:** each helper prints the branch taken for its sample inputs
- **Edges:** invalid month → `default`; `divisor == 0` must not evaluate `num % divisor`

## 2. Intuition
Conditionals choose which statements run. Prefer flat ladders for mutually exclusive ranges; nest when a second predicate only matters after the first; use `switch` for discrete integral labels; use short-circuit to guard unsafe operations.

## 3. Brute Force → Optimal
- **Naive:** deep nested ifs for everything; forget `break` in `switch`; compute `n % 0`.
- **This approach:** one helper per pattern, intentional fall-through for month groups, guard before modulo.

## 4. Data Structure / Approach Justification
No containers — control-flow primitives and a `std::string parity`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Lookup table `days[13]` | Cleaner for months in production; less teaching of `switch` |
| Polymorphism / strategy objects | Overkill for scalar demos |

## 5. Logic Walkthrough
1. `demonstrateIfElse(score)` walks thresholds 90/80/70/50 else F.
2. `demonstrateNestedIf(age, isCitizen)` checks age, then citizenship.
3. `demonstrateSwitchCase(month)` groups months via fall-through, `break` ends each group.
4. `demonstrateTernaryAndShortCircuit` sets `parity`, then `isDivisible` only if `divisor != 0`.

## 6. Dry Run
| Call | Result |
|------|--------|
| `demonstrateIfElse(85)` | Grade B |
| `demonstrateNestedIf(20, true)` | Eligible |
| `demonstrateSwitchCase(2)` | 28 or 29 days |
| `demonstrateTernaryAndShortCircuit(10, 0)` | No (or invalid divisor) — `%` skipped |

## 7. Time & Space Complexity
- **Time:** O(1) per call (fixed comparisons)
- **Space:** O(1)
- Why: no loops over input size

## 8. Trade-offs & Alternatives
- Prefer tables/maps when many discrete labels grow.
- Prefer early returns over deep nesting in real functions.
- Ternary is for expressions; keep statements in `if` for clarity.

## 9. Common Mistakes / Edge Cases
- Missing `break` causing accidental fall-through
- Using `=` instead of `==` in conditions
- Dividing/modding by zero
- Floating comparisons with `==`
- `switch` on non-integral types (pre-C++ limited)

## 10. Interview Follow-ups / Variations
- Rewrite grading with a policy table
- Leap-year exact February day count
- Difference between `&`/`|` and `&&`/`||`

## 11. Tags
`cpp-basics`, `conditionals`, `switch`, `short-circuit`, `beginner`
