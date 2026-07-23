# Path Sum II

## Problem Statement
[LeetCode 113](https://leetcode.com/problems/path-sum-ii/) — return **all** root-to-leaf paths whose values sum to `targetSum`.

- **Inputs:** `TreeNode* root`, `int targetSum`.
- **Output:** `vector<vector<int>>` of paths.
- **Valid answer:** each path is root→leaf; order among paths unrestricted.
- **Edges:** no paths; single matching leaf; multiple matches; negatives.

## Intuition
DFS with a mutable `path` vector: push on enter, copy into `result` on leaf match, pop on exit (backtrack).

## Brute Force → Optimal
- **Brute:** find all root-to-leaf paths then filter by sum — same asymptotics, more copies.
- **Optimal:** prune by remaining sum while building one shared path — O(N) visits.

## Data Structure / Approach Justification
**Chosen:** backtracking `vector<int> path` + `result` of copies.

- **vs linked path + reverse at leaf:** more awkward in C++.
- **vs Path Sum (112):** existence-only needs no path storage.

## Logic Walkthrough
Push `val`. If leaf and `val==targetSum`, push copy of `path`. Else recurse with `targetSum-val`. Always `pop_back`.

## Dry Run
Classic LC tree, target `22`: paths `[5,4,11,2]` and `[5,8,4,5]` recorded at matching leaves; backtrack restores `path`.

## Time & Space Complexity
Time **O(N²)** worst (copy paths of length O(N) at many leaves) / **O(N)** visits. Space **O(H)** path + output. Why: backtracking + result copies (section 4).

## Trade-offs & Alternatives
Copying full path at each hit is simplest; linked list of nodes can defer materialization.

## Common Mistakes / Edge Cases
Forgetting `pop_back`; recording non-leaf hits; mutating `path` after storing without copy.

## Interview Follow-ups / Variations
Path Sum (112); Path Sum III (437); print only count; max-sum root-to-leaf.

## Tags
`binary-tree`, `dfs`, `backtracking`, `path-sum`, `leetcode-113`, `difficulty:medium`
