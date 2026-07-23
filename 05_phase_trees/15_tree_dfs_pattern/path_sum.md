# Path Sum

## Problem Statement
[LeetCode 112](https://leetcode.com/problems/path-sum/) — return true if there is a **root-to-leaf** path summing to `targetSum`.

- **Inputs:** `TreeNode* root`, `int targetSum`.
- **Output:** boolean.
- **Valid answer:** path must end at a leaf (node with no children).
- **Edges:** empty tree; single node; negative values; early match on non-leaf.

## Intuition
DFS downward, subtracting `root->val` from the remaining target; at a leaf, check equality.

## Brute Force → Optimal
- **Brute:** enumerate all root-to-leaf paths then sum — O(N) with extra path storage.
- **Optimal:** recurse with remaining sum — O(N) time, O(H) space, no path copy.

## Data Structure / Approach Justification
**Chosen:** recursive DFS with reduced `targetSum`.

- **vs BFS with running sums:** also O(N); recursion is simpler for trees.
- **vs Path Sum II style path vector:** unnecessary when only existence matters.

## Logic Walkthrough
Null → false. Leaf → `targetSum == val`. Else OR of left/right with `targetSum - val`.

## Dry Run
`5-4-11`, target `20`: `20-5=15` → `15-4=11` → leaf `11==11` → true. Target `10`: no leaf match → false.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: visit each node once; recursion depth (section 4).

## Trade-offs & Alternatives
Early exit on first true is fine. Iterative stack of `(node, remain)` mirrors recursion.

## Common Mistakes / Edge Cases
Accepting sum at non-leaf; treating null child as leaf; empty root with target 0.

## Interview Follow-ups / Variations
Path Sum II (113) all paths; Path Sum III (437) any downward path; max path sum (124).

## Tags
`binary-tree`, `dfs`, `path-sum`, `leetcode-112`, `difficulty:easy`
