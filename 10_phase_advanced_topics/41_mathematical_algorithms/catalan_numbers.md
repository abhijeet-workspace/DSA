# Catalan Numbers

## Problem Statement
Compute the n-th Catalan number `C(n) = C(2n, n) / (n+1)` modulo `10^9+7`. Related: [LeetCode 96 Unique BSTs](https://leetcode.com/problems/unique-binary-search-trees/).

- **Inputs:** non-negative integer `n`.
- **Output:** `C(n) mod MOD`.
- **Valid answer:** exact Catalan sequence under prime modulus.
- **Edges:** `n=0` → 1; large `n` needing factorial tables; division must be modular inverse.

## Intuition
Catalan counts BSTs, Dyck words, polygon triangulations. Use binomial identity with modular inverse of `(n+1)` instead of integer division.

## Brute Force → Optimal
- **Brute:** DP `C(i) = Σ C(j)*C(i-1-j)` — O(N²).
- **Optimal:** factorials + Fermat inverses → `C(2n,n)*inv(n+1)` in O(N + log MOD).

## Data Structure / Approach Justification
**Chosen:** `fact` / `invFact` arrays + binary expo inverse.

- **vs DP recurrence:** O(N) prep vs O(N²); needs prime MOD.
- **vs generating functions:** overkill for interviews.

## Logic Walkthrough
Build `fact[0..2n]`. Set `invFact[2n] = fact[2n]^(MOD-2)`, backfill. `binom = fact[2n]*invFact[n]^2`, return `binom * inv(n+1)`.

## Dry Run
`C(0..4)`: 1, 1, 2, 5, 14. For `n=3`: `C(6,3)=20`, `20*inv(4)=5`.

## Time & Space Complexity
Time **O(N + log MOD)** per call (local tables). Space **O(N)**. Why: one factorial pass + Fermat (section 4).

## Trade-offs & Alternatives
Requires prime MOD for Fermat. Precompute once for many queries. Full nCr toolkit: CP topic 41.

## Common Mistakes / Edge Cases
Integer-dividing by `n+1` instead of modular inverse; off-by-one on fact size `2n`.

## Interview Follow-ups / Variations
Count unique BSTs; balanced parentheses; number of triangulations; DP vs closed form.

## Tags
`math`, `catalan`, `combinatorics`, `modular-inverse`, `difficulty:medium`
