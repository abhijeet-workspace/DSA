# Find Largest n-Digit Prime

## Problem Statement
Find the largest prime with exactly `n` decimal digits.

- **Inputs:** positive integer `n` (digit count).
- **Output:** that prime, or `-1` if invalid / none.
- **Valid answer:** largest `p` with `⌊log10 p⌋+1 = n`.
- **Edges:** `n≤0`; `n=1` → 7; large `n` (trial check gets slow).

## Intuition
Bertrand’s postulate guarantees a prime between `k` and `2k`, so an n-digit range always has primes. Scan from `10^n-1` downward and trial-test each candidate.

## Brute Force → Optimal
- **Brute:** check every n-digit number from the top — O((10^n)·√(10^n)) worst case (but primes are dense).
- **Better:** same scan with wheel / sieve of the range; for teaching, trial from the top is enough for small `n`.

## Data Structure / Approach Justification
**Chosen:** downward scan + `O(√p)` primality.

- **vs segmented sieve of [10^(n-1), 10^n):** faster for larger ranges, more code.
- **vs probabilistic tests (Miller–Rabin):** needed for very large `n`.

## Logic Walkthrough
Compute `upper=10^n-1`, `lower=10^(n-1)`. For `num` from upper down: if prime, return it.

## Dry Run
`n=2`: start 99 (composite) … down to 97 (prime) → return 97.

## Time & Space Complexity
Time **O(g · √U)** where `g` is gap to nearest prime below `U=10^n`. Space **O(1)**. Why: expected gaps are small vs range size (section 4).

## Trade-offs & Alternatives
Fine for demos (`n≤6`). Production/large `n` → segmented sieve or Miller–Rabin.

## Common Mistakes / Edge Cases
Using `pow` floats for bounds; treating 1 as prime; `n=1` lower bound.

## Interview Follow-ups / Variations
Smallest n-digit prime; k-th prime; primes in `[L,R]` with large `R`.

## Tags
`math`, `prime`, `number-theory`, `trial-division`, `difficulty:easy`
