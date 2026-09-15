# Course Schedule

## 1. Problem Statement
[LeetCode 207](https://leetcode.com/problems/course-schedule/) — return whether you can finish all `numCourses` given prereqs `[a,b]` meaning take `b` before `a`.

- **Inputs:** `int numCourses`, `vector<vector<int>> prerequisites`.
- **Output:** `bool`.
- **Valid answer:** true iff the directed prereq graph is acyclic.
- **Edges:** no prereqs; self-loop; disconnected components; mutual cycle.

## 2. Intuition
Model `b → a` (b before a). A cycle means circular dependency. Kahn BFS finishes every node iff the graph is a DAG.

## 3. Brute Force → Optimal
- **Brute / DFS:** 3-color DFS detecting back-edges — also O(V+E).
- **Optimal:** indegree + queue (Kahn) — O(V+E), easy to extend to return an order.

## 4. Data Structure / Approach Justification
**Chosen:** adjacency list + indegree array + BFS queue.

- **vs DFS coloring:** same complexity; Kahn’s `taken == n` check is interview-clear.
- **vs trying all orders:** exponential and unnecessary.

## 5. Logic Walkthrough
Build edges `b→a` and indegrees. Push all indegree-0 courses. While queue non-empty, take one, decrement neighbors, enqueue zeros. Return `taken == numCourses`.

## 6. Dry Run
`n=2`, `[[1,0]]`: edge `0→1`, take 0 then 1 → true.  
`[[1,0],[0,1]]`: cycle → neither finishes → false.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**. Why: each vertex/edge processed a constant number of times (section 4).

## 8. Trade-offs & Alternatives
Prefer Kahn when you may later return the order (210). Prefer DFS if recursion/stack coloring is more natural for the team.

## 9. Common Mistakes / Edge Cases
Reversing edge direction; treating undirected; counting only one component; missing that empty prereqs → true.

## 10. Interview Follow-ups / Variations
Return any order (210). Lex-smallest order. Count number of valid orders. Parallel semesters (min terms).

## 11. Tags
`graph`, `topological-sort`, `kahn`, `cycle-detection`, `leetcode-207`, `difficulty:medium`
