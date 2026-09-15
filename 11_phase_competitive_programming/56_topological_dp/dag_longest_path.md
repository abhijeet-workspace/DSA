# DAG Longest Path

## 1. Problem Statement
CP classic (related to parallel courses / scheduling) — directed acyclic graph; compute the maximum path length (sum of edge weights; default weight 1).

- **Inputs:** DAG with optional edge weights, nodes `1..n`.
- **Output:** max path weight over all paths.
- **Valid answer:** single-node path has length 0.
- **Edges:** multiple sources; disconnected DAG; single node.

## 2. Intuition
`dp[v] = max over u→v of dp[u] + w(u,v)`; evaluate in topological order so predecessors are final.

## 3. Brute Force → Optimal
- **Brute:** enumerate all paths — exponential.
- **Optimal:** Kahn topo + one forward DP pass — O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** adjacency list of weighted edges + indegree queue + `dp[]`.

- **vs recursion + memo:** same asymptotics; iterative topo is cache-friendly.
- **vs negate weights + shortest path:** works but less readable for “longest”.

## 5. Logic Walkthrough
Build indegrees; enqueue sources. Pop `u`, track `best`, relax `dp[to] = max(dp[to], dp[u]+w)`, enqueue when indegree hits 0.

## 6. Dry Run
Unit: `1→2→4`, `1→3→4` → longest length `2`. Weighted: `1→2 (5)`, `2→3 (1)`, `1→3 (3)` → longest `6`.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)** for graph, indeg, dp, queue. Why: acyclicity lets each edge contribute once.

## 8. Trade-offs & Alternatives
Memo matches the recurrence for single-query roots. On general graphs with cycles, longest path is NP-hard.

## 9. Common Mistakes / Edge Cases
Processing nodes in arbitrary order; treating length as hop count when weights vary; forgetting `best` may be an intermediate node.

## 10. Interview Follow-ups / Variations
Reconstruct one longest path? Critical path in a project network? Count longest paths?

## 11. Tags
`dag`, `topological-dp`, `longest-path`, `kahn`, `difficulty:medium`
