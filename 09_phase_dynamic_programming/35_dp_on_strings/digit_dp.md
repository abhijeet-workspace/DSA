# Digit DP

## Problem Statement
Count integers in `[0, R]` whose **digit sum** equals a given `target` (classic digit-DP template).

- **Inputs:** upper bound `R`, `target` digit sum.
- **Output:** count of valid numbers.
- **Valid answer:** includes 0 when sum matches; leading zeros allowed in digit construction.
- **Edges:** `R=0`; `target=0`; large `R` (up to ~10^18 via string digits).

## Intuition
Build the number digit-by-digit. `tight` means still matching the prefix of `R`. Memoize `(pos, sum, tight)`.

## Brute Force → Optimal
- **Brute:** scan `0…R` — O(R).
- **Optimal:** digit DP — O(D · target · 2 · 10) roughly, `D = digits(R)`.

## Data Structure / Approach Justification
**Chosen:** 3D memo `memo[pos][sum][tight]` + recursive `go`.

- **vs iterative digit DP:** same states; recursion mirrors interview template.
- **Leading-zero flag:** needed when property cares about digit count without pads.

## Logic Walkthrough
Convert `R` to string `S`. At `pos`, try digit `0…up`. New tight = `tight && d==up`. At end, accept iff `sum==target`.

## Dry Run
`R=20`, `target=2`: numbers `2`, `11`, `20` → **3**.

## Time & Space Complexity
Time **O(D · Σ · 10)** with Σ bound on sum. Space **O(D · Σ)**. Why: each state filled once (section 4).

## Trade-offs & Alternatives
Template generalizes to digit DP on ranges `[L,R]` via `f(R)-f(L-1)`. Add flags for “started”, parity, modulo.

## Common Mistakes / Edge Cases
Forgetting tight; not resetting memo between queries; excluding leading-zero paths incorrectly.

## Interview Follow-ups / Variations
Count numbers with digit DP constraints (LC 233, 902, 1012); `[L,R]` range; no leading zeros.

## Tags
`digit-dp`, `memoization`, `counting`, `difficulty:hard`
