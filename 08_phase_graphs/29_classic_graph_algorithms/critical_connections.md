# Critical Connections in a Network

## Problem Statement
[LeetCode 1192](https://leetcode.com/problems/critical-connections-in-a-network/) — find all bridges (edges whose removal disconnects the graph) in an undirected connected graph.

- **Inputs:** `n` nodes, undirected edges.
- **Output:** list of bridge edges.
- **Valid answer:** any order of bridges/endpoints.
- **Edges:** tree (all edges bridges); complete (none).

## Intuition
Tarjan: discovery time + low-link; edge u–v is bridge iff `low[v] > disc[u]` after exploring v.

## Brute Force → Optimal
- **Brute:** remove each edge, check connectivity — O(E(V+E)).
- **Optimal:** one DFS Tarjan — O(V+E).

## Data Structure / Approach Justification
**Chosen:** adjacency list + `disc`/`low` arrays.

- **vs articulation points:** related but different condition (`>=`).

## Logic Walkthrough
DFS assign disc; low = min over tree-child lows and back-edge discs; record bridge when child low > parent disc.

## Dry Run
Triangle 0-1-2 plus 1-3: only 1-3 is bridge.

## Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**.

## Trade-offs & Alternatives
Union-find bridge finding variants exist but Tarjan is standard.

## Common Mistakes / Edge Cases
Using `>=` (that's cut vertex); not skipping parent edge; updating low via low[v] on back edges incorrectly.

## Interview Follow-ups / Variations
Critical routers (articulation points); SCCs.

## Tags
`graph`, `dfs`, `bridges`, `tarjan`, `leetcode-1192`, `difficulty:hard`
