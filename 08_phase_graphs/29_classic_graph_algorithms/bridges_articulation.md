# Bridges and Articulation Points

## Problem Statement
Find **bridges** (critical edges) and **articulation points** (cut vertices) in an undirected graph via Tarjan DFS.

- **Inputs:** undirected adjacency list.
- **Output:** list of bridge edges; set of cut vertices.
- **Valid answer:** edge/vertex whose removal increases connected-component count.
- **Edges:** root vs non-root cuts; multiple edges; disconnected graphs; pure cycle (no bridges).

## Intuition
`tin[u]` = discovery time; `low[u]` = earliest discovery reachable from `u`'s subtree via tree/back edges. Bridge if child has `low[v] > tin[u]`; non-root cut if `low[v] >= tin[u]`; root cut if ≥2 DFS children.

## Brute Force → Optimal
- **Brute:** remove each edge/vertex and recount components — O(E(V+E)) / O(V(V+E)).
- **Optimal:** one Tarjan DFS — O(V+E).

## Data Structure / Approach Justification
**Chosen:** recursive DFS with `tin`, `low`, `visited`, plus result containers.

- **vs naive removal:** far too slow for interviews at scale.
- **vs flow-based cuts:** overkill for unweighted undirected critical connections.

## Logic Walkthrough
DFS from each unvisited node. On tree edge to `v`, recurse and update `low[u]`. Check bridge/art conditions. On back edge, `low[u] = min(low[u], tin[v])` (skip parent).

## Dry Run
Edges `0-1-2-0` triangle plus `1-3-4`: bridges `1-3`, `3-4`; articulation points include `1` and `3`.

## Time & Space Complexity
Time **O(V+E)**. Space **O(V)** (+ recursion stack). Why: each edge examined twice in undirected DFS (section 4).

## Trade-offs & Alternatives
Iterative Tarjan avoids stack overflow on deep graphs. For directed graphs use different strongly-connected / bridge notions.

## Common Mistakes / Edge Cases
Updating `low` with `low[v]` on back edges (should use `tin[v]`); treating parent as a back edge; wrong root child count with parallel edges.

## Interview Follow-ups / Variations
LeetCode 1192 Critical Connections. Block-cut tree. Bridge-connected components.

## Tags
`tarjan`, `bridges`, `articulation-points`, `dfs`, `difficulty:hard`
