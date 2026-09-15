# Maximum Product of Splitted Binary Tree

## Problem Statement
[LeetCode 1339](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/) — remove one edge; max product of two subtree sums mod 1e9+7.

- **Inputs:** `root`.
- **Output:** max product mod 10^9+7.
- **Valid answer:** max over edges of sum(sub)*(total-sum(sub)).
- **Edges:** two nodes.

## Intuition
Compute total sum; DFS subtree sums; track max product.

## Brute Force → Optimal
- **Brute:** try each edge.
- **Optimal:** O(N).

## Data Structure / Approach Justification
**Chosen:** two-pass or one DFS collecting subtree sums.

## Logic Walkthrough
product = sub * (total-sub).

## Dry Run
Sample -> **102119008** or similar.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Use long long; mod only at return.

## Common Mistakes / Edge Cases
Modding intermediate max wrongly.

## Interview Follow-ups / Variations
Tree sums DP.

## Tags
`tree-dp`, `leetcode-1339`, `difficulty:medium`
