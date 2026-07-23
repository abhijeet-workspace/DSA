# Sieve of Eratosthenes

## Problem Statement
List all primes ≤ `N`, and primes in a range `[lo, hi]` via a segmented sieve.

- **Inputs:** upper bound `N`, or range endpoints `lo`, `hi`.
- **Output:** boolean prime table / vector of primes in range.
- **Valid answer:** exact primes in the requested set.
- **Edges:** `N<2`; `lo=0/1`; empty prime ranges.

## Intuition
Every composite has a prime factor ≤ √n. Mark multiples of each prime `p` starting at `p²`. Segmented: sieve √hi first, then mark the window `[lo,hi]`.

## Brute Force → Optimal
- **Brute:** trial-divide each `k≤N` — O(N√N).
- **Optimal:** classical sieve O(N log log N); segmented for large `hi` with small `hi-lo`.

## Data Structure / Approach Justification
**Chosen:** `vector<bool>` mark array (+ small primes for segment).

- **vs linear sieve (SPF):** O(N), builds smallest prime factor table.
- **vs Miller–Rabin:** single large queries, not dense lists.

## Logic Walkthrough
Init all true except 0/1. For each prime `p` with `p*p≤N`, mark `p*p, p*p+p, …`. Segmented: align first multiple ≥ max(`p*p`, ceil(lo/p)*p).

## Dry Run
`N=10`: mark 4,6,8,10 by 2; 9 by 3 → primes 2,3,5,7.

## Time & Space Complexity
Classical: time **O(N log log N)**, space **O(N)**. Segmented: time **O((R-L+1) log log R + √R)**, space **O(R-L + √R)**. Why: each composite marked by its primes (section 4).

## Trade-offs & Alternatives
Dense primes → classical. Huge `R` with small window → segmented. Single huge `n` → probabilistic test.

## Common Mistakes / Edge Cases
Starting marks at `2p` instead of `p²`; treating 1 as prime; off-by-one in segment indexing.

## Interview Follow-ups / Variations
Count primes in `[L,R]` with `R≤1e12`, `R-L≤1e6`; SPF / factorization sieve.

## Tags
`math`, `sieve`, `prime`, `segmented-sieve`, `number-theory`, `difficulty:medium`
