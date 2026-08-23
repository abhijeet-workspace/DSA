# Successful Pairs of Spells and Potions

## Problem Statement
[LeetCode 2300](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/) — for each spell, count potions with `spell * potion >= success`.

- **Inputs:** `spells`, `potions`, `success`.
- **Output:** `vector<int>` counts.
- **Valid answer:** per-spell lower bound on sorted potions.
- **Edges:** no successful pair; all succeed; overflow on product.

## Intuition
Sort potions once. For spell s the min potion is `ceil(success/s)`. Binary search that threshold.

## Brute Force → Optimal
- **Brute:** nested loops — O(NM).
- **Optimal:** sort + N binary searches — O((N+M) log M).

## Data Structure / Approach Justification
**Chosen:** lower bound as a counting tool.

- **vs two pointers after sorting both:** also good; BS is the plan pattern
- **vs checking product mid*s:** must use long long

## Logic Walkthrough
`need = (success + s - 1) / s`. Count suffix `m - lower_bound(need)`.

## Dry Run
spells `[5,1,3]`, potions `[1..5]`, success 7 → `[4,0,3]`.

## Time & Space Complexity
Time **O((N+M) log M)**. Space **O(1)** extra besides the answer. Why: one sort of potions plus a log search per spell.

## Trade-offs & Alternatives
Same template as “count elements ≥ x”.

## Common Mistakes / Edge Cases
32-bit multiply overflow; using floor instead of ceil.

## Interview Follow-ups / Variations
Number of subsequences (1498); Koko (ceil division).

## Tags
`binary-search`, `sorting`, `leetcode-2300`, `difficulty:medium`
