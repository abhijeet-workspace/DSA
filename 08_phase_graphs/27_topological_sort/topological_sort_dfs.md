# Topological Sort (DFS)

## 1. Problem Statement
Classic DFS topological sort: on a digraph, return nodes in order of decreasing finishing times (valid topo on DAGs), or empty if a cycle is found (3-color states).

- **Inputs:** `n`, directed edges `u→v`.
- **Output:** topo order or `{}`.
- **Valid answer:** reverse postorder if DAG.
- **Edges:** cycle detection; disconnected components.

## 2. Intuition
DFS postorder lists a node after all descendants. Reversing postorder yields a topo order. Gray node revisit ⇒ back-edge ⇒ cycle.

## 3. Brute Force → Optimal
- **Brute:** permutations.
- **Optimal:** DFS O(n+E) with WHITE/GRAY/BLACK.

## 4. Data Structure / Approach Justification
**Chosen:** recursion + state colors + reverse postorder.

- **vs Kahn:** DFS is natural when recursion is already used; Kahn uses queues.

## 5. Logic Walkthrough
For each unvisited node, DFS. On entry mark GRAY; recurse; mark BLACK and append. Reverse append list at end. Abort on GRAY neighbor.

## 6. Dry Run
Same diamond DAG as Kahn → valid order starting with `0` ending with `3`.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n+E)** (+ recursion). Why: each edge once (section 4).

## 8. Trade-offs & Alternatives
Iterative stack DFS; Kahn for lexicographic control with PQ.

## 9. Common Mistakes / Edge Cases
Forgetting reverse; using only visited bool (misses cycles); not covering all components.

## 10. Interview Follow-ups / Variations
[Course Schedule](https://leetcode.com/problems/course-schedule/); detect cycle only; build order.

## 11. Tags
`topological-sort`, `dfs`, `cycle-detection`, `difficulty:medium`
