# Lucas Theorem Demo

## 1. Problem Statement
**Teaching lab** — compute C(n,r) mod p for prime p using Lucas when n may be ≥ p.

## 2. Intuition
Lucas: C(n,r) ≡ Π C(n_i, r_i) (mod p) on base-p digits.

## 3. Brute Force → Optimal
- **Brute:** huge factorial.
- **Optimal:** Lucas decomposition.

## 4. Data Structure / Approach Justification
**Chosen:** recursive Lucas + small nCr mod p.

- **Pedagogy:** extends ncr_mod_prime to large n.

## 5. Logic Walkthrough
While n or r: multiply C(n%p,r%p); n/=p; r/=p; if r_i>n_i return 0.

## 6. Dry Run
C(1000,200) mod 13 — demo prints a checked small case C(10,3)%5=0.

## 7. Time & Space Complexity
Time **O(p log_p n + p)** depending on small nCr method.

## 8. Trade-offs & Alternatives
Only for prime modulus.

## 9. Common Mistakes / Edge Cases
Digit overflow; r>n mid digits.

## 10. Interview Follow-ups / Variations
Modulo prime powers.

## 11. Tags
`combinatorics`, `lucas`, `teaching-lab`, `difficulty:hard`
