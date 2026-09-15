# All Possible Full Binary Trees

## Problem Statement
[LeetCode 894](https://leetcode.com/problems/all-possible-full-binary-trees/) — all structurally unique full binary trees with n nodes (node.val=0).

- **Inputs:** `n`.
- **Output:** list of roots.
- **Valid answer:** full trees (0 or 2 children).
- **Edges:** even n -> empty; n=1 -> single.

## Intuition
Memo: for odd n, split left/right odd sizes summing to n-1.

## Brute Force → Optimal
- **Brute:** all shapes.
- **Optimal:** catalan-like memo of trees.

## Data Structure / Approach Justification
**Chosen:** map n -> vector<TreeNode*>.

## Logic Walkthrough
For L=1,3,..n-2: combine left trees x right trees.

## Dry Run
n=7 -> 5 trees.

## Time & Space Complexity
Time Catalan-ish. Space stores trees.

## Trade-offs & Alternatives
n even impossible for full binary.

## Common Mistakes / Edge Cases
Leaking memory in OJ-style ok; local demos leak intentionally small.

## Interview Follow-ups / Variations
Unique BSTs counting.

## Tags
`tree-dp`, `leetcode-894`, `difficulty:medium`
