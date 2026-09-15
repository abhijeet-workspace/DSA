# Unique Binary Search Trees

## Problem Statement
[LeetCode 96](https://leetcode.com/problems/unique-binary-search-trees/) — number of structurally unique BSTs with values 1..n (Catalan).

- **Inputs:** `n`.
- **Output:** count.
- **Valid answer:** Catalan number C_n.
- **Edges:** n=1; n=3 -> 5.

## Intuition
dp[i] = sum dp[j]*dp[i-1-j] for root splits.

## Brute Force → Optimal
- **Brute:** generate trees.
- **Optimal:** O(N^2) Catalan DP.

## Data Structure / Approach Justification
**Chosen:** 1D catalan DP.

## Logic Walkthrough
dp[0]=1; build up to n.

## Dry Run
n=3 -> **5**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N)**.

## Trade-offs & Alternatives
Closed form binomial also works.

## Common Mistakes / Edge Cases
Off-by-one on empty tree.

## Interview Follow-ups / Variations
Unique BST II (95).

## Tags
`tree-dp`, `catalan`, `leetcode-96`, `difficulty:medium`
