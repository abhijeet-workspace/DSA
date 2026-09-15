# Parallel Courses III

## 1. Problem Statement
[LeetCode 2050](https://leetcode.com/problems/parallel-courses-iii/) — courses `1..n` with durations and prereq edges; compute minimum months to finish all (unlimited parallelism).

- **Inputs:** `n`, `relations`, `time[]`.
- **Output:** minimum total months.
- **Edges:** no relations; long chain.

## 2. Intuition
`dist[v] = time[v] + max dist[u]` over prereqs `u→v`; answer is max `dist`.

## 3. Brute Force → Optimal
- **Brute:** simulate month-by-month.
- **Optimal:** topo DP — O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn + critical-path DP.

| Alternative | Note |
|-------------|------|
| DFS memo | Same |
| LC 1136 month layers | Different (unit time, count semesters) |

## 5. Logic Walkthrough
Seed sources with their time; relax successors with max arrival; track global max.

## 6. Dry Run
`time=[3,2,5]`, edges to 3 → answer `8`.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Same as weighted DAG longest path / project critical path.

## 9. Common Mistakes / Edge Cases
1-based course ids vs 0-based `time`; summing instead of max.

## 10. Interview Follow-ups / Variations
Limited parallelism; reconstruct schedule.

## 11. Tags
`leetcode-2050`, `topological-dp`, `critical-path`, `difficulty:hard`
