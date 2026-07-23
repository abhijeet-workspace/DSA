# Euler's Totient

## Problem Statement
Compute Euler’s totient `φ(n)`: count of integers in `[1, n]` coprime to `n`.

- **Inputs:** positive integer `n`.
- **Output:** `φ(n)`.
- **Valid answer:** exact count.
- **Edges:** `n=1` → 1; prime `p` → `p-1`; prime powers `p^k`.

## Intuition
`φ(n) = n ∏ (1 - 1/p)` over distinct prime factors. Trial-factorize up to `√n`, strip each prime, apply `result -= result/p`.

## Brute Force → Optimal
- **Brute:** for each `k` in `1..n`, test `gcd(k,n)==1` — O(n log n).
- **Optimal:** factorization formula — O(√n) per query; sieve all `φ[1..N]` in O(N log log N).

## Data Structure / Approach Justification
**Chosen:** in-place factorization + product formula (O(1) extra space).

- **vs sieve:** better for single queries; sieve wins for many `φ` values.
- **vs gcd loop:** too slow for large `n`.

## Logic Walkthrough
`result = n`. For each prime `p | n`, strip all powers of `p`, then `result -= result/p`. If leftover `n > 1`, treat as a prime factor.

## Dry Run
`n=12 = 2²·3`: start 12 → hit 2 → strip → `result=12-6=6` → hit 3 → `result=6-2=4`.

## Time & Space Complexity
Time **O(√n)**. Space **O(1)**. Why: trial primes only up to sqrt (section 4).

## Trade-offs & Alternatives
Batch queries prefer linear sieve of totients. Multiplicative property enables CRT-style builds.

## Common Mistakes / Edge Cases
Dividing out `p` only once (must strip all powers); treating `1` incorrectly.

## Interview Follow-ups / Variations
Prove `Σ_{d|n} φ(d) = n`. Euler’s theorem `a^φ(n) ≡ 1 (mod n)` when `gcd(a,n)=1`.

## Tags
`math`, `number-theory`, `euler-totient`, `factorization`, `difficulty:easy`
