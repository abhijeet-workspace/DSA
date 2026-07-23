# Gas Station

## Problem Statement
[LeetCode 134](https://leetcode.com/problems/gas-station/) — find a starting station index to complete a circular circuit, or `-1`.

- **Inputs:** `gas[i]`, `cost[i]` for station `i`.
- **Output:** unique valid start index, or `-1` if impossible.
- **Valid answer:** problem guarantees uniqueness when possible.
- **Edges:** `n=1`; total gas exactly equal cost; all negative net.

## Intuition
If `sum(gas) < sum(cost)`, impossible. Otherwise a unique start exists: whenever the running tank goes negative, the next station is the new candidate start.

## Brute Force → Optimal
- **Brute:** try every start, simulate circuit — O(N²).
- **Optimal:** one pass tracking `total`, `tank`, `start` — O(N).

## Data Structure / Approach Justification
**Chosen:** single scan with tank reset — no extra structures.

- **vs prefix sums + binary search:** more code, same asymptotic.
- **vs two pointers:** similar idea; tank reset is clearest.

## Logic Walkthrough
Accumulate `d = gas[i]-cost[i]` into `total` and `tank`. If `tank < 0`, set `start = i+1`, `tank = 0`. Return `start` iff `total >= 0`.

## Dry Run
`gas=[1,2,3,4,5]`, `cost=[3,4,5,1,2]`: tank fails early; `start` lands at **3**; `total >= 0` → return 3.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one circuit fact + greedy reset (section 4).

## Trade-offs & Alternatives
Brute simulation is fine for tiny N. Proof of uniqueness is the interview depth.

## Common Mistakes / Edge Cases
Forgetting the total-gas check; resetting `start` without clearing `tank`; off-by-one when `tank` fails at last index.

## Interview Follow-ups / Variations
Return the path of tank levels? Multiple valid starts if uniqueness dropped?

## Tags
`greedy`, `array`, `circular`, `difficulty:medium`
