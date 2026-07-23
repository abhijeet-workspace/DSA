# Kuhn Maximum Matching

## Problem Statement
CP classic — left nodes `1..nL`, right `1..nR`; undirected bipartite edges; return maximum matching size.

- **Inputs:** bipartite adjacency from left to right.
- **Output:** size of a maximum matching.
- **Valid answer:** number of matched right vertices.
- **Edges:** empty side; isolated vertices; sparse vs dense.

## Intuition
From each left vertex, DFS seeking an augmenting path: take a free right, or reassign its current match via an alternating path (Berge).

## Brute Force → Optimal
- **Brute:** try all assignments — exponential.
- **Optimal:** Kuhn O(VE) DFS augmentations from free lefts.

## Data Structure / Approach Justification
**Chosen:** `mt[right]=left` matching array + per-attempt visit stamp.

- **vs Hopcroft–Karp:** same answer, O(E√V) — use when V is large.
- **vs max-flow:** correct but heavier boilerplate for unit bipartite graphs.

## Logic Walkthrough
For each left `v`, bump `timer` and `tryKuhn(v)`: mark visited, try each right; if free or `tryKuhn(mt[to])` succeeds, assign `mt[to]=v`.

## Dry Run
Edges `1-1`, `1-2`, `2-2` → matching size `2` (e.g. 1↔1, 2↔2 or 1↔2 after reassign).

## Time & Space Complexity
Time **O(V·E)** worst case. Space **O(V+E)** for graph and match arrays. Why: up to V augmentations, each O(E) DFS.

## Trade-offs & Alternatives
Simple for contests with V≤500–1k. Prefer Hopcroft–Karp or Dinic for larger dense bipartite graphs.

## Common Mistakes / Edge Cases
Not clearing/refreshing `vis` each left attempt; 0-based/1-based mixups; forgetting unmatched rights stay `-1`.

## Interview Follow-ups / Variations
Recover the actual pairs? Minimum vertex cover via König? Min-cost matching?

## Tags
`bipartite`, `matching`, `kuhn`, `augmenting-path`, `difficulty:medium`
