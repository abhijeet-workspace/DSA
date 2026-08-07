# Power & Roots

## 1. Problem Statement
Implement power and integer-root building blocks:

1. Naive power (loop multiply)
2. Binary exponentiation (iterative)
3. Integer square root via binary search
4. Check perfect square / power of `k`

- **Input:** base, exponent, targets in `main`
- **Output:** powers, floor sqrt, bools
- **Edges:** exp=0; base=0; negative bases (define for integers); overflow

## 2. Intuition
`a^n = (a^(n/2))²` with an extra multiply when `n` is odd. Binary search finds largest `m` with `m*m ≤ n` for floor sqrt.

## 3. Brute Force → Optimal
- Naive multiply: O(n)
- Binary exp: O(log n) multiplications
- Sqrt: linear scan O(√n) vs binary search O(log n)

## 4. Data Structure / Approach Justification
Iterative binary exp (no recursion stack). `long long` for products.

| Alternative | Notes |
|-------------|-------|
| `std::pow` | Floating; precision risk for integers |
| Newton's method | Fast sqrt; more code |

## 5. Logic Walkthrough
1. Binary exp: while exp>0, if odd multiply ans by base; square base; exp>>=1.
2. Sqrt search `lo..hi` mid; shrink by comparing `mid*mid` to `n`.

## 6. Dry Run
`2^10`: ans builds to 1024. `isqrt(10)=3`. `isPerfectSquare(16)` true. `isPowerOfK(81,3)` true.

## 7. Time & Space Complexity
- Binary exp: O(log exp) time, O(1) space
- Integer sqrt: O(log n) time, O(1) space

## 8. Trade-offs & Alternatives
Modular power needed when answers wrap — see `06_modular_arithmetic` and advanced `binary_exponentiation`.

## 9. Common Mistakes / Edge Cases
`0^0` convention; signed overflow in `mid*mid`; using `double` sqrt then casting without checking.

## 10. Interview Follow-ups / Variations
Pow(x,n) with negative exponents (floats); super-pow; modular matrix exponentiation.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `binary-exponentiation`, `sqrt`, `intermediate`

## 12. Next Steps
`06_modular_arithmetic`. Production modular pow: `41_mathematical_algorithms/binary_exponentiation`.
