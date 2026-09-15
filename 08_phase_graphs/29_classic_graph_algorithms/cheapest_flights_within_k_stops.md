# Cheapest Flights Within K Stops

## 1. Problem Statement
[LeetCode 787](https://leetcode.com/problems/cheapest-flights-within-k-stops/) — `n` cities, flights `[from,to,price]`. Cheapest price from `src` to `dst` with at most `k` stops (≤ k+1 edges). Return `-1` if impossible.

- **Inputs:** `n`, `flights`, `src`, `dst`, `k`.
- **Output:** min price or -1.
- **Valid answer:** Bellman-Ford limited to k+1 relaxations.
- **Edges:** k=0 direct only; cycles with cheaper long paths disallowed by k.

## 2. Intuition
Standard shortest path with hop limit: relax all edges for `k+1` rounds using a temp distance array (Bellman-Ford layering).

## 3. Brute Force → Optimal
- **Brute:** DFS all paths with ≤k stops.
- **Optimal:** Bellman-Ford O(k·E) or Dijkstra on state (node,stops).

## 4. Data Structure / Approach Justification
**Chosen:** Bellman-Ford with `next` copy per iteration.

- **vs Dijkstra+(node,hops):** also common.
- **vs plain Dijkstra on city only:** wrong (may use too many stops).

## 5. Logic Walkthrough
dist[src]=0. Repeat k+1 times: relax every flight into `next` from previous `dist`.

## 6. Dry Run
Sample src0→dst3 with k=1 → **700**.

## 7. Time & Space Complexity
Time **O(k·E)**. Space **O(n)**. Why: limited BF (section 4).

## 8. Trade-offs & Alternatives
Priority-queue Dijkstra on (cost, node, stops).

## 9. Common Mistakes / Edge Cases
Relaxing in-place within a round (mixes hop counts); off-by-one on stops vs edges.

## 10. Interview Follow-ups / Variations
Network delay time; constrained shortest path.

## 11. Tags
`bellman-ford`, `shortest-path`, `leetcode-787`, `difficulty:medium`
