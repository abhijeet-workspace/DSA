# Tree Paths of Length K

## Problem Statement
CP classic (CSES / CF tree path counting) — undirected tree on N nodes; count unordered pairs `{u,v}` with `dist(u,v) == K` (K edges on the unique path).

- **Inputs:** tree edges, integer `K`.
- **Output:** number of such pairs.
- **Valid answer:** unordered pairs; each path counted once.
- **Edges:** `K=0`; `K ≥ N` → 0; star (leaf–leaf paths length 2).

## Intuition
Every path has a unique highest centroid. At each centroid, count pairs of nodes in different subtrees whose depths sum to K (plus paths ending at the centroid).

## Brute Force → Optimal
- **Brute:** DFS/BFS from every node — O(N²).
- **Optimal:** centroid decomposition with depth frequency maps — O(N log N).

## Data Structure / Approach Justification
**Chosen:** CD + `freq[depth]` updated after querying each subtree (avoid same-subtree pairs).

- **vs rerooting DP:** O(N) for fixed K variants but less general for constrained counts.
- **vs binary lifting + two pointers:** heavier setup for this exact count.

## Logic Walkthrough
At centroid `c`, start `freq[0]=1`. For each live child subtree: collect depths, add `freq[K-d]` to answer, then merge depths into `freq`. Mark `c` dead and recurse.

## Dry Run
Path `1-2-3-4`, `K=2`: paths `(1,3)` and `(2,4)` → answer `2`. Star with hub 1 and three leaves, `K=2`: three leaf–leaf pairs → `3`.

## Time & Space Complexity
Time **O(N log N)** — each node processed in O(log N) CD layers. Space **O(N + K)** for graph, masks, and freq. Why: balanced separators + depth maps.

## Trade-offs & Alternatives
CD generalizes to weighted / constrained path counts. Rerooting DP is simpler when you only need all-pairs distance sums of a fixed form.

## Common Mistakes / Edge Cases
Double-counting pairs inside the same subtree (merge before query); forgetting centroid depth 0; `K=0` off-by-one.

## Interview Follow-ups / Variations
Sum of distances of all pairs? Length in `[L,R]`? Weighted edges?

## Tags
`tree`, `centroid-decomposition`, `path-counting`, `cp`, `difficulty:hard`
