# Reorder Routes to Make All Paths Lead to the City Zero

## 1. Problem Statement
[LeetCode 1466](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/) — `n` cities, `n-1` directed roads forming a tree if undirected. Reorient minimum roads so every city can reach city 0.

- **Inputs:** `n`, `connections` directed.
- **Output:** minimum reorientations.
- **Valid answer:** count of edges pointing away from 0 in the rooted tree.
- **Edges:** already all toward 0; star out of 0.

## 2. Intuition
Treat as undirected tree for traversal; when DFS walks an originally forward edge away from 0, it needs a reorder (+1).

## 3. Brute Force → Optimal
- **Brute:** try subsets of flips — exponential.
- **Optimal:** one DFS/BFS from 0 — O(n).

## 4. Data Structure / Approach Justification
**Chosen:** bidirectional adj with direction flag + DFS.

- **vs BFS:** same idea.

## 5. Logic Walkthrough
Add `u→v` with flag 1 and `v→u` with flag 0. DFS from 0; add flag when entering child.

## 6. Dry Run
Sample connections → **3** changes.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(n)**. Why: tree traversal (section 4).

## 8. Trade-offs & Alternatives
Root at 0 and count edges with wrong orientation via parent pointers.

## 9. Common Mistakes / Edge Cases
Counting both directions; not building reverse edges for traversal.

## 10. Interview Follow-ups / Variations
Make all reach any capital; weighted flip costs.

## 11. Tags
`dfs`, `tree`, `leetcode-1466`, `difficulty:medium`
