# Graph Valid Tree

## Problem Statement
[LeetCode 261](https://leetcode.com/problems/graph-valid-tree/) (premium) — given `n` nodes and undirected `edges`, return true iff they form a valid tree.

- **Inputs:** `int n`, `vector<vector<int>> edges`.
- **Output:** `bool`.
- **Valid answer:** connected + acyclic (equivalently: connected and `|E| == n-1`).
- **Edges:** `n=1` no edges; disconnected with `n-1` edges; self-loop; duplicate edge.

## Intuition
A tree on n vertices has exactly n−1 edges and is connected. Union-Find rejects any edge that joins already-same components (cycle) and checks one component remains.

## Brute Force → Optimal
- **Brute:** DFS/BFS cycle detect + visit count — O(N+E).
- **Optimal:** early reject on `|E| != n-1`, then DSU — O(N α(N)).

## Data Structure / Approach Justification
**Chosen:** DSU with path compression + union by rank; track `comps`.

- **vs DFS from 0:** also fine; must still verify visited == n and no back edge.
- **vs only `|E|==n-1`:** insufficient alone (disconnected counterexamples).

## Logic Walkthrough
If `|edges| != n-1` → false. For each edge, `unite`; false on failure. Return `comps == 1`.

## Dry Run
`n=5`, star edges from 0 → four unions, comps=1 → true.  
Extra chord among neighbors → unite fails → false.

## Time & Space Complexity
Time **O(N α(N))** after the edge-count check. Space **O(N)**. Why: nearly-constant DSU ops per edge (section 4).

## Trade-offs & Alternatives
Edge-count early exit is a fast reject. BFS/DFS preferred if DSU is unfamiliar. For dynamic graphs, stick with DSU.

## Common Mistakes / Edge Cases
Checking only edge count; forgetting connectivity; 0- vs 1-indexing; treating directed edges.

## Interview Follow-ups / Variations
Count spanning trees. Fully dynamic edge inserts. Detect which edge breaks the tree property.

## Tags
`union-find`, `tree`, `graph`, `leetcode-261`, `difficulty:medium`
