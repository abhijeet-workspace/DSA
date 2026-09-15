# Tree Diameter

## 1. Problem Statement
[LeetCode 1245](https://leetcode.com/problems/tree-diameter/) (premium) / CP classic — length (edges) of the longest path in an undirected tree.

- **Inputs:** `edges` list on `n = |edges|+1` nodes.
- **Output:** diameter length.
- **Edges:** single edge → 1; star → 2.

## 2. Intuition
Two BFS/DFS: farthest from arbitrary node → farthest from that node is a diameter endpoint.

## 3. Brute Force → Optimal
- **Brute:** all-pairs distances.
- **Optimal:** two sweeps — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** iterative DFS/BFS farthest twice.

| Alternative | Note |
|-------------|------|
| Tree DP heights | Also O(N); good interview variant |
| Centroid | Unrelated for plain diameter |

## 5. Logic Walkthrough
From 0 find farthest `u`; from `u` find farthest distance `d`.

## 6. Dry Run
`0-1-2-3` plus `1-4` → diameter `3`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Tree DP returns diameter while computing heights in one DFS.

## 9. Common Mistakes / Edge Cases
Counting nodes instead of edges; disconnected input (not a tree).

## 10. Interview Follow-ups / Variations
Weighted diameter; count diameter paths.

## 11. Tags
`leetcode-1245`, `tree-diameter`, `bfs`, `difficulty:medium`
