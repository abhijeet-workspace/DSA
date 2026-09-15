# Decompose and Answer Distance Queries

## 1. Problem Statement
Teaching lab — answer offline distance queries on a tree.

**Pedagogy:** full CD stores distances to centroid ancestors and meets at the lowest common centroid; this lab uses parent-climb LCA for clear O(N) preprocess + O(N) query I/O, with CD called out in §4 as the scalable path-query skeleton.

- **Inputs:** tree, queries `(u,v)`.
- **Output:** `dist(u,v)`.
- **Edges:** `u=v` → 0.

## 2. Intuition
`dist = depth[u]+depth[v]-2*depth[lca]`.

## 3. Brute Force → Optimal
- **Brute:** BFS per query.
- **This lab:** root + climb.
- **CD approach:** precompute dist to each centroid ancestor; query walks both ancestor lists.

## 4. Data Structure / Approach Justification
**Chosen:** rooted depths + parent climb for verifiable I/O.

| Alternative | Note |
|-------------|------|
| Binary lifting LCA | O(N log N) / O(log N) |
| Centroid ancestors | Natural with CD build |

## 5. Logic Walkthrough
DFS depths; for each query climb to LCA; apply formula.

## 6. Dry Run
`4` and `5` under root `1` with `1-2-3-4`, `2-5` → dist `3`.

## 7. Time & Space Complexity
Time preprocess **O(N)**, query **O(N)** climb. Space **O(N)**.

## 8. Trade-offs & Alternatives
Prefer binary lifting or CD ancestor tables for large Q.

## 9. Common Mistakes / Edge Cases
Wrong root; `u=v` mishandled.

## 10. Interview Follow-ups / Variations
Upgrade to binary lifting; store CD ancestor distances.

## 11. Tags
`tree`, `distance-query`, `lca`, `centroid-pedagogy`, `difficulty:medium`
