# Course Schedule

## Problem Statement
[LeetCode 207](https://leetcode.com/problems/course-schedule/) — return whether you can finish all `numCourses` given prereqs `[a,b]` meaning take `b` before `a`.

- **Inputs:** `int numCourses`, `vector<vector<int>> prerequisites`.
- **Output:** `bool`.
- **Valid answer:** true iff the directed prereq graph is acyclic.
- **Edges:** no prereqs; self-loop; disconnected components; mutual cycle.

## Intuition
Model `b → a` (b before a). A cycle means circular dependency. Kahn BFS finishes every node iff the graph is a DAG.

## Brute Force → Optimal
- **Brute / DFS:** 3-color DFS detecting back-edges — also O(V+E).
- **Optimal:** indegree + queue (Kahn) — O(V+E), easy to extend to return an order.

## Data Structure / Approach Justification
**Chosen:** adjacency list + indegree array + BFS queue.

- **vs DFS coloring:** same complexity; Kahn’s `taken == n` check is interview-clear.
- **vs trying all orders:** exponential and unnecessary.

## Logic Walkthrough
Build edges `b→a` and indegrees. Push all indegree-0 courses. While queue non-empty, take one, decrement neighbors, enqueue zeros. Return `taken == numCourses`.

## Dry Run
`n=2`, `[[1,0]]`: edge `0→1`, take 0 then 1 → true.  
`[[1,0],[0,1]]`: cycle → neither finishes → false.

## Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**. Why: each vertex/edge processed a constant number of times (section 4).

## Trade-offs & Alternatives
Prefer Kahn when you may later return the order (210). Prefer DFS if recursion/stack coloring is more natural for the team.

## Common Mistakes / Edge Cases
Reversing edge direction; treating undirected; counting only one component; missing that empty prereqs → true.

## Interview Follow-ups / Variations
Return any order (210). Lex-smallest order. Count number of valid orders. Parallel semesters (min terms).

## Tags
`graph`, `topological-sort`, `kahn`, `cycle-detection`, `leetcode-207`, `difficulty:medium`
