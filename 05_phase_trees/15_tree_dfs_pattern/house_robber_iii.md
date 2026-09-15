# House Robber III

## 1. Problem Statement
[LeetCode 337](https://leetcode.com/problems/house-robber-iii/) — maximize money robbed from a binary tree of house values without robbing two directly connected nodes.

- **Inputs:** `TreeNode* root` (node values = money).
- **Output:** `int` max amount.
- **Valid answer:** any independent set of nodes with maximum sum.
- **Edges:** empty; single node; negative values not present (non-negative on LC); skewed chain.

## 2. Intuition
At each node choose: rob it (then cannot rob children) vs skip it (take best of each child independently).

## 3. Brute Force → Optimal
- **Brute:** recurse with a `parentRobbed` flag and recompute overlapping subtrees — exponential.
- **Optimal:** postorder returning `{rob, skip}` pair — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** DFS returning pair `(withRoot, withoutRoot)`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Naive recursion without memo | Exponential blow-up |
| DP map<node,state> | Extra memory; pair return is enough |

## 5. Logic Walkthrough
1. Null → `(0,0)`.
2. Recurse left/right.
3. `with = val + L.without + R.without`.
4. `without = max(L.with,L.without) + max(R.with,R.without)`.
5. Answer `max(root.with, root.without)`.

## 6. Dry Run
`[3,2,3,null,3,null,1]`: rob 2+3+1? or 3+3+1=7 → optimal **7** (root 3 + left’s 3 + right’s 1).

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)
- Why: each node computed once bottom-up.

## 8. Trade-offs & Alternatives
Memoized top-down with two states is equivalent. Tree DP generalizes to “max independent set on tree”.

## 9. Common Mistakes / Edge Cases
Forbidding grandchildren incorrectly; adding both children when root robbed; forgetting skip can still take child’s rob.

## 10. Interview Follow-ups / Variations
House Robber I/II (array/circle); binary tree cameras (968).

## 11. Tags
`binary-tree`, `dfs`, `tree-dp`, `leetcode-337`, `difficulty:medium`
