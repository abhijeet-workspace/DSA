# Find All Centroids

## 1. Problem Statement
CP / teaching — list every centroid by verifying each adjacent component has size ≤ N/2 (brute check; complements the O(N) heavy-child walk).

- **Inputs:** undirected tree.
- **Output:** sorted centroid ids.
- **Edges:** even path (two centroids); odd path (one).

## 2. Intuition
Definition: a node is a centroid iff no neighbor-component exceeds N/2.

## 3. Brute Force → Optimal
- **Brute (this file):** O(N²) per-node component scans.
- **Optimal:** size DFS + walk — O(N) (`centroid_find`).

## 4. Data Structure / Approach Justification
**Chosen:** explicit component enumeration for verification pedagogy.

| Alternative | Note |
|-------------|------|
| Heavy-child walk | Production |
| Leaf peeling | Also O(N) |

## 5. Logic Walkthrough
For each `v`, measure each neighbor component excluding `v`; accept if all ≤ N/2.

## 6. Dry Run
Path `1-2-3-4` → centroids `{2,3}`.

## 7. Time & Space Complexity
Time **O(N²)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Use as an oracle to test the O(N) finder.

## 9. Common Mistakes / Edge Cases
Using `<` instead of `≤` for N/2.

## 10. Interview Follow-ups / Variations
Prove at most two centroids.

## 11. Tags
`centroid`, `verification`, `tree`, `cp`, `difficulty:easy`
