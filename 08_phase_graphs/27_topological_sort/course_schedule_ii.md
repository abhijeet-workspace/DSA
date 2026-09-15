# Course Schedule II

## 1. Problem Statement
[LeetCode 210](https://leetcode.com/problems/course-schedule-ii/) — return any valid order to finish all courses, or empty if impossible.

- **Inputs:** `int numCourses`, `vector<vector<int>> prerequisites` (`[a,b]` ⇒ take `b` before `a`).
- **Output:** `vector<int>` of length `n`, or `{}`.
- **Valid answer:** any topo order of the DAG.
- **Edges:** empty prereqs; cycle; multiple valid orders; disconnected courses.

## 2. Intuition
Same as Course Schedule I: Kahn BFS. Record the pop sequence as the answer; if size &lt; n, a cycle exists.

## 3. Brute Force → Optimal
- **Brute:** enumerate permutations — exponential.
- **Optimal:** Kahn BFS or DFS finishing times reversed — O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** adjacency list + indegree + queue, appending each popped node to `order`.

- **vs DFS postorder reverse:** identical correctness; BFS order depends on enqueue order.
- **vs priority queue:** only needed for lex-smallest order.

## 5. Logic Walkthrough
Edges `b→a`. Seed indegree-0. Pop → append to `order` → decrement neighbors. Return `order` iff size equals `numCourses`.

## 6. Dry Run
`n=4`, `[[1,0],[2,0],[3,1],[3,2]]`: start with `0`, then `1`/`2`, then `3` → e.g. `0 1 2 3` or `0 2 1 3`.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**. Why: standard topo sort over the prereq graph (section 4).

## 8. Trade-offs & Alternatives
Any valid order is accepted. Min-heap of ready courses yields lex-smallest. DFS reverse-postorder is a common alternate.

## 9. Common Mistakes / Edge Cases
Returning a partial order on cycles; wrong edge direction; forgetting isolated courses still belong in the order.

## 10. Interview Follow-ups / Variations
Lex-smallest order. Minimum semesters with parallelism. Detect which edges cause the cycle.

## 11. Tags
`graph`, `topological-sort`, `kahn`, `leetcode-210`, `difficulty:medium`
