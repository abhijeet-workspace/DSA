# Find if Path Exists in Graph

## 1. Problem Statement
[LeetCode 1971](https://leetcode.com/problems/find-if-path-exists-in-graph/) — bi-directional edges on `n` nodes `0..n-1`. Return whether a path from `source` to `destination` exists.

- **Inputs:** `n`, `edges`, `source`, `destination`.
- **Output:** bool.
- **Valid answer:** true iff same connected component.
- **Edges:** source==dest; disconnected; single edge.

## 2. Intuition
Build adjacency list; BFS/DFS/Union-Find from source; see if destination is reached.

## 3. Brute Force → Optimal
- **Brute:** DFS/BFS visit each vertex/edge once — optimal O(n+E).
- **UF:** also O(n+E α).

## 4. Data Structure / Approach Justification
**Chosen:** BFS on adjacency list.

- **vs DFS:** same complexity.
- **vs UF:** great if many queries; here one query.

## 5. Logic Walkthrough
Build undirected adj. BFS from source with visited; return true if dest dequeued/seen.

## 6. Dry Run
Triangle 0-1-2: 0→2 true. Two components: 0↛5 false.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n+E)**. Why: standard traversal (section 4).

## 8. Trade-offs & Alternatives
Recursive DFS is shorter; watch stack depth on large n.

## 9. Common Mistakes / Edge Cases
Forgetting undirected edges both ways; not handling source==destination.

## 10. Interview Follow-ups / Variations
Shortest path length; number of paths; directed version.

## 11. Tags
`graph`, `bfs`, `leetcode-1971`, `difficulty:easy`
