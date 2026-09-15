# Distance-K Nodes (Centroid)

## 1. Problem Statement
Teaching lab — count unordered pairs at distance exactly `K` on a tree (centroid decomposition). Related framing to [LeetCode 863](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) (list nodes from one source in a binary tree) but here we **count pairs** on an undirected tree.

- **Inputs:** undirected tree, `K`.
- **Output:** number of unordered pairs at distance `K`.
- **Edges:** star; path; `K=1` equals edge count.

## 2. Intuition
CD layers partition paths by highest centroid; depth-pair counting answers distance-K.

## 3. Brute Force → Optimal
- **Brute:** BFS from each node.
- **Optimal:** CD O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** centroid + depth frequency maps.

| Alternative | Note |
|-------------|------|
| LC 863 parent map + BFS | Better for rooted binary trees *listing* nodes |
| Two BFS | Diameter-style, not for all pairs |

## 5. Logic Walkthrough
Same CD path-count skeleton as `tree_paths_of_length_k`.

## 6. Dry Run
Star hub+4 leaves, `K=2` → `6` leaf pairs.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N+K)**. Why: balanced separators (section 4).

## 8. Trade-offs & Alternatives
Use parent-pointer BFS when the tree is rooted binary and you must list nodes from one source.

## 9. Common Mistakes / Edge Cases
Off-by-one on depth; double-counting same subtree.

## 10. Interview Follow-ups / Variations
List nodes from a source; weighted distance.

## 11. Tags
`centroid`, `distance-k`, `tree`, `cp`, `difficulty:medium`
