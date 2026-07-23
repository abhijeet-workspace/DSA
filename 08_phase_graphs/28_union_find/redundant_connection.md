# Redundant Connection

## Problem Statement
[LeetCode 684](https://leetcode.com/problems/redundant-connection/) — a tree of `n` nodes plus one extra edge; return the edge that can be removed to restore a tree (last such edge in input order).

- **Inputs:** `vector<vector<int>> edges` (1-indexed nodes, `n == edges.size()`).
- **Output:** the redundant edge `[u,v]`.
- **Valid answer:** the last edge in the list that closes a cycle.
- **Edges:** cycle early vs late; path that later chords; `n` small.

## Intuition
Process edges in order with DSU. The first edge whose endpoints already share a parent closes a cycle — that is the answer.

## Brute Force → Optimal
- **Brute:** for each edge, DFS the rest for connectivity — O(N·E).
- **Optimal:** single DSU pass — O(N α(N)).

## Data Structure / Approach Justification
**Chosen:** Union-Find with path compression + union by rank.

- **vs DFS per edge:** same answer, worse complexity.
- **vs building adj then finding any cycle edge:** harder to respect “last in input” rule.

## Logic Walkthrough
`DSU(n+1)`. For each edge, if `unite` fails, return that edge. Otherwise continue.

## Dry Run
Edges `1-2`, `2-3`, `3-4`, `1-4`, `1-5`: when adding `1-4`, 1 and 4 already connected via the path → return `[1,4]`.

## Time & Space Complexity
Time **O(N α(N))**. Space **O(N)**. Why: one nearly-constant DSU op per edge (section 4).

## Trade-offs & Alternatives
DSU naturally returns the last cycle-forming edge in input order. For undirected critical edges generally, use Tarjan bridges instead.

## Common Mistakes / Edge Cases
0-indexing the DSU; returning the first edge of the cycle rather than the closing one; directed-graph confusion.

## Interview Follow-ups / Variations
Redundant Connection II (directed). Return any removable edge. Find all bridges.

## Tags
`union-find`, `cycle-detection`, `tree`, `leetcode-684`, `difficulty:medium`
