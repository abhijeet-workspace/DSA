# Cheapest Flights Within K Stops

## 1. Problem Statement
[LeetCode 787](https://leetcode.com/problems/cheapest-flights-within-k-stops/) — cheapest price from `src` to `dst` with at most `k` stops (≤ k+1 edges).

- **Inputs:** `n`, `flights` `[u,v,w]`, `src`, `dst`, `k`.
- **Output:** min cost or `-1`.
- **Edges:** unreachable; `k=0`.

## 2. Intuition
DP by edge count: after `i` relaxations, distances use ≤ i edges — Bellman–Ford layered.

## 3. Brute Force → Optimal
- **Brute:** DFS all paths with ≤k stops.
- **Optimal:** K+1 BF rounds — O(K·E).

## 4. Data Structure / Approach Justification
**Chosen:** array copy BF rounds (topo-like layers on path length).

| Alternative | Note |
|-------------|------|
| Dijkstra with (node,stops) | Also common |
| Plain Dijkstra | Wrong (ignores stop limit) |

## 5. Logic Walkthrough
For round in `0..k`: relax all edges into a new distance array from the previous.

## 6. Dry Run
LC sample → `700`.

## 7. Time & Space Complexity
Time **O(K·E)**. Space **O(V)**.

## 8. Trade-offs & Alternatives
Links topo/DP thinking to constrained shortest paths; also fits Johnson/APSP folder pedagogy.

## 9. Common Mistakes / Edge Cases
Relaxing in-place incorrectly allowing >k+1 edges; INF overflow.

## 10. Interview Follow-ups / Variations
At most k cost; maximize stops under budget.

## 11. Tags
`leetcode-787`, `bellman-ford`, `dp`, `shortest-path`, `difficulty:medium`
