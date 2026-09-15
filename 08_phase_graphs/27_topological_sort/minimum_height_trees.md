# Minimum Height Trees

## 1. Problem Statement
[LeetCode 310](https://leetcode.com/problems/minimum-height-trees/) — undirected tree with `n` nodes. Choose a root to minimize height. Return all such best roots (1 or 2 centroids).

- **Inputs:** `n`, `edges`.
- **Output:** list of root labels.
- **Valid answer:** tree centroid(s).
- **Edges:** n=1; line; star.

## 2. Intuition
Repeatedly trim leaves (indegree/degree 1) like Kahn peeling until ≤2 nodes remain — those are MHT roots.

## 3. Brute Force → Optimal
- **Brute:** height from every root O(n²).
- **Optimal:** leaf trimming O(n).

## 4. Data Structure / Approach Justification
**Chosen:** multi-source queue of leaves + degree counts.

- **vs two BFS diameters:** also finds centroids; trimming matches topo peeling teaching.

## 5. Logic Walkthrough
Init queue with degree-1 nodes. Peel layers until ≤2 nodes left; those are answers.

## 6. Dry Run
Star center 1 → `{1}`.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(n)**. Why: each edge trimmed once (section 4).

## 8. Trade-offs & Alternatives
Diameter midpoint method; rerooting DP heights.

## 9. Common Mistakes / Edge Cases
Stopping at 1 when 2 centroids; n=1; mutating degrees wrong.

## 10. Interview Follow-ups / Variations
Tree diameter; reroot DP; fire spreading from leaves.

## 11. Tags
`topological-sort`, `tree`, `bfs`, `leetcode-310`, `difficulty:medium`
