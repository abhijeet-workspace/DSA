# Distribute Coins in Binary Tree

## 1. Problem Statement
[LeetCode 979](https://leetcode.com/problems/distribute-coins-in-binary-tree/) — each node has `node.val` coins; move coins across edges so every node has exactly 1. Return minimum moves.

- **Inputs:** `TreeNode* root` with `sum(vals) == n`.
- **Output:** `int` moves.
- **Valid answer:** each edge traversal of one coin counts as one move.
- **Edges:** already balanced; all coins in one leaf; skewed.

## 2. Intuition
Postorder excess: subtree returns `coins - nodes` to parent; absolute excess flowing across the edge equals moves on that edge.

## 3. Brute Force → Optimal
- **Brute:** simulate coin shipping — messy.
- **Optimal:** one DFS accumulating `|excess|` — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** DFS returning excess coins in subtree.

| Alternative | Why it loses here |
|-------------|-------------------|
| Global BFS shipping | More complex state |
| Explicit flow network | Overkill |

## 5. Logic Walkthrough
1. `dfs(null)=0`.
2. `left=dfs(L)`, `right=dfs(R)`.
3. Add `|left|+|right|` to answer.
4. Return `node.val + left + right - 1` (excess after keeping one).

## 6. Dry Run
`[3,0,0]`: left excess −1, right −1; moves 1+1=2; root returns 0.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)
- Why: each edge contributes once via child excess.

## 8. Trade-offs & Alternatives
Thinking “balance subtree then parent” is the same excess idea.

## 9. Common Mistakes / Edge Cases
Forgetting `-1` for the node itself; using sum of excess without absolute value.

## 10. Interview Follow-ups / Variations
Binary tree cameras; minimum cost to make paths equal.

## 11. Tags
`binary-tree`, `dfs`, `greedy`, `leetcode-979`, `difficulty:medium`
