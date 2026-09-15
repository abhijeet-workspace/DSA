# Possible Bipartition

## 1. Problem Statement
[LeetCode 886](https://leetcode.com/problems/possible-bipartition/) — split `n` people into two groups so every dislike pair is separated (graph bipartiteness).

- **Inputs:** `n`, `dislikes` edges.
- **Output:** true/false.
- **Edges:** empty dislikes; triangle.

## 2. Intuition
Same as bipartite check on the dislike graph.

## 3. Brute Force → Optimal
- **Brute:** assign groups 2^n.
- **Optimal:** BFS 2-color O(n+e).

## 4. Data Structure / Approach Justification
**Chosen:** BFS coloring on dislike graph.

| Alternative | Note |
|-------------|------|
| LC 785 | Identical core |

## 5. Logic Walkthrough
Build undirected dislike graph; 2-color each component.

## 6. Dry Run
Path of dislikes → true; triangle → false.

## 7. Time & Space Complexity
Time **O(n+e)**. Space **O(n+e)**.

## 8. Trade-offs & Alternatives
Social-graph framing of bipartiteness before matching.

## 9. Common Mistakes / Edge Cases
1-based people ids; directed dislike mishandling.

## 10. Interview Follow-ups / Variations
Minimum edges to remove to make bipartite.

## 11. Tags
`leetcode-886`, `bipartite`, `graph-coloring`, `difficulty:medium`
