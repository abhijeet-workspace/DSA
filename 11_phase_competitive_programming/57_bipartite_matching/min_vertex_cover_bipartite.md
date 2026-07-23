# Min Vertex Cover (Bipartite)

## Problem Statement
König’s theorem (CP classic) — bipartite graph; find size (and a construction) of a minimum vertex cover that hits every edge.

- **Inputs:** bipartite edges left `0..nL-1` ↔ right `0..nR-1`.
- **Output:** cover size and labeled vertices (`L*`, `R*`).
- **Valid answer:** cover size equals max matching size.
- **Edges:** no edges (cover 0); perfect matching on `K_{n,n}` (cover n).

## Intuition
Max matching size = min vertex cover size on bipartite graphs. From unmatched left vertices, grow set Z by non-matching L→R then matching R→L; cover = `(L \ Z) ∪ (R ∩ Z)`.

## Brute Force → Optimal
- **Brute:** try all vertex subsets — exponential.
- **Optimal:** max matching + König labeling — same asymptotics as matching.

## Data Structure / Approach Justification
**Chosen:** Kuhn matching then BFS/queue Z-set construction.

- **vs max-flow / min-cut:** equivalent cut on the flow network; more setup.
- **vs size-only:** `|matching|` alone gives size; Z-set needed for the actual cover.

## Logic Walkthrough
Compute max matching. Seed Z with unmatched lefts. Expand via non-matching edges to right, then matching edges back to left. Emit `(L\Z) ∪ (R∩Z)`.

## Dry Run
3×2 example with matching size 2 ⇒ cover size 2; printed cover labels hit every edge.

## Time & Space Complexity
Time **O(V·E)** with Kuhn (+ O(V+E) for Z). Space **O(V+E)**. Why: König construction is a graph search on the matching.

## Trade-offs & Alternatives
Size alone needs only `|matching|`. Construction needs the alternating Z-set. Theorem fails on non-bipartite graphs.

## Common Mistakes / Edge Cases
Applying `|cover|=|matching|` off bipartite graphs; walking matching edges L→R when growing Z; 0-based indexing slips.

## Interview Follow-ups / Variations
Maximum independent set = `|V| − min vertex cover` (bipartite). Edge cover vs vertex cover?

## Tags
`bipartite`, `konig`, `vertex-cover`, `matching`, `difficulty:hard`
