# Number of Connected Components

## 1. Problem Statement
[LeetCode 323](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) (premium) — return the number of connected components in an undirected graph with `n` nodes.

- **Inputs:** `int n`, `vector<vector<int>> edges`.
- **Output:** component count.
- **Valid answer:** partitions of `0..n-1` under undirected connectivity.
- **Edges:** no edges → `n`; fully connected → `1`; isolated nodes; duplicate edges.

## 2. Intuition
Start with `n` components. Each successful union merges two sets and decrements the count.

## 3. Brute Force → Optimal
- **Brute / DFS:** flood-fill from each unvisited node — O(N+E).
- **Optimal for online edges:** Union-Find — O((N+E) α(N)).

## 4. Data Structure / Approach Justification
**Chosen:** parent array with path compression; count decremented on merge.

- **vs adjacency DFS:** simpler if the full graph is static and already built.
- **vs BFS:** same as DFS for counting starts.

## 5. Logic Walkthrough
Init `parent[i]=i`, `comps=n`. For each edge, find roots; if different, link and `--comps`. Return `comps`.

## 6. Dry Run
`n=5`, edges `0-1`, `1-2`, `3-4`: merges → components `{0,1,2}`, `{3,4}` → **2**.

## 7. Time & Space Complexity
Time **O((N+E) α(N))**. Space **O(N)**. Why: nearly-constant find/union per edge (section 4).

## 8. Trade-offs & Alternatives
DFS is clearer for one-shot static graphs. DSU wins when edges stream in or you already need DSU elsewhere.

## 9. Common Mistakes / Edge Cases
Forgetting isolates (`comps` must start at `n`); not compressing paths; treating the graph as directed.

## 10. Interview Follow-ups / Variations
Largest component size. Dynamic deletions. Count after each edge insert.

## 11. Tags
`union-find`, `graph`, `components`, `leetcode-323`, `difficulty:medium`
