# Number Theory

## 1. Problem Statement
CP number-theory toolkit: primes via sieve, GCD / extended GCD, modular power & inverse, Euler totient φ, and Chinese Remainder Theorem (CRT).

- **Inputs:** bounds / moduli / remainders depending on routine.
- **Output:** primes list; Bézout coeffs; φ(n); minimal CRT solution.
- **Valid answer:** mathematically correct under stated assumptions (e.g. prime mod for Fermat inverse; pairwise-coprime moduli for CRT).
- **Edges:** n=0/1 for sieve; a=0 in gcd; composite mod breaks Fermat inverse.

## 2. Intuition
Factorization and modular structure reduce hard ops: sieve marks composites; Euclidean algorithm shrinks gcd; binary exp squares for log-time powers; CRT glues congruent systems when moduli cooperate.

## 3. Brute Force → Optimal
- **Brute:** trial division for primes O(N√N); linear scan for φ; naive multiply for pow.
- **Optimal:** Eratosthenes O(N log log N); Euclid O(log); binary exp O(log exp); φ via prime factors O(√N); CRT with extGCD.

## 4. Data Structure / Approach Justification
**Chosen:** `vector<bool>` sieve mark array; recursive Euclid / extGCD; iterative modpow.

**Pedagogy:** this is a multi-tool teaching lab / CP toolkit overview, not a single contest
submission. Focused problems later in this folder drill one technique each (sieve count, Fermat
inverse, totient batch, etc.).

- **vs segmented sieve:** needed only for huge ranges.
- **vs Euler sieve / SPF:** better for factor queries; heavier for one-shot primes.
- **vs inv via extGCD:** works for any coprime mod, not only primes.

## 5. Logic Walkthrough
Sieve: for each prime p, mark multiples from p². extGCD: unwind remainders to Bézout. pow: square base, multiply when bit set. φ: for each prime factor p of n, multiply by (1−1/p). CRT: x = Σ rem_i · (P/n_i) · inv(P/n_i mod n_i).

## 6. Dry Run
CRT: x≡2 (mod 3), x≡3 (mod 5), x≡2 (mod 7); P=105.
- i=0: pp=35, inv(35 mod 3)=inv(2)=2 → +2·2·35
- i=1: pp=21, inv(21 mod 5)=inv(1)=1 → +3·1·21
- i=2: pp=15, inv(15 mod 7)=inv(1)=1 → +2·1·15
- sum mod 105 = 23

## 7. Time & Space Complexity
Sieve **O(N log log N)** time, **O(N)** space. gcd/pow **O(log)**; φ **O(√N)**; CRT **O(K log M)**. Why: each tool matches its algebraic reduction (section 4).

## 8. Trade-offs & Alternatives
Fermat inverse needs prime mod; use extGCD otherwise. Linear sieve builds SPF for many factorizations. CRT assumes pairwise coprime moduli (general CRT needs compatibility checks).

## 9. Common Mistakes / Edge Cases
Overflow in `a*b%mod` without wide multiply; negative remainders after extGCD; forgetting to normalize inverse mod m; CRT with non-coprime moduli.

## 10. Interview Follow-ups / Variations
Modular inverse for all 1..n; discrete log; Miller–Rabin; CRT with non-coprime moduli; Euler's theorem for pow reduction.

## 11. Tags
`number-theory`, `sieve`, `gcd`, `modular-arithmetic`, `crt`, `difficulty:medium`
