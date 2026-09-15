# Boats to Save People

## Problem Statement
[LeetCode 881](https://leetcode.com/problems/boats-to-save-people/) — each boat carries at most two people and weight ≤ `limit`; minimize boats to rescue everyone.

- **Inputs:** `people[i]` weights, `int limit`.
- **Output:** minimum number of boats.
- **Valid answer:** greedy pairing count.
- **Edges:** all alone (heavy); all pair; single person; `people[i]==limit`.

## Intuition
Heaviest person always boards; pair with lightest if room remains — otherwise alone. Sorting enables two pointers.

## Brute Force → Optimal
- **Brute:** try all pairings — exponential.
- **Optimal:** sort + two pointers — O(N log N).

## Data Structure / Approach Justification
**Chosen:** sorted array, `lo`/`hi` pointers.

- **vs multiset:** same greedy, heavier constants.
- **vs DP knapsack:** overkill; at most two per boat.

## Logic Walkthrough
Sort ascending. While `lo<=hi`: if `people[lo]+people[hi]<=limit`, `++lo`. Always `--hi`, `++boats`.

## Dry Run
`[3,2,2,1]`, limit 3: pair 1+2, then 2 alone, then 3 alone → **3** boats.

## Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra (sort). Why: sort dominates; each person boarded once (section 4).

## Trade-offs & Alternatives
If already sorted, linear scan. Three-per-boat would need different packing.

## Common Mistakes / Edge Cases
Forgetting `lo==hi` still needs a boat; pairing two heavies first; assuming three fit.

## Interview Follow-ups / Variations
Boats of capacity `k`; variable boat limits.

## Tags
`greedy`, `two-pointers`, `sorting`, `leetcode-881`, `difficulty:medium`
