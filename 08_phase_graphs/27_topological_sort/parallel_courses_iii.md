# Parallel Courses III

## Problem Statement
[LeetCode 2050](https://leetcode.com/problems/parallel-courses-iii/) — `n` courses with durations and prerequisites; unlimited parallel enrollment; return min months to finish all.

- **Inputs:** `n`, `relations` `[prev, next]`, `time[0..n-1]`.
- **Output:** earliest finish month.
- **Valid answer:** DAG; finish time = max over courses of path duration sums.
- **Edges:** no relations; long chain; many parents.

## Intuition
Longest path in a DAG of course times; Kahn topo DP: `dist[v] = max(dist[v], dist[u] + time[v])`.

## Brute Force → Optimal
- **Brute:** DFS all paths — exponential.
- **Optimal:** topo DP — O(V+E).

## Data Structure / Approach Justification
**Chosen:** adjacency + indegree queue + dist array.

- **vs DFS memo longest path:** same complexity.

## Logic Walkthrough
Seed zero-indegree with their times; relax edges in topo order; answer max dist.

## Dry Run
Courses 1:3, 2:2, 3:5 with 1→3,2→3 → finish at max(3,2)+5 = 8.

## Time & Space Complexity
Time **O(V+E)**. Space **O(V+E)**.

## Trade-offs & Alternatives
DFS with memoization on DAG.

## Common Mistakes / Edge Cases
1-index courses; summing instead of max over parents; assuming serial.

## Interview Follow-ups / Variations
Course Schedule I/II; Parallel Courses I/II.

## Tags
`graph`, `topological-sort`, `dp`, `leetcode-2050`, `difficulty:hard`
