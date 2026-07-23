# Balanced Binary Tree

## Problem Statement
[LeetCode 110](https://leetcode.com/problems/balanced-binary-tree/) — return true if the binary tree is height-balanced (every node’s left/right heights differ by at most 1).

- **Inputs:** `TreeNode* root`.
- **Output:** `bool`.
- **Valid answer:** true iff every subtree is balanced.
- **Edges:** empty tree; single node; left-skewed chain; imbalance only deep in one branch.

## Intuition
Balance is local at every node: compute left/right heights and reject if `|L-R| > 1`. Propagate failure upward so one DFS covers the whole tree.

## Brute Force → Optimal
- **Brute:** for each node, compute left/right heights separately — O(N²) on skewed trees.
- **Optimal:** single postorder DFS returning height or `-1` sentinel on imbalance — O(N).

## Data Structure / Approach Justification
**Chosen:** recursive height with early `-1` abort.

- **vs top-down height calls:** correct but recomputes overlapping subtrees.
- **vs storing heights in a map:** extra memory; recursion already carries height.

## Logic Walkthrough
`height(null)=0`. Recurse left/right; if either returns `-1` or `|L-R|>1`, return `-1`. Else return `1+max(L,R)`. `isBalanced` is `height(root) >= 0`.

## Dry Run
Tree `1→2→3` (left chain):
- leaf `3`: `L=R=0` → height 1
- node `2`: `L=1,R=0` → height 2
- root `1`: `L=2,R=0` → `|2-0|>1` → `-1` → false

## Time & Space Complexity
Time **O(N)** (each node once). Space **O(H)** recursion. Why: one postorder pass with early abort (section 4).

## Trade-offs & Alternatives
Sentinel `-1` packs height + balance into one return; pair/`struct` is clearer but noisier. Iterative postorder avoids deep recursion on skewed trees.

## Common Mistakes / Edge Cases
Checking only the root; forgetting empty → true; off-by-one on height (nodes vs edges).

## Interview Follow-ups / Variations
Return the balance factor; AVL insert rotations; min height / diameter (543).

## Tags
`binary-tree`, `dfs`, `height`, `leetcode-110`, `difficulty:easy`
