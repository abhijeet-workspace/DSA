# Cmath Demo (`<cmath>`, `<cstdlib>`)

## Problem Statement
Apply math builtins to:
1. Euclidean distance between 2D points.
2. Amortized monthly loan payment.
3. Real roots of a quadratic equation.

Also show `abs`, `ceil`/`floor`/`round`, `fmod`, `min`/`max`.

**Inputs:** coordinates; principal/APR/months; coefficients `a,b,c`.  
**Edges:** `a == 0` (not quadratic), negative discriminant, `months == 0` / zero rate edge cases (demo assumes valid loan params).

## Intuition
Geometry, finance, and algebra reuse the same floating-point primitives (`hypot`, `pow`, `sqrt`) rather than reinventing formulas.

## Brute Force → Optimal
- Distance: manual `sqrt(dx*dx+dy*dy)` risks overflow; **`hypot`** is the safer library form.
- Loan: closed-form amortization is already optimal vs simulating month-by-month (O(months)).
- Quadratic: discriminant method is O(1) vs numeric root-finding.

## Data Structure / Approach Justification (REQUIRED)
Plain `double` scalars — no container needed; access pattern is pure arithmetic.
- **vs fixed-point/`int`:** money demos often use decimal libraries in production; `double` is fine for teaching formulas.
- **vs `long double`:** extra precision rarely needed here; stick to `double` for portability demos.

## Logic Walkthrough
- `calculateDistance` → `hypot(dx, dy)`.
- `calculateMonthlyPayment` → monthly rate, then `P * r(1+r)^n / ((1+r)^n - 1)` via `pow`.
- `solveQuadratic` → discriminant; print imaginary or two roots with `sqrt`.

## Dry Run
`(0,0)-(3,4)` → 5.  
`$100k`, 5% APR, 360 months → ~$536.82.  
`x^2 - 5x + 6 = 0` → roots 3 and 2.

## Time & Space Complexity
**O(1)** time/space per call (`pow` is effectively constant for scalar doubles). Why: no loops over N (section 4).

## Trade-offs & Alternatives
Month-by-month amortization for irregular payments; `std::complex` for imaginary roots; `std::numbers` (C++20) for constants.

## Common Mistakes / Edge Cases
Integer division when computing rates; forgetting `/100` for percent APR; `pow` for large exponents (prefer `exp`/`log` forms when needed).

## Interview Follow-ups / Variations
3D distance; compound vs simple interest; numerically stable quadratic formula when `b^2 ≈ 4ac`.

## Tags
`cmath`, `math`, `finance`, `beginner`
