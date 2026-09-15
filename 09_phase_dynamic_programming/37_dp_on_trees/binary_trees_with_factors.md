# Binary Trees With Factors

## Problem Statement
[LeetCode 823](https://leetcode.com/problems/binary-trees-with-factors/) — count binary trees with values from arr where parent = left*right; mod 1e9+7.

- **Inputs:** `arr` distinct ints.
- **Output:** count trees mod 10^9+7.
- **Valid answer:** each value can be root of many trees.
- **Edges:** primes only; duplicates none.

## Intuition
Sort; DP[x] = 1 + sum DP[L]*DP[R] for factors.

## Brute Force → Optimal
- **Brute:** build trees.
- **Optimal:** O(N^2) with map.

## Data Structure / Approach Justification
**Chosen:** map value->ways; for each x try factors in set.

## Logic Walkthrough
Leaf always counts as 1.

## Dry Run
[2,4] -> **3**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N)**.

## Trade-offs & Alternatives
Not a geometric tree layout problem — combinatorial DP.

## Common Mistakes / Edge Cases
Forgetting leaf base 1.

## Interview Follow-ups / Variations
Unique BSTs style counting.

## Tags
`tree-dp`, `leetcode-823`, `difficulty:medium`
