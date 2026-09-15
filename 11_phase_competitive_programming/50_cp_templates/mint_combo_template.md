# Mint Combo Template

## 1. Problem Statement
Teaching-lab — factorial / inverse factorial table for `nCr` under prime MOD.

## 2. Intuition
`C(n,k)=n!/(k!(n-k)!)` via modular inverses (Fermat).

## 3. Brute Force → Optimal
- **Brute:** compute each C with loops. **Optimal:** O(n) prep, O(1) query.

## 4. Data Structure / Approach Justification
**Chosen:** fact + ifact.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

Combinatorics topic expands identities.

## 5. Logic Walkthrough
Build fact; inv of fact[n]; back-prop ifact; multiply three terms.

## 6. Dry Run
`C(10,3)=120`.

## 7. Time & Space Complexity
Prep **O(n + log MOD)**; query **O(1)**.

## 8. Trade-offs & Alternatives
Lucas for non-prime or huge n; DP Pascal when MOD composite small n.

## 9. Common Mistakes / Edge Cases
Calling C before building enough fact size.

## 10. Interview Follow-ups / Variations
nPr; multinomial.

## 11. Tags
`combinatorics`, `modint`, `nCr`, `template`, `difficulty:medium`
