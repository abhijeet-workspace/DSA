# Branch and Bound (0/1 Knapsack)

## Problem Statement
Solve 0/1 knapsack by exploring an include/exclude decision tree, pruning branches whose **optimistic bound** cannot beat the best feasible profit found so far.

- **Inputs:** capacity `W`, items `(weight, value)`.
- **Output:** maximum achievable profit.
- **Edges:** `W=0`; single item; items heavier than `W`.

## Intuition
Backtracking tries all subsets. Branch-and-bound keeps a fractional-knapsack **upper bound** on each node; if bound ≤ current best, prune.

## Brute Force → Optimal
- **Brute / DP:** O(2^N) or O(N·W).
- **BnB:** still exponential worst case; often much faster with tight bounds.

## Data Structure / Approach Justification
**Chosen:** DFS/stack over decision nodes + value/weight density sort + fractional bound.

- **vs DP:** DP needs pseudo-polynomial `W`; BnB depends on pruning quality.
- Classic for TSP / knapsack optimization lectures.

## Logic Walkthrough
Sort by value/weight. From a node, branch include/exclude next item. Update `maxProfit` on feasible includes. Push children only if `bound > maxProfit`.

## Dry Run
`W=50`, items `(10,60),(20,100),(30,120)` → optimal profit **220** (20+30).

## Time & Space Complexity
Worst **O(2^N)**; space **O(N)** for the recursion/stack depth (plus frontier).

## Trade-offs & Alternatives
Prefer DP when `W` is moderate. Prefer BnB / ILP when bounds prune well or `W` is huge.

## Common Mistakes / Edge Cases
Using an inadmissible (too small) bound; forgetting to sort by density; not pruning on exclude branch.

## Interview Follow-ups / Variations
TSP branch-and-bound; best-first BnB with priority queue; comparison to meet-in-the-middle.

## Tags
`branch-and-bound`, `knapsack`, `pruning`, `optimization`, `difficulty:hard`
