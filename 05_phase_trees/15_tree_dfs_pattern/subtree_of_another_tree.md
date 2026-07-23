# Subtree of Another Tree

## Problem Statement
[LeetCode 572](https://leetcode.com/problems/subtree-of-another-tree/) — return true if `subRoot` is a subtree of `root` (identical structure and node values).

- **Inputs:** `TreeNode* root`, `TreeNode* subRoot`.
- **Output:** boolean.
- **Valid answer:** some node in `root` is the root of a tree identical to `subRoot`.
- **Edges:** null trees; single node; values match but shape differs; partial overlap.

## Intuition
At every node of `root`, run Same Tree against `subRoot`; if not, try left/right children.

## Brute Force → Optimal
- **Brute / standard:** DFS + `isSameTree` — O(N·M) worst.
- **Alternative optimal:** serialize with delimiters + string/KMP find — O(N+M).

## Data Structure / Approach Justification
**Chosen:** nested DFS (`isSubtree` + `isSameTree`) — interview-standard and clear.

- **vs hash/Merkle serialization:** faster average, collision/careful encoding needed.
- **vs value-only match:** wrong; structure must match fully.

## Logic Walkthrough
`isSameTree`: both null → true; one null → false; else values equal and both children same. `isSubtree`: null root → false; same at root or recurse children.

## Dry Run
`root=[3,4,5,1,2]`, `sub=[4,1,2]`: at node `4`, `isSameTree` matches children `1`,`2` → true.

## Time & Space Complexity
Time **O(N·M)** worst. Space **O(H)**. Why: Same Tree up to M work per of N nodes (section 4).

## Trade-offs & Alternatives
Naive is fine for interviews. Serialization preferred when N·M is a constraint worry.

## Common Mistakes / Edge Cases
Matching values without full structure; treating `subRoot` null inconsistently; stopping after first value hit.

## Interview Follow-ups / Variations
Count occurrences of `subRoot`; largest common subtree; tree isomorphism under swaps.

## Tags
`binary-tree`, `dfs`, `same-tree`, `leetcode-572`, `difficulty:easy`
