# Maximum Length of Pair Chain

## Problem Statement
[LeetCode 646](https://leetcode.com/problems/maximum-length-of-pair-chain/) — longest chain of pairs (a,b)->(c,d) with b<c.

- **Inputs:** `pairs`.
- **Output:** max chain length.
- **Valid answer:** LIS on pairs by end / greedy by end.
- **Edges:** overlapping; single pair.

## Intuition
Sort by second element; greedy take next compatible.

## Brute Force → Optimal
- **Brute:** subsets.
- **Optimal:** O(N log N) greedy or O(N^2) DP.

## Data Structure / Approach Justification
**Chosen:** sort by end; greedy count.

## Logic Walkthrough
Sort by right; iterate, take if left > prev_end.

## Dry Run
[[1,2],[2,3],[3,4]] -> **2**.

## Time & Space Complexity
Time **O(N log N)**. Space **O(1)**. Why: sort + scan (section 4).

## Trade-offs & Alternatives
Same as activity selection.

## Common Mistakes / Edge Cases
Sorting by start incorrectly.

## Interview Follow-ups / Variations
Russian Doll Envelopes (354).

## Tags
`lis`, `greedy`, `leetcode-646`, `difficulty:medium`
