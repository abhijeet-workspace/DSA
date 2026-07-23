# Dinic Max Flow

## Problem Statement
Compute maximum s–t flow in a directed capacity network (blocking-flow / Dinic).

- **Inputs:** residual graph via `addEdge(u,v,c)`, source `s`, sink `t`.
- **Output:** max flow value.
- **Valid answer:** max flow (= min cut capacity).
- **Edges:** no path; multiple edges; zero caps; unit networks.

## Intuition
BFS builds a level graph of shortest residual paths. DFS pushes a blocking flow only along edges that increase level by 1. Each phase lengthens the shortest augmenting path.

## Brute Force → Optimal
- **Brute / Ford–Fulkerson:** arbitrary augmenting paths — may be slow / need care with IR.
- **Edmonds–Karp:** BFS paths O(VE²).
- **Dinic:** typically much faster; O(V²E) general, better on unit caps.

## Data Structure / Approach Justification
**Chosen:** adjacency list of residual edges with reverse indices + level/`it` arrays.

- **vs Edmonds–Karp:** more code, better practical speed.
- **vs push-relabel:** competitive; different implementation tradeoffs.

## Logic Walkthrough
While `bfs()` reaches `t`: reset iterators, repeatedly `dfs` from `s` until no more flow in this level graph; accumulate.

## Dry Run
Caps `0→1:10`, `0→2:5`, `1→3:8`, `2→3:10`, `1→2:4` → max flow 15 (min cut leaves sink with capacity 18 but source side limits to 15).

## Time & Space Complexity
Time **O(V²E)** typical bound. Space **O(V+E)**. Why: O(V) phases × blocking flow work (section 4).

## Trade-offs & Alternatives
EK is easier to write in interviews; Dinic preferred in CP. State max-flow min-cut.

## Common Mistakes / Edge Cases
Forgetting reverse residual edges; not resetting `it` each phase; using DFS without level constraint.

## Interview Follow-ups / Variations
Min cut edges; bipartite matching via flow; circulation with demands.

## Tags
`graph`, `max-flow`, `dinic`, `network-flow`, `difficulty:hard`
