# Dijkstra Template

## 1. Problem Statement
Teaching-lab — binary-heap Dijkstra for non-negative edge weights. Demo shortest path 0→2 is 3 via 0-1-2.

## 2. Intuition
Always expand the globally closest unsettled node; relaxation is safe with ≥0 weights.

## 3. Brute Force → Optimal
- **Brute:** Bellman-Ford O(VE). **Optimal:** Dijkstra O((V+E) log V).

## 4. Data Structure / Approach Justification
**Chosen:** `priority_queue` Dijkstra with decrease-key via duplicates.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Pop min dist; skip stale; relax neighbors.

## 6. Dry Run
Edges 0→1 (1), 1→2 (2), 0→2 (4) → dist[2]=3.

## 7. Time & Space Complexity
Time **O((V+E) log V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
0-1 BFS for weights 0/1; potentials for Johnson.

## 9. Common Mistakes / Edge Cases
Negative edges; not skipping stale heap entries.

## 10. Interview Follow-ups / Variations
Path recovery via parent; multisource.

## 11. Tags
`dijkstra`, `shortest-path`, `template`, `difficulty:medium`
