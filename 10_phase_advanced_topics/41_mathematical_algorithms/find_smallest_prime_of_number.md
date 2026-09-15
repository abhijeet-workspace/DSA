# Find Smallest n-Digit Prime

## 1. Problem Statement
Find the smallest prime with exactly `n` decimal digits.

- **Inputs:** positive integer `n` (digit count).
- **Output:** that prime, or `-1` if invalid / none.
- **Valid answer:** smallest `p` with exactly `n` digits.
- **Edges:** `n≤0`; `n=1` → 2; large `n` slows trial checks.

## 2. Intuition
Start at the smallest n-digit number (`10^(n-1)`, or 2 when `n=1`) and walk upward until a prime appears. Gaps near powers of ten are still small in practice for modest `n`.

## 3. Brute Force → Optimal
- **Brute:** upward trial primality — acceptable for small `n`.
- **Better:** sieve the n-digit window; Miller–Rabin for huge bounds.

## 4. Data Structure / Approach Justification
**Chosen:** upward scan + `O(√p)` isPrime.

- **vs sieve of the digit range:** better when many primes are needed.
- **vs probabilistic tests:** scale to big integers.

## 5. Logic Walkthrough
`lower = 10^(n-1)` (or 2), `upper = 10^n-1`. Return first prime in range.

## 6. Dry Run
`n=3`: start 100 (even) … 101 is prime → return 101.

## 7. Time & Space Complexity
Time **O(g · √L)** for gap `g` above `L=10^(n-1)`. Space **O(1)**. Why: first prime is typically nearby (section 4).

## 8. Trade-offs & Alternatives
Teaching demo for small `n`. Prefer segmented sieve when `n` grows.

## 9. Common Mistakes / Edge Cases
Starting at `10^(n-1)` when `n=1` (includes 1); float `pow` for limits.

## 10. Interview Follow-ups / Variations
Largest n-digit prime; next prime after `x`; prime gaps.

## 11. Tags
`math`, `prime`, `number-theory`, `trial-division`, `difficulty:easy`
