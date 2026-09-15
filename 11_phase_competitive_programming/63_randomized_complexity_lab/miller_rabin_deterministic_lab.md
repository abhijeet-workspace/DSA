# Miller–Rabin Deterministic Lab

## 1. Problem Statement
Deterministic Miller–Rabin for 32-bit integers using fixed witness set; compare to naive trial division.

- **Inputs:** integers to test.
- **Output:** prime/composite.
- **Edges:** n<2; even; known SPRP boundaries.
- **Note:** witnesses `{2,7,61}` determine 32-bit primality; do not invent wider claims.

## 2. Intuition
Stronger than Fermat: look for nontrivial square roots of 1 mod n in the factoring of n-1.

## 3. Brute Force → Optimal
- **Trial division.**
- **MR:** few modular exponentiations.

## 4. Data Structure / Approach Justification
**Chosen:** deterministic witnesses for 32-bit.

| Alternative | Note |
|-------------|------|
| Fermat only | Carmichael issues |
| Probabilistic MR | Random witnesses |

## 5. Logic Walkthrough
1. Write n-1 = 2^s · d.
2. For each witness a, compute a^d; square up to s-1 checking -1.
3. Fail → composite.

## 6. Dry Run
97 prime; 91 composite.

## 7. Time & Space Complexity
**O(#witness · log³ n)** bit ops in demo.

## 8. Trade-offs & Alternatives
Production uses `__int128` / big-int carefully.

## 9. Common Mistakes / Edge Cases
Overflow mul; wrong witness set for bit width.

## 10. Interview Follow-ups / Variations
64-bit witness sets; Baillie–PSW.

## 11. Tags
`miller-rabin`, `primality`, `lab`, `difficulty:hard`
