# Floyd vs Johnson Demo

## Problem Statement
Teaching comparison — on a tiny directed graph (negative edges allowed, no neg cycle), compute all-pairs distances with Floyd–Warshall and Johnson and confirm equality.

- **Inputs:** small edge list with one negative edge.
- **Output:** both distance matrices and an equality flag.
- **Valid answer:** corresponding entries match (including INF).
- **Edges:** INF unreachable; zero diagonals; single negative edge.

## Intuition
Both solve APSP. Floyd is dense/simple DP over intermediates. Johnson reweights then runs Dijkstra from each vertex; reweighting preserves path argmins.

## Brute Force → Optimal
- **Brute:** V×BFS only works for unit weights.
- **Pick:** Floyd for dense/tiny V; Johnson for sparse large V.

## Data Structure / Approach Justification
**Chosen:** dense matrix for Floyd; edge list + heap Dijkstra for Johnson on the same instance.

- **vs V×Bellman–Ford:** correct but slower teaching demo.
- **vs repeated Dijkstra if all ≥0:** skips potentials; fails with negatives.

## Logic Walkthrough
Build init matrix for Floyd. Run Johnson (BF potentials → Dijkstra → convert). Print both; compare entrywise.

## Dry Run
Edges `{0→1:4, 0→2:5, 1→2:−2, 1→3:3, 2→3:4}`: `johnson_ok=1`, printed matrices equal → `matrices_equal=1`.

## Time & Space Complexity
Floyd **O(V³)** time, **O(V²)** space. Johnson **O(VE + V E log V)** time, **O(V²)** for output. Why: different asymptotic regimes; same answers.

## Trade-offs & Alternatives
FW easier to code; Johnson scales better with sparsity. Complexity crossover: when is `V E log V` better than `V³`?

## Common Mistakes / Edge Cases
Comparing raw Johnson `d'` without converting back with `h[]`; treating INF inconsistently; negative cycles (both must fail/detect).

## Interview Follow-ups / Variations
When to pick which algorithm in interviews? Sparse road networks vs dense contest graphs (V≤400)?

## Tags
`floyd-warshall`, `johnson`, `apsp`, `comparison`, `difficulty:medium`
