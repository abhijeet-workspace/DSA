# Sum of Distances in Tree

## 1. Problem Statement
[LeetCode 834](https://leetcode.com/problems/sum-of-distances-in-tree/) — for every node `i`, compute sum of distances to all other nodes.

**Pedagogy vs centroid:** classic **rerooting tree DP**, not centroid decomposition. Included because CD also answers global distance aggregates; rerooting is the simpler O(N) tool for this exact problem.

- **Inputs:** undirected tree on `n` nodes `0..n-1`.
- **Output:** `ans[i]` = Σ dist(i,j).
- **Edges:** `n=1`; line; star.

## 2. Intuition
First DFS: `dp[v]` = sum of distances in subtree. Reroot: `ans[child] = ans[v] - sz[child] + (n - sz[child])`.

## 3. Brute Force → Optimal
- **Brute:** BFS from every node — O(N²).
- **Optimal:** rerooting — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** two-DFS rerooting.

| Alternative | Note |
|-------------|------|
| Centroid + depth sums | Works but heavier |
| N BFS | Too slow |

## 5. Logic Walkthrough
`dfs1` subtree sums; set `ans[root]=dp[root]`; `dfs2` reroot formula.

## 6. Dry Run
LC example → `[8,12,6,10,10,10]`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: each edge contributes once per DFS (section 4).

## 8. Trade-offs & Alternatives
Prefer rerooting for this LC; keep CD for constrained path counts.

## 9. Common Mistakes / Edge Cases
Integer overflow; wrong `n-sz` term.

## 10. Interview Follow-ups / Variations
Weighted edges; sum of squared distances.

## 11. Tags
`leetcode-834`, `rerooting`, `tree-dp`, `difficulty:hard`
