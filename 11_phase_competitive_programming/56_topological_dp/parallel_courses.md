# Parallel Courses

## 1. Problem Statement
[LeetCode 1136](https://leetcode.com/problems/parallel-courses/) (premium) — minimum semesters to take all courses with prereqs; any number of courses per semester if prereqs done. Return `-1` on cycle.

- **Inputs:** `n`, `relations` (`prev → next`).
- **Output:** semester count or `-1`.
- **Edges:** empty relations → 1; cycle.

## 2. Intuition
Layered Kahn: each layer is one semester of all currently zero-indegree courses.

## 3. Brute Force → Optimal
- **Brute:** try subsets.
- **Optimal:** BFS topo layers — O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** layered Kahn BFS.

| Alternative | Note |
|-------------|------|
| LC 2050 | Durations differ; use longest-path DP |
| DFS cycle + depth | Also fine |

## 5. Logic Walkthrough
While queue nonempty: process entire queue as one semester; enqueue newly unlocked.

## 6. Dry Run
Two prereqs into 3 → `2` semesters; cycle → `-1`.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Unit-time special case of parallel courses III.

## 9. Common Mistakes / Edge Cases
Not processing by layers (would count courses not semesters).

## 10. Interview Follow-ups / Variations
Limit of k courses per semester.

## 11. Tags
`leetcode-1136`, `topological-sort`, `bfs-layers`, `difficulty:medium`
