# Centroid Decomposition Build

## Problem Statement
CP classic — recursively find a centroid of each live component, mark it removed, and record parent links in the centroid tree (with component sizes at selection time).

- **Inputs:** undirected tree on `n` nodes.
- **Output:** centroid-tree root, `cpar[]`, `compsize_at[]`, children lists.
- **Valid answer:** every node chosen once; root’s `compsize_at` equals `n`.
- **Edges:** `n=1`; balanced tree; skinny path.

## Intuition
Removing a centroid splits into components of size ≤ N/2, so recursion depth is O(log N) and total work across layers is O(N log N).

## Brute Force → Optimal
- **Brute:** re-rooting sizes naively without a `dead[]` mask — messy / wrong on live components.
- **Optimal:** DFS size on the live component → find centroid → mark dead → recurse on neighbors.

## Data Structure / Approach Justification
**Chosen:** `dead[]` mask + size DFS + parent array for the centroid tree.

- **vs HLD:** HLD targets path aggregates with updates; CD shines for path-counting / distance queries.
- **vs binary lifting alone:** LCA/dist only; not a balanced divide-and-conquer skeleton.

## Logic Walkthrough
`build(entry, parent)`: size the live component, find centroid `c`, mark dead, set `cpar[c]=parent`, link into `ctree`, recurse into each non-dead neighbor of `c`.

## Dry Run
Path `1-2-3-4`: first centroid near the middle; remaining path segments recurse as children. All four nodes eventually marked dead; root `compsize_at=4`.

## Time & Space Complexity
Time **O(N log N)** — each node appears in O(log N) layers as sizes halve. Space **O(N)** for graph, masks, and centroid tree. Why: balanced separators.

## Trade-offs & Alternatives
CD for path-counting / constrained distances. HLD + segment tree for path aggregates with updates. Binary lifting for LCA-only queries.

## Common Mistakes / Edge Cases
Forgetting to mark the centroid dead before recursing; sizing the whole tree instead of the live component; 1-based indexing bugs.

## Interview Follow-ups / Variations
Store distances to centroid ancestors for offline queries? Count paths of length K through CD?

## Tags
`tree`, `centroid-decomposition`, `divide-and-conquer`, `cp`, `difficulty:hard`
