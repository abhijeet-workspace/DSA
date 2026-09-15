# Path with Maximum Probability

## Problem Statement
[LeetCode 1514](https://leetcode.com/problems/path-with-maximum-probability/) — undirected graph with edge success probabilities; maximize the product of probabilities on a path from `start` to `end`.

- **Inputs:** `n`, `edges`, `succProb`, `start`, `end`.
- **Output:** max probability (double), or `0` if unreachable.
- **Valid answer:** maximum product along any path.
- **Edges:** disconnected; single edge; many tiny products.

## Intuition
“Longest” path under multiplicative weights with values in `(0,1]`. Dijkstra with a max-heap on probability (or min-heap on `-log(p)`) works because products are monotonic nonincreasing along extensions.

## Brute Force → Optimal
- **Brute:** enumerate paths — exponential.
- **Optimal:** Dijkstra on max product — **O((V+E) log V)**.

## Data Structure / Approach Justification
**Chosen:** max-heap Dijkstra storing best probability per node.

- **vs Bellman-Ford:** O(VE); fine but slower.
- **vs BFS:** wrong — edges are weighted (by probability).

## Logic Walkthrough
`best[start]=1`. Pop highest `prob`; relax `np = prob * w` if improves `best[v]`. Early return when popping `end`.

## Dry Run
Edges `0-1 (0.5)`, `1-2 (0.5)`, `0-2 (0.2)`: path `0-1-2` product `0.25` beats direct `0.2`.

## Time & Space Complexity
Time **O((V+E) log V)**. Space **O(V+E)**. Why: binary heap Dijkstra (section 4).

## Trade-offs & Alternatives
Use `-log(p)` and standard min Dijkstra to avoid float underflow on long paths.

## Common Mistakes / Edge Cases
Min-heap without negating; adding probabilities; treating as unweighted.

## Interview Follow-ups / Variations
Minimize product; maximize sum of logs; constrained hops.

## Tags
`graph`, `dijkstra`, `shortest-path`, `leetcode-1514`, `difficulty:medium`
