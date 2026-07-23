# Difference Array

## Problem Statement
Support many range-add updates `[l,r] += val`, then read the final array (or scan the reconstructed values).

Technique used in booking / car-pooling style problems (no single LC “difference array” problem).

**Inputs:** initial array (often zeros), updates `(l, r, val)`.  
**Valid answer:** array after all updates applied.  
**Edges:** whole-array update; `r = n-1` (no `diff[r+1]`); empty.

## Intuition
Instead of touching every index in a range, mark “+val starts here” and “−val starts after the range.” Prefix-summing those marks restores the array.

## Brute Force → Optimal
- **Brute:** for each update, loop `[l..r]` adding `val` — O(N) per update.
- **Optimal:** O(1) per update via deltas; O(N) once to materialize.

## Data Structure / Approach Justification (REQUIRED)
Difference / delta array `diff` of size `N+1`.
- **vs segment tree / Fenwick (range update, point query):** more general for interleaved reads/writes; heavier for offline batch updates.
- **vs naive loop:** loses when update count is large.

## Logic Walkthrough
`update`: `diff[l]+=val`, `diff[r+1]-=val`. `getArray`: prefix-sum `diff` into `result`.

## Dry Run
Zeros length 5; `+2` on `[1,3]`; `+3` on `[2,4]` → `[0,2,5,5,3]`.

## Time & Space Complexity
Update **O(1)**, reconstruct **O(N)**, space **O(N)**. Why: each update only touches two delta slots (section 4).

## Trade-offs & Alternatives
Ideal for offline batch updates. Interleaved random reads mid-stream favor trees or event sweeps.

## Common Mistakes / Edge Cases
Forgetting `-=` at `r+1`; wrong bounds when `r+1 == n` (guard or size `n+1`).

## Interview Follow-ups / Variations
2D difference array for submatrix updates? Event-sort sweep when coordinate space is sparse.

## Tags
`difference-array`, `prefix-sum`, `range-update`, `medium`
