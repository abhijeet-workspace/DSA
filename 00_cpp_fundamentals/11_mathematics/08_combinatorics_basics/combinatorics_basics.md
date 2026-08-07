# Combinatorics Basics

## 1. Problem Statement
Compute core counting quantities:

1. Permutations `P(n,r) = n!/(n-r)!`
2. Combinations `C(n,r) = n!/(r!(n-r)!)` via multiplicative formula (avoids huge factorials)
3. Pascal triangle row / value via recurrence
4. Binomial coefficient under a small modulus (optional demo with prime mod via product)

- **Input:** `n`, `r` demos
- **Output:** P, C, Pascal entries
- **Edges:** `r>n`; `r=0`; overflow for large n without mod

## 2. Intuition
Order matters → permutations. Order ignored → combinations. Pascal: `C(n,r)=C(n-1,r-1)+C(n-1,r)`. Multiplicative C builds product `(n-r+1)..n / 1..r` reducing gcd along the way.

## 3. Brute Force → Optimal
- Full factorials: overflow fast.
- Multiplicative C: O(r) with smaller intermediates.
- Precompute Pascal table O(n²) for many queries.

## 4. Data Structure / Approach Justification
`long long` multiplicative nCr; small DP row for Pascal.

| Alternative | When |
|-------------|------|
| Lucas theorem | Large n, small prime mod — CP |
| Factorial + modinv | Prime mod batch queries |

## 5. Logic Walkthrough
1. nPr: multiply `n*(n-1)*…*(n-r+1)`.
2. nCr: for i=1..r, multiply by `(n-r+i)/i` after dividing gcd.
3. Pascal row: start `[1]`; expand using adjacent sums.

## 6. Dry Run
`P(5,2)=20`, `C(5,2)=10`. Pascal row n=4: 1 4 6 4 1.

## 7. Time & Space Complexity
nPr/nCr: O(r). Pascal row: O(n) time/space for one row; full triangle O(n²).

## 8. Trade-offs & Alternatives
Use modular inverses for contest nCr under prime mod. See CP `46_combinatorics`.

## 9. Common Mistakes / Edge Cases
Computing `n!` first; not reducing fractions; `C(n,r)=C(n,n-r)` forgotten for speed.

## 10. Interview Follow-ups / Variations
Unique paths on grid; catalan via `C(2n,n)/(n+1)`; stars and bars.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `combinatorics`, `nCr`, `pascal`, `intermediate`

## 12. Next Steps
`09_sieve_and_totient_intro`. Advanced: `11_phase_competitive_programming/46_combinatorics`.
