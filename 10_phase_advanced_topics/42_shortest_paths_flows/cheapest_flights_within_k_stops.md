# Cheapest Flights Within K Stops

## Problem Statement
[LeetCode 787](https://leetcode.com/problems/cheapest-flights-within-k-stops/) — cheapest price from `src` to `dst` with at most `k` stops (≤ `k+1` flights).

- **Inputs:** `n` cities, `flights` as `[from,to,price]`, `src`, `dst`, `k`.
- **Output:** min cost, or `-1` if impossible.
- **Valid answer:** minimum among valid hop-limited paths.
- **Edges:** no path; `k=0` (direct only); cheaper longer routes.

## Intuition
Standard Dijkstra ignores hop limits. Run Bellman-Ford for exactly `k+1` rounds, copying distances each round so each round adds at most one edge.

## Brute Force → Optimal
- **Brute:** DFS/BFS all paths with ≤k stops — exponential.
- **Optimal:** hop-limited BF — O(K·E); Dijkstra on state `(node, stops)` — O(K·E log(KV)).

## Data Structure / Approach Justification
**Chosen:** distance array + per-round snapshot `nd`.

- **vs stateful Dijkstra:** similar; BF is short to code.
- **vs plain Dijkstra on prices:** wrong — may use too many stops.

## Logic Walkthrough
`dist[src]=0`. For `i=0..k`: start from previous `dist`, relax all flights into `nd`, swap. Return `dist[dst]` or `-1`.

## Dry Run
Flights `0→1 (100)`, `1→2 (100)`, `0→2 (500)`, `k=1`: after rounds, path `0-1-2` costs 200 beats direct 500.

## Time & Space Complexity
Time **O(K·E)**. Space **O(V)**. Why: `K+1` edge-list passes (section 4).

## Trade-offs & Alternatives
BF is simple; state-Dijkstra can prune earlier. Watch `INT_MAX` overflow if prices sum large — use long / cap adds.

## Common Mistakes / Edge Cases
In-place relax without snapshot (uses >k+1 edges); off-by-one on stops vs edges.

## Interview Follow-ups / Variations
At most K edges in general graphs; reconstruct path; negative prices (still BF-style).

## Tags
`graph`, `bellman-ford`, `shortest-path`, `leetcode-787`, `difficulty:medium`
