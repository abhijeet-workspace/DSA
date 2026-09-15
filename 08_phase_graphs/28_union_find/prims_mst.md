# Prim's MST

## 1. Problem Statement
Classic **Prim** — build a Minimum Spanning Tree by growing a single tree from a start vertex; return total weight.

- **Inputs:** `V`, undirected adjacency list of `{weight, neighbor}`.
- **Output:** MST total weight (assumes connected).
- **Valid answer:** weight of any MST.
- **Edges:** equal weights; start vertex choice; dense graphs.

## 2. Intuition
Maintain the cut between tree and non-tree vertices. Always add the lightest edge crossing the cut (cut property → optimality).

## 3. Brute Force → Optimal
- **Brute:** scan all crossing edges each step — O(V·E).
- **Optimal:** binary heap Prim — O(E log V); dense Prim matrix — O(V²).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of candidate edges + `inMST` flags (lazy Prim).

- **vs Kruskal:** Prim fits adjacency lists; Kruskal fits raw edge lists.
- **vs decrease-key Prim:** cleaner constants in theory; lazy heap is simpler to code.

## 5. Logic Walkthrough
Push `(0, start)`. While heap non-empty: pop lightest; skip if already in MST; mark in, add weight; push all edges to non-tree neighbors.

## 6. Dry Run
5-vertex sample with edges as in `main` → MST weight **16** (e.g. 0-1, 0-3, 1-4, 1-2).

## 7. Time & Space Complexity
Time **O(E log V)** with binary heap. Space **O(V+E)**. Why: each edge may be pushed/popped from the heap (section 4).

## 8. Trade-offs & Alternatives
Use dense O(V²) Prim when E ≈ V². Use Kruskal when you only have an edge list and want DSU practice.

## 9. Common Mistakes / Edge Cases
Forgetting undirected reverse edges; not skipping stale heap entries; starting weight counted twice.

## 10. Interview Follow-ups / Variations
Return parent pointers of the MST. Bottleneck MST. Compare with Kruskal on the same graph.

## 11. Tags
`mst`, `prim`, `priority-queue`, `greedy`, `difficulty:medium`
