# Matchsticks to Square

## Problem Statement
[LeetCode 473](https://leetcode.com/problems/matchsticks-to-square/) — can matchsticks form a square (4 equal sides)?

- **Inputs:** `matchsticks`.
- **Output:** bool.
- **Valid answer:** partition into 4 equal sum subsets.
- **Edges:** sum%4!=0; stick > side.

## Intuition
Same as partition to k=4; DFS or bitmask DP.

## Brute Force → Optimal
- **Brute:** assignments.
- **Optimal:** DFS prune / bitmask O(N*2^N).

## Data Structure / Approach Justification
**Chosen:** sort desc + DFS fill 4 sides.

## Logic Walkthrough
Target = sum/4; place each stick.

## Dry Run
[1,1,2,2,2] -> **true**.

## Time & Space Complexity
Time exponential prune / **O(N*2^N)**. Space **O(N)**.

## Trade-offs & Alternatives
Special case of 698.

## Common Mistakes / Edge Cases
Not sorting; sum not divisible by 4.

## Interview Follow-ups / Variations
Partition to K Equal Sum Subsets (698).

## Tags
`bitmask-dp`, `backtracking`, `leetcode-473`, `difficulty:medium`
