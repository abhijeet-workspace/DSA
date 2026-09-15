# Topological Sort (Kahn)

## 1. Problem Statement
Classic Kahn's algorithm: given a directed acyclic graph with `n` nodes `0..n-1` and edge list, return a topological ordering, or empty if a cycle exists.

- **Inputs:** `n`, directed `edges` `u→v` (u before v).
- **Output:** order vector or `{}` on cycle.
- **Valid answer:** any linear extension; all nodes iff DAG.
- **Edges:** empty edges; single node; cycle.

## 2. Intuition
Repeatedly take indegree-0 nodes (ready). Removing them decreases successors' indegrees — BFS layering of prerequisites.

## 3. Brute Force → Optimal
- **Brute:** try all permutations — n!.
- **Optimal:** Kahn O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** queue + indegree array + adjacency list.

- **vs DFS postorder topo:** also O(n+E); Kahn detects cycles via count.

## 5. Logic Walkthrough
Build graph/indegrees. Enqueue zeros. Pop u, append order, decrement neighbors; enqueue new zeros. If `|order|!=n`, cycle.

## 6. Dry Run
Edges `0→1,0→2,1→3,2→3` → e.g. `0 1 2 3` or `0 2 1 3`.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n+E)**. Why: each edge once (section 4).

## 8. Trade-offs & Alternatives
Priority queue yields lexicographically smallest topo.

## 9. Common Mistakes / Edge Cases
Forgetting cycle check; directed vs undirected; off-by-one n.

## 10. Interview Follow-ups / Variations
[Course Schedule II](https://leetcode.com/problems/course-schedule-ii/); alien dictionary; parallel courses.

## 11. Tags
`topological-sort`, `kahn`, `bfs`, `difficulty:medium`
