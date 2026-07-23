# Kosaraju SCC

## Problem Statement
Find all strongly connected components (SCCs) in a directed graph.

- **Inputs:** `V`, adjacency list of directed edges.
- **Output:** list of components (each a vertex list).
- **Valid answer:** partition into maximal strongly connected sets.
- **Edges:** single nodes; fully strongly connected; DAG (V trivial SCCs).

## Intuition
First DFS records finish order. Condensation of SCCs is a DAG; DFS on the transposed graph in reverse finish order peels sink components of the transpose (= sources of the original condensation).

## Brute Force → Optimal
- **Brute:** pairwise reachability — O(V(V+E)).
- **Optimal:** Kosaraju two DFS passes — O(V+E); Tarjan one-pass — O(V+E).

## Data Structure / Approach Justification
**Chosen:** adj + transpose adj + finish stack.

- **vs Tarjan:** Kosaraju is two clear passes; Tarjan uses less auxiliary graph memory.
- **vs Gabow:** similar one-pass family.

## Logic Walkthrough
DFS1 push on finish. Build `radj`. Clear vis. While stack nonempty: if unvisited, DFS2 collects one SCC.

## Dry Run
Cycle `0→2→1→0` plus `1→3→4` → SCCs `{0,1,2}`, `{3}`, `{4}` (3 components).

## Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**. Why: each vertex/edge processed constant times (section 4).

## Trade-offs & Alternatives
Easy to explain; needs transpose storage. Prefer Tarjan when memory/constants matter.

## Common Mistakes / Edge Cases
Forgetting transpose; processing stack in wrong order; not resetting `vis`.

## Interview Follow-ups / Variations
Build condensation DAG; 2-SAT; count SCCs only.

## Tags
`graph`, `scc`, `kosaraju`, `dfs`, `difficulty:medium`
