# nCr Mod Prime

## 1. Problem Statement
**Teaching lab** — compute C(n,r) mod p for prime p (n < p) using factorial + modular inverse.

## 2. Intuition
C(n,r)=n!/(r!(n-r)!) ; under prime mod use Fermat inverses.

## 3. Brute Force → Optimal
- **Brute:** multiplicative loop without mod care.
- **Optimal:** precompute fact/invfact.

## 4. Data Structure / Approach Justification
**Chosen:** fact + invfact arrays.

- **Pedagogy:** competitive combinatorics toolkit; Lucas theorem extends when n≥p.

## 5. Logic Walkthrough
Precompute fact[i], invfact[i]; query fact[n]*invfact[r]*invfact[n-r].

## 6. Dry Run
C(5,2) mod 1e9+7 = 10.

## 7. Time & Space Complexity
Precompute **O(n + log mod)**. Query **O(1)**.

## 8. Trade-offs & Alternatives
Lucas when n≥p; CRT for mod=p^k.

## 9. Common Mistakes / Edge Cases
Using non-prime mod with Fermat.

## 10. Interview Follow-ups / Variations
Many queries; Lucas demo.

## 11. Tags
`combinatorics`, `modular`, `teaching-lab`, `difficulty:medium`
