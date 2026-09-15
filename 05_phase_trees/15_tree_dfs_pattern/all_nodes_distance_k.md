# All Nodes Distance K in Binary Tree

## 1. Problem Statement
[LeetCode 863](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) — return all node values at distance `k` from a target node.

- **Inputs:** `TreeNode* root`, `TreeNode* target`, `int k`.
- **Output:** `vector<int>` (any order).
- **Valid answer:** graph distance via parent/child edges equals `k`.
- **Edges:** `k=0`; target root; target leaf; disconnected distance > depth.

## 2. Intuition
Treat the tree as an undirected graph: build parent links (or adjacency), then BFS from target for exactly `k` steps.

## 3. Brute Force → Optimal
- **Brute:** for every node compute distance to target via LCA — O(N²).
- **Optimal:** parent map + BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** DFS mark parents, then BFS from target.

| Alternative | Why it loses here |
|-------------|-------------------|
| Pure tree recursion only downward | Misses parent direction |
| Convert to adjacency list | Fine; parent map is lighter |

## 5. Logic Walkthrough
1. DFS to fill `parent[child]=node`.
2. BFS from target with visited set; at depth `k` collect values.

## 6. Dry Run
Target mid-tree, `k=2`: BFS reaches parent’s other child and grandchildren — collect those values.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) parents + queue
- Why: each node visited ≤ once in BFS.

## 8. Trade-offs & Alternatives
Recurse with distance downward and upward separately without explicit BFS — trickier.

## 9. Common Mistakes / Edge Cases
Forgetting visited (revisit parent); not linking parents; `k=0` must return target only.

## 10. Interview Follow-ups / Variations
Amount of time to infect tree (2385); burn tree from leaf.

## 11. Tags
`binary-tree`, `bfs`, `dfs`, `graph`, `leetcode-863`, `difficulty:medium`
