# Matrix Exponentiation

## Problem Statement
Compute the n-th Fibonacci number (mod `1e9+7`) in logarithmic time using matrix power.

- **Inputs:** nonnegative integer `n`.
- **Output:** `F_n` modulo MOD.
- **Valid answer:** F_0=0, F_1=1, F_n=F_{n-1}+F_{n-2}.
- **Edges:** n=0,1; large n needing O(log n); multiply overflow before mod.

## Intuition
Linear recurrence ↔ multiply by a fixed transition matrix. Raising that matrix to `n−1` advances the state in O(log n) multiplies.

## Brute Force → Optimal
- **Brute:** loop add — O(n).
- **Optimal:** binary exponentiation of 2×2 matrix — O(log n) matrix muls.

## Data Structure / Approach Justification
**Chosen:** `vector<vector<ll>>` matrices with modmul and identity init.

- **vs fast doubling formulas:** fewer constants for pure Fib; matrices generalize to order-k.
- **vs Binet:** floating error for large n.

## Logic Walkthrough
`T = [[1,1],[1,0]]`. `T^{n-1} = [[F_n, F_{n-1}],[F_{n-1}, F_{n-2}]]`. Return `T[0][0]`. Power squares and multiplies like integer binary exp.

## Dry Run
`n=10`: compute `T^9` → top-left **55** = F_10.
`n=1`: early return 1; `n=0` → 0.

## Time & Space Complexity
Time **O(D³ log n)** (D=2 → const). Space **O(D²)**. Why: each mul is D³; log bits of exponent (section 4).

## Trade-offs & Alternatives
Same template solves Tribonacci, linear DP skip, geometric series sums. For tiny n, plain loop is clearer.

## Common Mistakes / Edge Cases
Wrong identity matrix; off-by-one exponent (`n` vs `n-1`); `(a*b)%MOD` overflow on 32-bit; forgetting base cases.

## Interview Follow-ups / Variations
k-bonacci; count paths of length k in a graph; sum of F_1..F_n via augmented matrix.

## Tags
`matrix-exponentiation`, `fibonacci`, `binary-exponentiation`, `linear-recurrence`, `difficulty:medium`
