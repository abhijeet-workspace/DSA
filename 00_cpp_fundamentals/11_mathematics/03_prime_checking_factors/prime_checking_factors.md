# Prime Checking & Factorization

## 1. Problem Statement
Core prime problems before sieves:

1. Primality test in O(√n)
2. Smallest prime factor of `n`
3. Full prime factorization (trial)
4. Count of distinct prime factors

- **Input:** demo integers
- **Output:** bool / factor list / counts
- **Edges:** `n≤1` not prime; `n=2`; perfect squares; large composites

## 2. Intuition
A composite `n` has a factor ≤ √n. Check 2, then odd candidates. Factorization repeatedly divides out the smallest prime factor.

## 3. Brute Force → Optimal
- Trial all `2..n-1` → O(n).
- Trial to √n → O(√n) — standard single-query check.
- Many queries → sieve / SPF table (section 09 / advanced phase).

## 4. Data Structure / Approach Justification
Plain loops + `vector` of prime factors.

| Alternative | Why later |
|-------------|-----------|
| Miller–Rabin | Probabilistic; large `n` |
| Pollard Rho | Hard composites; CP advanced |

## 5. Logic Walkthrough
1. `isPrime`: reject ≤1; skip evens after 2; loop `i*i≤n`.
2. Factor: strip 2s; for odd `p`, while divisible push `p`; leftover >1 is prime.

## 6. Dry Run
`isPrime(17)` true; `isPrime(15)` false. Factors of 60: 2,2,3,5. Distinct: 3.

## 7. Time & Space Complexity
- Primality: O(√n) time, O(1) space
- Factorization: O(√n) time, O(ω) factors space

## 8. Trade-offs & Alternatives
Wheel factorization (skip multiples of 2,3) shaves constants. For dense queries use Eratosthenes.

## 9. Common Mistakes / Edge Cases
Calling 1 prime; overflow in `i*i`; not handling remaining cofactor after the loop.

## 10. Interview Follow-ups / Variations
Largest prime factor; count primes ≤ n; Goldbach verification for even n.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `primes`, `factorization`, `beginner-intermediate`

## 12. Next Steps
`04_digit_problems`. Sieve variants: `09_sieve_and_totient_intro` and `41_mathematical_algorithms/sieve_of_eratosthenes`.
