# Sieve & Totient Intro

## 1. Problem Statement
Bridge from fundamentals to advanced number theory:

1. Sieve of Eratosthenes — all primes ≤ `N`
2. Count primes ≤ `N`
3. Euler’s totient φ(n) via prime factorization
4. Totient sieve — φ(1..N) in O(N log log N)

- **Input:** bound `N`, sample `n` for φ
- **Output:** prime list / counts / φ values
- **Edges:** `N<2`; `φ(1)=1`; marking from `p*p`

## 2. Intuition
Composites are multiples of primes ≤ √N. Marking multiples leaves primes. φ(n) counts `k` in `1..n-1` coprime to `n`; multiplicativity: for prime power `p^k`, φ=`p^k - p^(k-1)`.

## 3. Brute Force → Optimal
- Trial each k ≤ N → O(N√N).
- Classical sieve → O(N log log N).
- Single φ via factors O(√n); many φ → linear/totient sieve.

## 4. Data Structure / Approach Justification
`vector<bool>` or `vector<char>` mark array; optional SPF for factorization.

| Next in repo | Path |
|--------------|------|
| Segmented sieve / SPF depth | `41_mathematical_algorithms` |
| CRT, Fermat inverse pack | `45_number_theory` |

## 5. Logic Walkthrough
1. Init mark true; for `p=2..√N`, if prime mark `p², p²+p, …`.
2. φ(n): for each prime factor p, `n *= (1 - 1/p)` i.e. `result -= result/p`.
3. Totient sieve: init `phi[i]=i`; for each prime p, for multiples `j`, `phi[j]-=phi[j]/p`.

## 6. Dry Run
Primes ≤ 10: 2,3,5,7. `φ(9)=6`. `φ(1..6)`: 1,1,2,2,4,2.

## 7. Time & Space Complexity
Sieve / totient sieve: O(N log log N) time, O(N) space. Single φ: O(√n).

## 8. Trade-offs & Alternatives
Linear sieve builds primes + SPF in O(N). Use when factorizing many numbers.

## 9. Common Mistakes / Edge Cases
Starting marks at `2p` not `p²`; `φ(1)`; 32-bit overflow for large N arrays.

## 10. Interview Follow-ups / Variations
Count numbers ≤ N coprime to N; sum of φ(d) over divisors = n; Euler’s theorem for modpow reduction.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `sieve`, `totient`, `advanced-fundamentals`

## 12. Next Steps
Continue in `10_phase_advanced_topics/41_mathematical_algorithms` and `11_phase_competitive_programming/45_number_theory` / `46_combinatorics` / `48_advanced_math`.
