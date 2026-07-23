# Tarjan SCC

## Problem Statement
Find all strongly connected components (SCCs) in a directed graph with a **single DFS** using discovery times and low-link values.

- **Inputs:** `V`, directed adjacency list.
- **Output:** list of SCCs (each a vertex list).
- **Valid answer:** partition into maximal strongly connected sets.
- **Edges:** self-loops; single-node components; multiple disconnected digraphs.

## Intuition
During DFS, track `disc[u]` (first visit time) and `low[u]` (earliest disc reachable via tree/back edges into the current stack). When `low[u] == disc[u]`, `u` is an SCC root — pop the stack until `u`.

## Brute Force → Optimal
- **Brute:** pairwise reachability — O(V(V+E)).
- **Optimal:** Tarjan one DFS — O(V+E); Kosaraju two DFS — O(V+E) with transpose.

## Data Structure / Approach Justification
**Chosen:** `disc` / `low` arrays, explicit node `stack`, `inStack` flags.

- **vs Kosaraju:** no transpose graph; one pass.
- **vs naive DFS forests:** low-link correctly merges cycles into one component.

## Logic Walkthrough
On enter: set `disc=low=++time`, push `u`, `inStack[u]=true`. For each neighbor: recurse if unvisited and take `low[v]`; if `v` on stack, take `disc[v]`. If `low[u]==disc[u]`, pop stack into a new SCC until `u`.

## Dry Run
Edges `1→0→2→1`, `0→3→4`:
- cycle `{0,1,2}` shares one root; `{3}` then `{4}` → **3** SCCs (matches demo `g1`).

## Time & Space Complexity
Time **O(V+E)**. Space **O(V)** for arrays + stack (plus adj). Why: each vertex/edge processed once (section 4).

## Trade-offs & Alternatives
Harder to explain than Kosaraju; fewer memory passes. Prefer when SCCs are needed mid-DFS or transpose cost matters.

## Common Mistakes / Edge Cases
Updating `low` from off-stack cross edges; forgetting `inStack`; not starting DFS from every unvisited vertex.

## Interview Follow-ups / Variations
Condensation DAG; bridges/articulation points (related low-link); 2-SAT.

## Tags
`graph`, `scc`, `tarjan`, `dfs`, `low-link`, `difficulty:hard`
