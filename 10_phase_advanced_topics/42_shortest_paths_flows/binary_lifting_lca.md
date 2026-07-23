# Binary Lifting LCA

## Problem Statement
On a rooted tree, answer k-th ancestor and LCA queries online. Related: [LeetCode 1483](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/).

- **Inputs:** undirected tree edges, root, query pairs `(a,b)`.
- **Output:** LCA node id.
- **Valid answer:** deepest common ancestor.
- **Edges:** `a==b`; root queries; skewed deep trees.

## Intuition
Precompute `up[k][v] = 2^k`-th ancestor. Any depth difference decomposes into distinct powers of two. Equalize depths, then joint-lift while ancestors differ.

## Brute Force → Optimal
- **Brute:** climb parents one-by-one — O(N) per query.
- **Optimal:** binary lifting — build O(N log N), query O(log N) (often stated O(1) with care / RMQ).

## Data Structure / Approach Justification
**Chosen:** `up[LOG][N]` + depth array.

- **vs Euler tour + sparse table RMQ:** faster queries, more prep code.
- **vs Tarjan offline LCA:** great for offline batches.

## Logic Walkthrough
DFS fills `up[0]` and depths. DP fills higher `up[k]`. LCA: lift deeper node; if equal return; else lift both from high bits; return parent.

## Dry Run
Tree `0-1-3`, `0-2-4`: `LCA(3,4)` equalize depths → both at depth 1 under 0 → joint lift fails → parent `0`.

## Time & Space Complexity
Build **O(N log N)**, query **O(log N)**, space **O(N log N)**. Why: LOG ≈ log N ancestors each (section 4).

## Trade-offs & Alternatives
Memory-heavy vs parent-climb. Sparse table on Euler tour is the classic O(1) query upgrade.

## Common Mistakes / Edge Cases
Forgetting to lift the deeper node first; `up` parent of root set incorrectly.

## Interview Follow-ups / Variations
K-th ancestor; distance via `depth[a]+depth[b]-2*depth[lca]`; path aggregates with HLD.

## Tags
`tree`, `lca`, `binary-lifting`, `sparse-table`, `difficulty:medium`
