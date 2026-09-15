# Path Sum III

## 1. Problem Statement
[LeetCode 437](https://leetcode.com/problems/path-sum-iii/) — count the number of downward paths (parent → child links only) whose node values sum to `targetSum`.

- **Inputs:** `TreeNode* root`, `int targetSum`.
- **Output:** `int` count.
- **Valid answer:** paths need not start at root or end at leaf; must go downward only.
- **Edges:** empty; negatives; zeros; multiple overlapping paths.

## 2. Intuition
Prefix sums along the root-to-current path: if `curSum - target` was seen, a valid suffix ends here.

## 3. Brute Force → Optimal
- **Brute:** from every node DFS all downward paths — O(N²).
- **Optimal:** DFS + hashmap of prefix frequencies — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** prefix-sum frequency map with backtracking.

| Alternative | Why it loses here |
|-------------|-------------------|
| Restart DFS from every node | O(N²) |
| Store all paths explicitly | Extra memory, same asymptotics at best |

## 5. Logic Walkthrough
1. Maintain `cur` prefix and `freq[prefix]`.
2. At node: `cur += val`; add `freq[cur - target]`; `++freq[cur]`.
3. Recurse children; then `--freq[cur]` (backtrack).

## 6. Dry Run
Tree `10→5→3`, target `8`: path `5→3` gives one; other branches may add more. Prefix map finds each ending node in O(1).

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H) for map along one path (+ recursion)
- Why: each node visited once; map size ≤ depth.

## 8. Trade-offs & Alternatives
Two-DFS (start-anywhere) is simpler but slower. Watch overflow with large sums (`long long`).

## 9. Common Mistakes / Edge Cases
Forgetting backtrack; requiring leaf ends; missing `freq[0]=1` for paths from root.

## 10. Interview Follow-ups / Variations
Path Sum I/II; subarray sum equals k (560) — same prefix idea on arrays.

## 11. Tags
`binary-tree`, `dfs`, `prefix-sum`, `leetcode-437`, `difficulty:medium`
