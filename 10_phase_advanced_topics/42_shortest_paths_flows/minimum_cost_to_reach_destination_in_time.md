# Minimum Cost to Reach Destination in Time

## Problem Statement
[LeetCode 1928](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/) — undirected roads with travel times; each city has a `passingFee` charged on visit (including start). Minimize total fees to reach `n-1` from `0` in at most `maxTime`.

- **Inputs:** `maxTime`, `edges` `[u,v,time]`, `passingFee`.
- **Output:** min fee, or `-1`.
- **Valid answer:** minimum fee among all paths with total time ≤ `maxTime`.
- **Edges:** tight time; expensive short path vs cheap long path; unreachable.

## Intuition
Two costs: time (budget) and fee (optimize). Dijkstra on state `(node, time_used)` minimizing fee. First time you pop destination is optimal fee (min-heap on fee).

## Brute Force → Optimal
- **Brute:** DFS all paths under time — exponential.
- **Optimal:** state Dijkstra / DP — **O((n·T + E·T) log (n·T))** heap, or DP relax **O(E·T)**.

## Data Structure / Approach Justification
**Chosen:** `dist[u][t]` min fee + fee-min heap.

- **vs DP Bellman-style over time:** also correct, often simpler loops.
- **vs Dijkstra on fee ignoring time:** may exceed `maxTime`.

## Logic Walkthrough
`dist[0][0]=passingFee[0]`. Pop `(fee,time,u)`; if `u==n-1` return. Else try edges with `nt=time+w≤maxTime`, `nf=fee+passingFee[v]`, relax `dist[v][nt]`.

## Dry Run
Fees `[5,1,2,20,20,3]`: `maxTime=30` → path `0-1-2-5` fee `11`; `29` → `0-3-4-5` fee `48`; `25` → impossible `-1`.

## Time & Space Complexity
Time **O(E·T log(n·T))** heap. Space **O(n·T)**. Why: states are `(node,time)` (section 4).

## Trade-offs & Alternatives
DP: for increasing time, relax all edges — no heap. Prune Pareto states per node (min fee for each time) — same as `dist[u][t]`.

## Common Mistakes / Edge Cases
Not charging start fee; charging fee twice per city; using only best-fee-per-node without time dimension (loses alternate states).

## Interview Follow-ups / Variations
Cheapest flights within K stops; constrained shortest path; multi-objective Pareto.

## Tags
`graph`, `dijkstra`, `dp`, `shortest-path`, `leetcode-1928`, `difficulty:hard`
