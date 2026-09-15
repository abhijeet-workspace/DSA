# Is Graph Bipartite

## 1. Problem Statement
[LeetCode 785](https://leetcode.com/problems/is-graph-bipartite/) — return whether an undirected graph can be 2-colored so every edge joins opposite colors.

- **Inputs:** adjacency list `graph` (`graph[u]` = neighbors of `u`).
- **Output:** `bool`.
- **Valid answer:** true iff no odd cycle (graph is bipartite).
- **Edges:** disconnected components; single node; triangle; even cycle.

## 2. Intuition
Bipartite ⟺ 2-colorable. BFS/DFS assign opposite colors to neighbors; a same-color adjacency means an odd cycle.

## 3. Brute Force → Optimal
- **Brute:** try all 2^V colorings — exponential.
- **Optimal:** one BFS/DFS pass per component — O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** BFS with `colors[u] ∈ {0, +1, -1}` and a queue per uncolored source.

- **vs DFS recursion:** same complexity; BFS avoids deep stacks on long paths.
- **vs checking girth explicitly:** coloring is simpler and sufficient.

## 5. Logic Walkthrough
For each uncolored `i`, color it `+1` and BFS. Uncolored neighbor → opposite color; same color neighbor → false. Finish all components → true.

## 6. Dry Run
4-cycle `0-1-2-3-0`: colors alternate → bipartite.  
Triangle `0-1-2`: third edge sees matching colors → not bipartite.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V)** for colors/queue. Why: each vertex/edge examined once (section 4).

## 8. Trade-offs & Alternatives
DFS coloring is shorter recursively. Union-Find bipartite tricks exist but are less common in interviews.

## 9. Common Mistakes / Edge Cases
Only coloring one component; treating the graph as directed; using 0/1 without a distinct “uncolored” state.

## 10. Interview Follow-ups / Variations
Possible bipartition sets. Bipartite matching. Detect odd cycle explicitly.

## 11. Tags
`bipartite`, `bfs`, `graph-coloring`, `leetcode-785`, `difficulty:medium`
