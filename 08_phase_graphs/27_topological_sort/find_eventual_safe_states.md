# Find Eventual Safe States

## 1. Problem Statement
[LeetCode 802](https://leetcode.com/problems/find-eventual-safe-states/) — a node is safe if every path from it reaches a terminal (outdegree 0) without entering a cycle. Return all safe nodes sorted ascending.

- **Inputs:** directed graph as adjacency lists.
- **Output:** sorted list of safe node indices.
- **Valid answer:** nodes not on / not reaching any cycle.
- **Edges:** all terminals; one big cycle; self-loop.

## 2. Intuition
Unsafe iff a cycle is reachable. 3-color DFS: gray = on stack (back-edge → cycle); black = proven safe. Alternatively reverse edges and Kahn from terminals.

## 3. Brute Force → Optimal
- **Brute:** from each node DFS detect cycle — O(V(V+E)) without memo.
- **Optimal:** color DFS with memo — **O(V+E)**; or reverse Kahn — **O(V+E)**.

## 4. Data Structure / Approach Justification
**Chosen:** color DFS (`0/1/2`).

- **vs reverse Kahn:** same complexity; Kahn builds reverse graph explicitly.
- **vs per-query cycle check:** too slow without caching.

## 5. Logic Walkthrough
`dfs(u)`: if colored return safe?; mark gray; recurse neighbors — any false → unsafe; mark black safe. Collect black nodes.

## 6. Dry Run
Graph with cycle `0↔3` via paths: nodes `2,4,5,6` never reach the cycle → safe.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V)** colors + recursion. Why: each node/edge processed once (section 4).

## 8. Trade-offs & Alternatives
Reverse Kahn: reverse all edges, start from outdegree-0 in original (indegree-0 in reverse), peel — remaining not processed are unsafe.

## 9. Common Mistakes / Edge Cases
Treating only nodes *on* a cycle as unsafe (nodes that *reach* a cycle are also unsafe); forgetting sort (DFS order may already be sorted if scanned 0..n-1).

## 10. Interview Follow-ups / Variations
Detect all nodes on cycles; longest path in DAG of safe condensation.

## 11. Tags
`graph`, `dfs`, `cycle-detection`, `topological-sort`, `leetcode-802`, `difficulty:medium`
