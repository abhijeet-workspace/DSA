# Inclusion-Exclusion Demo

## 1. Problem Statement
**Teaching lab** — count integers ≤ N divisible by any of given pairwise moduli via inclusion-exclusion.

## 2. Intuition
Union size = sum singles − sum pairs + sum triples − ...

## 3. Brute Force → Optimal
- **Brute:** mark each integer.
- **Optimal:** IE over 2^m subsets of moduli.

## 4. Data Structure / Approach Justification
**Chosen:** bitmasks over moduli with lcm.

- **Pedagogy:** counting IE; principle reappears in bitmask DP elsewhere.

## 5. Logic Walkthrough
For each non-empty subset, add/sub N/lcm(subset).

## 6. Dry Run
N=10, mods={2,3,5} → 2,3,4,5,6,8,9,10 → 8.

## 7. Time & Space Complexity
Time **O(2^m · m)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Mobius form over multiples.

## 9. Common Mistakes / Edge Cases
LCM overflow; empty subset.

## 10. Interview Follow-ups / Variations
Count coprime to m (Euler via IE).

## 11. Tags
`combinatorics`, `inclusion-exclusion`, `teaching-lab`, `difficulty:medium`
