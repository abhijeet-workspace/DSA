# Reachable Nodes In Subdivided Graph

## 1. Problem Statement
[LeetCode 882](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/) — edges subdivided into `cnt` nodes; count reachable original+subdivision nodes with ≤ `maxMoves` from 0.

- **Inputs:** edges `[u,v,cnt]`, `maxMoves`, `n`.
- **Output:** reachable count.
- **Edges:** maxMoves 0; large cnt.

## 2. Intuition
Dijkstra on original graph with edge length `cnt+1`; then each edge contributes `min(cnt, leftover_u+leftover_v)` subdivision nodes.

## 3. Brute Force → Optimal
- **Brute:** explicit subdivision.
- **Optimal:** Dijkstra + edge accounting.

## 4. Data Structure / Approach Justification
**Chosen:** Dijkstra distances + per-edge min formula.

| Alternative | Note |
|-------------|------|
| Build explicit graph | Memory blowup |

## 5. Logic Walkthrough
SSSP from 0; count originals; add capped subdivision uses.

## 6. Dry Run
LC sample → `13`.

## 7. Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Advanced SSSP application beside Johnson APSP.

## 9. Common Mistakes / Edge Cases
Double-counting subdivision nodes; wrong edge length.

## 10. Interview Follow-ups / Variations
Directed subdivided graphs.

## 11. Tags
`leetcode-882`, `dijkstra`, `graph`, `difficulty:hard`
