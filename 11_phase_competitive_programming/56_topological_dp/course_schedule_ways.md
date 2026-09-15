# Course Schedule Ways

## 1. Problem Statement
Related to LeetCode 207/210; ways variant is CP-style DP — courses `0..n-1` with directed edges `u→v` (“u before v”). Count distinct paths from sources to a designated sink.

- **Inputs:** DAG adjacency list, sink index.
- **Output:** number of paths reaching the sink (sources seeded with 1).
- **Valid answer:** sum of independent incoming path counts.
- **Edges:** multiple sources; unreachable sink (0); diamond DAG.

## 2. Intuition
`ways[v] = sum of ways[u]` over edges `u→v`; seed indegree-0 nodes with 1; process in Kahn topo order.

## 3. Brute Force → Optimal
- **Brute:** DFS enumerate all paths — exponential.
- **Optimal:** topological DP — O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn queue + `ways[]` accumulation.

- **vs recursion + memo from sink:** same asymptotics; forward topo matches “prereq → course”.
- **vs adjacency-matrix powers:** overkill for sparse DAGs.

## 5. Logic Walkthrough
Compute indegrees; enqueue sources with `ways=1`. Pop `u`, add `ways[u]` into each successor `v`; when `indeg[v]` hits 0, enqueue. Return `ways[sink]`.

## 6. Dry Run
`0→2`, `1→2`, `2→3`: `ways[3] = ways[2] = ways[0]+ways[1] = 2`. Diamond `0→1,0→2,1→3,2→3` → also 2 ways to 3.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V)** for indeg/ways/queue (+ graph). Why: each edge relaxes once in topo order.

## 8. Trade-offs & Alternatives
Forward topo is natural for prereq chains; memoized DFS for sparse single-sink queries. Modulo `10^9+7` in contests.

## 9. Common Mistakes / Edge Cases
Multiplying instead of summing incoming ways; counting topological orders (different problem); cycles (not a DAG).

## 10. Interview Follow-ups / Variations
Mod `10^9+7`; count number of topological orders; ways with length constraints.

## 11. Tags
`dag`, `topological-dp`, `path-counting`, `kahn`, `difficulty:medium`
