# Sparse APSP: Johnson vs Floyd

## 1. Problem Statement
Teaching lab — decide Floyd vs Johnson using a simple operation-count heuristic on `(V,E)`.

- **Inputs:** illustrative `V,E` pairs in `main`.
- **Output:** preferred algorithm label.
- **Edges:** tiny dense; large sparse.

## 2. Intuition
Floyd always Θ(V³). Johnson ~ VE + V·(E log V). Sparse large V favors Johnson.

## 3. Brute Force → Optimal
- **Always Floyd:** simple, may TLE.
- **Heuristic pick:** match graph shape.

## 4. Data Structure / Approach Justification
**Chosen:** compare crude op counts (pedagogy, not a benchmark harness).

| Alternative | Note |
|-------------|------|
| Wall-clock microbench | See `floyd_vs_johnson_demo` |

## 5. Logic Walkthrough
Compute both estimates; print preference.

## 6. Dry Run
`V=1000,E=3000` → Johnson; `V=50,E=2500` → Floyd.

## 7. Time & Space Complexity
Time **O(1)** for the decision lab.

## 8. Trade-offs & Alternatives
Pairs with the timed demo file already in this folder.

## 9. Common Mistakes / Edge Cases
Ignoring log factors; negative edges forcing Johnson/BF.

## 10. Interview Follow-ups / Variations
Add real timing on random graphs.

## 11. Tags
`johnson`, `floyd`, `complexity`, `teaching`, `difficulty:easy`
