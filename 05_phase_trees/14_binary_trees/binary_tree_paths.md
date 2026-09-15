# Binary Tree Paths

## 1. Problem Statement
[LeetCode 257](https://leetcode.com/problems/binary-tree-paths/) — return all root-to-leaf paths formatted as `"1->2->5"`.

- **Inputs:** `TreeNode* root`.
- **Output:** `vector<string>`.
- **Valid answer:** every path ends at a leaf; order may vary.
- **Edges:** empty; single node; skewed chain.

## 2. Intuition
DFS while appending the current value; at a leaf, push the built string.

## 3. Brute Force → Optimal
- **Brute:** store vector<path> of nodes then join — extra allocations.
- **Optimal:** grow a string (or path vector + backtrack) — O(N) visits.

## 4. Data Structure / Approach Justification
**Chosen:** DFS with path string by value (immutable per branch).

- **vs path vector + join at leaf:** clearer backtracking; same asymptotics.
- **vs BFS parent map:** more bookkeeping for strings.

## 5. Logic Walkthrough
Append val; if leaf → push; else append `->` and recurse left/right.

## 6. Dry Run
`[1,2,3,null,5]`: paths `1->2->5` and `1->3`.

## 7. Time & Space Complexity
Time **O(N²)** worst (string copy on skewed tree) / typical **O(N·H)**. Space **O(H)** recursion + output. Why: each root-to-leaf materializes a path.

## 8. Trade-offs & Alternatives
Pass `string&` + backtrack (`pop`) to avoid repeated copies when paths are long.

## 9. Common Mistakes / Edge Cases
Including non-leaf partial paths; forgetting `->` only between nodes; empty root.

## 10. Interview Follow-ups / Variations
Path Sum II (113); Sum Root to Leaf Numbers (129).

## 11. Tags
`binary-tree`, `dfs`, `backtracking`, `leetcode-257`, `difficulty:easy`
