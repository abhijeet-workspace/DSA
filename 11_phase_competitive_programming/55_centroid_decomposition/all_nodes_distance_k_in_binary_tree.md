# All Nodes Distance K in Binary Tree

## 1. Problem Statement
[LeetCode 863](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) — return all node values at distance `k` from `target` in a binary tree.

**Pedagogy:** parent-map + BFS (not CD). Paired with centroid distance-K counting labs to contrast single-source listing vs global pair counting.

- **Inputs:** binary tree root, target node, `k`.
- **Output:** values at distance `k` (any order).
- **Edges:** `k=0` → `{target}`; target is root.

## 2. Intuition
Treat the tree as an undirected graph via parent pointers; BFS from target for exactly `k` layers.

## 3. Brute Force → Optimal
- **Brute:** compute dist from target to every node via DFS.
- **Optimal:** one parent build + BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** parent hashmap + layered BFS.

| Alternative | Note |
|-------------|------|
| Recurse with dist-to-target return | Elegant, harder to get right |
| Centroid | Wrong tool for single-source list |

## 5. Logic Walkthrough
DFS parents; BFS from target; stop at layer `k`; collect queue contents.

## 6. Dry Run
LC sample: target 5, k=2 → `{7,4,1}`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
On undirected trees for pair counts, prefer CD (`distance_k_nodes_centroid`).

## 9. Common Mistakes / Edge Cases
Forgetting parent edge; revisiting nodes; `k=0`.

## 10. Interview Follow-ups / Variations
Count nodes at distance K; weighted edges.

## 11. Tags
`leetcode-863`, `bfs`, `binary-tree`, `distance-k`, `difficulty:medium`
