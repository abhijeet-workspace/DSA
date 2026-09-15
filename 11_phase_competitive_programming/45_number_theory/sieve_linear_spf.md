# Linear Sieve (SPF Table) — Teaching Lab

## 1. Problem Statement
**Teaching lab (not a contest submission):** build the smallest-prime-factor (SPF) table for all integers in `[0, N]` in O(N), then factorize queries in O(log x).

- **Inputs:** bound `N`, query integers.
- **Output:** SPF array; prime factorization lists.
- **Edges:** 0/1 have no prime factors.

## 2. Intuition
Each composite is marked exactly once by its smallest prime factor. Maintain primes list; for i=2..N, for each prime p≤spf[i] with i*p≤N set spf[i*p]=p.

## 3. Brute Force → Optimal
- **Brute:** trial factor each value.
- **Optimal:** linear sieve O(N) preprocess + O(log x) factor.

## 4. Data Structure / Approach Justification
**Chosen:** `spf[]` + `primes` vector.

**Pedagogy:** teaching lab extending the Eratosthenes overview in `number_theory`. Prefer this when many factorizations are needed.

## 5. Logic Walkthrough
spf[i]=i initially for primes path. When marking j=i*p, if p==spf[i] break after setting (ensures linearity).

## 6. Dry Run
N=10 → spf[8]=2, spf[9]=3. Factor 84 → 2,2,3,7.

## 7. Time & Space Complexity
Preprocess **O(N)** time/space; factor **O(log x)**.

## 8. Trade-offs & Alternatives
Classical sieve is simpler if you only need primes list once.

## 9. Common Mistakes / Edge Cases
Not breaking when p==spf[i]; spf[0/1] misuse.

## 10. Interview Follow-ups / Variations
Segmented linear sieve; multiplicative functions via SPF.

## 11. Tags
`number-theory`, `linear-sieve`, `spf`, `teaching-lab`, `difficulty:medium`
