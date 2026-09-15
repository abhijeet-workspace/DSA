# Is Graph Bipartite

## 1. Problem Statement
[LeetCode 785](https://leetcode.com/problems/is-graph-bipartite/) — check whether an undirected graph is 2-colorable.

- **Inputs:** adjacency list `graph`.
- **Output:** true/false.
- **Edges:** disconnected; odd cycle.

## 2. Intuition
BFS/DFS 2-coloring; conflict on same-color edge ⇒ not bipartite. Matching algorithms require this property.

## 3. Brute Force → Optimal
- **Brute:** try partitions.
- **Optimal:** BFS coloring O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** multi-source BFS colors.

| Alternative | Note |
|-------------|------|
| Union-Find with parity | Also O(V+E) |

## 5. Logic Walkthrough
For each uncolored component, color 0 and propagate XOR 1; reject monochromatic edges.

## 6. Dry Run
Odd-cycle sample → false; even cycle → true.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V)**.

## 8. Trade-offs & Alternatives
Prerequisite check before Kuhn/Hopcroft.

## 9. Common Mistakes / Edge Cases
Only checking one component; treating directed edges.

## 10. Interview Follow-ups / Variations
Count bipartition sizes; odd-cycle detection certificate.

## 11. Tags
`leetcode-785`, `bipartite`, `bfs-coloring`, `difficulty:medium`
