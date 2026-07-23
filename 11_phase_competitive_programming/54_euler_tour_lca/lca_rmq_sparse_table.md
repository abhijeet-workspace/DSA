# LCA RMQ Sparse Table

## Problem Statement
Rooted tree: answer lowest common ancestor of pairs `(u, v)`.

- **Inputs:** undirected tree, root, LCA queries.
- **Output:** LCA node id for each pair.
- **Valid answer:** deepest node that is an ancestor of both (or the node itself if equal).
- **Edges:** `u==v`; one is ancestor of the other; root involved.

## Intuition
Record nodes in a DFS Euler tour with depths. Between the first occurrences of `u` and `v`, the minimum-depth node is the LCA. Sparse table gives `O(1)` RMQ after `O(N log N)` build.

## Brute Force → Optimal
- **Brute:** walk parents to equalize depth then climb — `O(N)` per query.
- **Optimal:** Euler tour + sparse table on depths — `O(1)` per query.

## Data Structure / Approach Justification
**Chosen:** Euler + first[] + sparse table on depth indices.

- **vs binary lifting:** simpler for kth ancestor; `O(log N)`/query.
- **vs Tarjan offline:** DFS+DSU, one-shot offline.

## Logic Walkthrough
DFS records visit + return to parent. Build ST for argmin depth. Query: RMQ on `[first[u], first[v]]`, return `euler[idx]`.

## Dry Run
Tree `0-1-3`, `0-2-4`:
- `LCA(3,4)=0`, `LCA(3,1)=1`, `LCA(4,2)=2`, `LCA(3,3)=3`.

## Time & Space Complexity
Preprocess **O(N log N)**; query **O(1)**. Space **O(N log N)**. Why: path `u→LCA→v` is a contiguous Euler segment; shallowest node is LCA (section 4).

## Trade-offs & Alternatives
Sparse table is fastest static RMQ but forbids depth updates. Binary lifting extends more easily to kth ancestor.

## Common Mistakes / Edge Cases
RMQ on node ids instead of depths; wrong first occurrence; ST off-by-one on interval length.

## Interview Follow-ups / Variations
kth ancestor? Distance `depth[u]+depth[v]-2*depth[lca]`?

## Tags
`lca`, `euler-tour`, `sparse-table`, `rmq`, `difficulty:hard`
