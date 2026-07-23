# Centroid Find

## Problem Statement
CP classic — find all centroids of an undirected tree: nodes whose every adjacent component has size ≤ N/2. A tree has one centroid, or two adjacent ones.

- **Inputs:** undirected tree on `n` nodes (edges as adjacency list).
- **Output:** sorted list of centroid node ids.
- **Valid answer:** one node, or two neighbors when `n` is even.
- **Edges:** `n=1`; even-length path; star (hub only).

## Intuition
Root anywhere, compute subtree sizes, walk toward any child with size > N/2; the stopping node is a centroid. If N is even, a neighbor with component size N/2 may be the second.

## Brute Force → Optimal
- **Brute:** try every node and measure components — O(N²).
- **Optimal:** one size DFS + walk — O(N); verify neighbors with component checks.

## Data Structure / Approach Justification
**Chosen:** adjacency list + subtree-size array, then heavy-child walk.

- **vs leaf peeling:** also finds centroids but does not extend as cleanly into full centroid decomposition.
- **vs O(N²) per-node BFS:** same answer, too slow for contest N.

## Logic Walkthrough
`dfsSize` from root 1. From v=1, while some child has `sz > n/2`, move there. Collect v if it is a centroid, plus any neighboring centroid; unique-sort.

## Dry Run
Path `1-2-3-4-5`: sizes under root 1 → walk to 3 → unique centroid `{3}`. Edge `1-2`: both nodes are centroids `{1,2}`.

## Time & Space Complexity
Time **O(N)** for size DFS + walk (verify may be O(N) extra). Space **O(N)** for graph and sizes. Why: one pass finds a candidate; at most two centroids exist.

## Trade-offs & Alternatives
Size-walk extends directly into full centroid decomposition. Leaf peeling is fine if you only need the centroid set.

## Common Mistakes / Edge Cases
Using strict `< N/2` and rejecting a valid centroid; forgetting trees can have two centroids; 1-based vs 0-based ids.

## Interview Follow-ups / Variations
List all centroids? Build the full centroid tree? Use centroid as root for balanced recursion?

## Tags
`tree`, `centroid`, `subtree-size`, `cp`, `difficulty:medium`
