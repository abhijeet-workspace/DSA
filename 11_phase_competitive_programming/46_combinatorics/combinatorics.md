# Combinatorics

## Problem Statement
CP combinatorics demos: binomial `nCr` mod prime, Catalan numbers, Stirling numbers of the second kind, and 3-set inclusion-exclusion counts.

- **Inputs:** n, r / n, k / limit and divisors a,b,c.
- **Output:** counts modulo `1e9+7` (where applicable) or integer union size.
- **Valid answer:** matches closed formulas / recurrence definitions.
- **Edges:** r>n → 0; n=0 Catalan/Stirling bases; overflow without mod.

## Intuition
Factorials + modular inverses turn divisions into multiplies. Catalan is a binomial ratio. Stirling2 counts set partitions via recurrence. Inclusion-exclusion expands union by adding singles, subtracting pairs, adding triple.

## Brute Force → Optimal
- **Brute:** compute each nCr with loops O(nr); recursive Catalan/Stirling with overlap.
- **Optimal:** O(MAX) factorial precompute → O(1) nCr; DP Stirling O(nk); closed IE for fixed sets.

## Data Structure / Approach Justification
**Chosen:** global `fact` / `inv_fact` arrays; 2D DP for Stirling; LCM via GCD for IE.

- **vs Pascal triangle:** O(n²) space/time if many mid-size queries without huge MAX.
- **vs Lucas theorem:** needed when n ≥ MOD.
- **vs labeled partitions (Bell via Stirling×k!):** different counting model.

## Logic Walkthrough
Precompute fact[i], then inv_fact from Fermat of fact[MAX-1] downward. nCr = fact[n]·inv_fact[r]·inv_fact[n-r]. Catalan uses fact[2n]·inv_fact[n+1]·inv_fact[n]. Stirling: S[i][j] = j·S[i-1][j] + S[i-1][j-1]. IE: A+B+C−AB−BC−AC+ABC.

## Dry Run
`5C2`: fact[5]=120 with inv_fact[2], inv_fact[3] → **10**.
`S(4,2)`: DP partitions of 4 elements into 2 nonempty subsets → **7**.
`IE(100,3,5,7)`: ⌊100/3⌋+⌊100/5⌋+⌊100/7⌋ − ⌊100/15⌋−⌊100/35⌋−⌊100/21⌋ + ⌊100/105⌋ = 33+20+14−6−2−4+0 = **55**.

## Time & Space Complexity
Precompute **O(MAX)**; nCr **O(1)**; Catalan **O(1)** after pre; Stirling **O(nk)** time/space; IE **O(1)**. Why: inverses amortize divisions (section 4).

## Trade-offs & Alternatives
Large MAX wastes memory if queries are tiny. For n ≥ MOD use Lucas. Stirling can roll DP to O(k) space if only last row needed.

## Common Mistakes / Edge Cases
Missing inv_fact[0]=1; Catalan needing fact[2n] within MAX; LCM overflow before divide; forgetting mod on multiplies.

## Interview Follow-ups / Variations
nPr; Bell numbers; multinomial; generating functions; paths not crossing (Catalan variants).

## Tags
`combinatorics`, `binomial`, `catalan`, `stirling`, `inclusion-exclusion`, `difficulty:medium`
