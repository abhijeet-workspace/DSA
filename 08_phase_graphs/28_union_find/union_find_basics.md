# Union-Find Basics

## 1. Problem Statement
Teach a standard **Disjoint Set Union (DSU)** with path compression and union by rank; demo by counting connected components on an undirected edge list.

- **Inputs:** `n` nodes, undirected `edges`.
- **Output (demo):** number of connected components.
- **Valid answer:** DSU partitions match undirected connectivity.
- **Edges:** no edges; already united pairs; skewed link order.

## 2. Intuition
Each element starts in its own set. `find` returns the representative; `union` merges sets. Path compression flattens trees; rank keeps them shallow.

## 3. Brute Force → Optimal
- **Brute:** rebuild components with DFS after every edge — O(E(N+E)).
- **Optimal:** DSU — O((N+E) α(N)) ≈ almost O(N+E).

## 4. Data Structure / Approach Justification
**Chosen:** `parent` + `rank` arrays, recursive find with compression.

- **vs linked-list union-find:** worse asymptotics without weighted union.
- **vs adjacency flood-fill:** DSU is the reusable primitive for MST / redundant-edge problems.

## 5. Logic Walkthrough
Init `parent[i]=i`, `count=n`. `find` recurses to root and writes parents. `unionSets` links lower rank under higher; equal rank increments. Demo decrements `count` on each merge.

## 6. Dry Run
`n=5`, edges `0-1`, `1-2`, `3-4`: three merges → components `{0,1,2}` and `{3,4}` → **2**.

## 7. Time & Space Complexity
Time **O((N+E) α(N))** per forest operations. Space **O(N)**. Why: Ackermann-inverse bound with compression + rank (section 4).

## 8. Trade-offs & Alternatives
Iterative find avoids deep recursion. Union by size is equivalent to rank for interviews. DFS counting is simpler if you never reuse DSU.

## 9. Common Mistakes / Edge Cases
Forgetting to compress; union without find; not handling `ra==rb`; 1-based vs 0-based nodes.

## 10. Interview Follow-ups / Variations
Explain α(N). Online connectivity. Kruskal. Accounts merge / redundant connection.

## 11. Tags
`union-find`, `dsu`, `path-compression`, `union-by-rank`, `difficulty:easy`
