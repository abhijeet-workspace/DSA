# Course Schedule IV

## 1. Problem Statement
[LeetCode 1462](https://leetcode.com/problems/course-schedule-iv/) — given prereq edges, answer queries whether `u` is a prerequisite of `v` (direct or indirect).

- **Inputs:** `numCourses`, `prerequisites`, `queries`.
- **Output:** bool per query.
- **Edges:** no path; direct edge.

## 2. Intuition
Transitive closure of the prereq DAG; Floyd–Warshall OR topo DP reachability sets.

## 3. Brute Force → Optimal
- **Brute:** BFS per query.
- **Optimal:** Floyd O(V³) or bitset topo O(V(V+E)/w).

## 4. Data Structure / Approach Justification
**Chosen:** Floyd reachability (clear for small V).

| Alternative | Note |
|-------------|------|
| Bitset DP in topo order | Faster practically |
| DFS cache per node | Fine |

## 5. Logic Walkthrough
Init direct edges; `reach[i][j] |= reach[i][k] && reach[k][j]`.

## 6. Dry Run
Prereqs make `1` reach `0` and `2` → queries true.

## 7. Time & Space Complexity
Time **O(V³ + Q)**. Space **O(V²)**.

## 8. Trade-offs & Alternatives
Topo DP with bitsets is the contest upgrade.

## 9. Common Mistakes / Edge Cases
Direction of prereq edge reversed; not closing transitively.

## 10. Interview Follow-ups / Variations
Count prereq chain length; dynamic edge adds.

## 11. Tags
`leetcode-1462`, `reachability`, `floyd`, `topological-dp`, `difficulty:medium`
