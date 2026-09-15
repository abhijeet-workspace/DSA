# Path Sum II

## 1. Problem Statement
[LeetCode 113](https://leetcode.com/problems/path-sum-ii/) — return **all** root-to-leaf paths whose values sum to `targetSum`.

- **Inputs:** `TreeNode* root`, `int targetSum`.
- **Output:** `vector<vector<int>>` of paths.
- **Valid answer:** each path is root→leaf; order among paths unrestricted.
- **Edges:** no paths; single matching leaf; multiple matches; negatives.

## 2. Intuition
DFS with a mutable `path` vector: push on enter, copy into `result` on leaf match, pop on exit (backtrack).

## 3. Brute Force → Optimal
- **Brute:** find all root-to-leaf paths then filter by sum — same asymptotics, more copies.
- **Optimal:** prune by remaining sum while building one shared path — O(N) visits.

## 4. Data Structure / Approach Justification
**Chosen:** backtracking `vector<int> path` + `result` of copies.

- **vs linked path + reverse at leaf:** more awkward in C++.
- **vs Path Sum (112):** existence-only needs no path storage.

## 5. Logic Walkthrough
Push `val`. If leaf and `val==targetSum`, push copy of `path`. Else recurse with `targetSum-val`. Always `pop_back`.

## 6. Dry Run
Classic LC tree, target `22`: paths `[5,4,11,2]` and `[5,8,4,5]` recorded at matching leaves; backtrack restores `path`.

## 7. Time & Space Complexity
Time **O(N²)** worst (copy paths of length O(N) at many leaves) / **O(N)** visits. Space **O(H)** path + output. Why: backtracking + result copies (section 4).

## 8. Trade-offs & Alternatives
Copying full path at each hit is simplest; linked list of nodes can defer materialization.

## 9. Common Mistakes / Edge Cases
Forgetting `pop_back`; recording non-leaf hits; mutating `path` after storing without copy.

## 10. Interview Follow-ups / Variations
Path Sum (112); Path Sum III (437); print only count; max-sum root-to-leaf.

## 11. Tags
`binary-tree`, `dfs`, `backtracking`, `path-sum`, `leetcode-113`, `difficulty:medium`
