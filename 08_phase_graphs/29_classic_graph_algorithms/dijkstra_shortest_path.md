# Dijkstra Shortest Path

## 1. Problem Statement
Classic Dijkstra: given a directed graph with non-negative edge weights, compute shortest-path distances from `src` to all nodes (INF if unreachable).

- **Inputs:** `n`, edges `[u,v,w]`, `src`.
- **Output:** distance array.
- **Valid answer:** δ(src,·) under non-negative weights.
- **Edges:** unreachable nodes; zero-weight edges; dense graphs.

## 2. Intuition
Greedily finalize the unsettled node with smallest tentative distance; relax its outgoing edges (priority queue).

## 3. Brute Force → Optimal
- **Brute:** Bellman-Ford O(nE) works with negatives too.
- **Optimal:** binary-heap Dijkstra O((n+E) log n) for non-negative weights.

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of (dist,node) + adj list.

- **vs set-based Dijkstra:** similar.
- **vs Fibonacci heap:** theoretical; rare in practice.

## 5. Logic Walkthrough
dist[src]=0. While PQ: pop best u; skip if stale; relax neighbors and push updates.

## 6. Dry Run
Graph with shortcut 0→2→1→3 yields dist[3]=6.

## 7. Time & Space Complexity
Time **O((n+E) log n)**. Space **O(n+E)**. Why: heap Dijkstra (section 4).

## 8. Trade-offs & Alternatives
See [Network Delay Time](https://leetcode.com/problems/network-delay-time/) for a LeetCode wrapper.

## 9. Common Mistakes / Edge Cases
Using Dijkstra with negative edges; not skipping stale entries; 1-index confusion.

## 10. Interview Follow-ups / Variations
A*; bidirectional Dijkstra; potential reduction for negatives (Johnson).

## 11. Tags
`dijkstra`, `shortest-path`, `classic`, `difficulty:medium`
