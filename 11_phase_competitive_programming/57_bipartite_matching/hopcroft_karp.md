# Hopcroft–Karp

## Problem Statement
CP classic — faster maximum bipartite matching via layered BFS + multiple DFS augmentations per phase.

- **Inputs:** left `1..nL`, right `1..nR`, edges left→right (1-based; `NIL=0` sentinel).
- **Output:** matching size.
- **Valid answer:** same as Kuhn / unit max-flow.
- **Edges:** unbalanced parts; dense complete bipartite.

## Intuition
BFS builds shortest-distance layers from free left nodes; DFS finds vertex-disjoint augmenting paths of that length in one phase (blocking flow in a unit network).

## Brute Force → Optimal
- **Brute / Kuhn:** O(VE) single-path DFS.
- **Optimal:** Hopcroft–Karp O(E√V) — O(√V) phases.

## Data Structure / Approach Justification
**Chosen:** `pairU`/`pairV` with NIL sentinel + `dist[]` layers.

- **vs Kuhn:** more code; asymptotically better on large graphs.
- **vs Dinic on bipartite flow:** same complexity class; HK is specialized.

## Logic Walkthrough
While `bfs()` finds a free right at finite layer: for each free left, `dfs` along increasing `dist` edges, flipping matches. Repeat phases until no augmenting path of any length.

## Dry Run
Complete bipartite `K_{2,2}`: two phases or one multi-DFS → matching size `2`.

## Time & Space Complexity
Time **O(E√V)**. Space **O(V+E)**. Why: unit-capacity blocking-flow analysis yields ≤ √V phases.

## Trade-offs & Alternatives
Use when V is large and the graph is dense-ish. Kuhn is shorter to write for small V. Dinic is a good general alternative.

## Common Mistakes / Edge Cases
Incorrect distance checks in DFS; forgetting to set `dist[u]=INF` on DFS failure; mixing 0/1 indexing with NIL.

## Interview Follow-ups / Variations
Min-cost bipartite matching? Construct the matching pairs? König vertex cover from the final matching?

## Tags
`bipartite`, `matching`, `hopcroft-karp`, `blocking-flow`, `difficulty:hard`
