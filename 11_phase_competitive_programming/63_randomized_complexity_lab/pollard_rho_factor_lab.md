# Pollard Rho Factor Lab (Small)

## 1. Problem Statement
Factor a small composite integer with Pollard's Rho (teaching scale).

- **Inputs:** composite `n` (fit in 64-bit, small factors).
- **Output:** a nontrivial factor.
- **Edges:** prime input (should fail/retry); even n.
- **Note:** lab for small n; not a full big-int factorization suite.

## 2. Intuition
Pseudo-random polynomial walk; gcd of differences catches factors via birthday collision in subgroup.

## 3. Brute Force → Optimal
- **Trial division to √n.**
- **Rho:** expected ~ n^{1/4} for balanced factors.

## 4. Data Structure / Approach Justification
**Chosen:** Brent/Floyd style rho with `f(x)=x²+c mod n`.

| Alternative | Note |
|-------------|------|
| ECM | Harder factors |
| Trial | Fine for tiny n |

## 5. Logic Walkthrough
1. Pick x,y,c.
2. Iterate; compute gcd(|x-y|,n).
3. If 1 continue; if n restart; else factor.

## 6. Dry Run
n=91 → factor 7 or 13.

## 7. Time & Space Complexity
Expected ~ **O(n^{1/4})** ops for semiprimes (rough).

## 8. Trade-offs & Alternatives
Needs MR for primality first in real pipelines.

## 9. Common Mistakes / Edge Cases
Overflow; not handling gcd==n; poor RNG constants.

## 10. Interview Follow-ups / Variations
Full factorization recursion; Brent's variant.

## 11. Tags
`pollard-rho`, `factorization`, `lab`, `difficulty:hard`
