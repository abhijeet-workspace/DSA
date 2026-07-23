# Segment Tree with Lazy Propagation

## Problem Statement
Support **range add** updates and **range sum** queries on an array in O(log N) per operation.

- **Inputs:** initial `arr`; `updateRange(l, r, val)` adds `val` to every index in `[l..r]`; `queryRange(l, r)`.
- **Output:** sum over `[l..r]` after updates.
- **Valid answer:** exact sum (can go negative).
- **Edges:** full-array update; single index; overlapping then nested ranges; empty array.

## Intuition
Without laziness, range add would touch O(N) leaves. Lazy tags defer work: when a node is fully inside the update range, apply the add to that node’s sum and stash `val` for children; push only when you must go deeper.

## Brute Force → Optimal
- **Brute:** loop `[l..r]` on each update — O(N) update, O(N) query (or prefix rebuild).
- **Plain segtree:** O(N) range update if you touch every leaf.
- **Optimal:** lazy segtree — O(log N) range update and query.

## Data Structure / Approach Justification
**Chosen:** 0-based tree (`2*node+1`, `2*node+2`) with parallel `lazy[]`.

- **vs difference array + Fenwick:** great for range add + point/prefix query; less natural for arbitrary range sum after mixed ops without care.
- **vs sqrt decomposition:** simpler constants sometimes; weaker asymptotics / interview clarity.

## Logic Walkthrough
`push`: add `(len)*lazy` to `tree[node]`, propagate to children, clear. Update: push, exit if no overlap, set lazy+push on full cover, else recurse and rebuild parent. Query: push, then same no/full/partial cases.

## Dry Run
`arr={1,3,5,7,9,11}`:
- `query(1,3)` → 3+5+7 = **15**; `query(0,5)` → **36**
- `update(1,5,+10)` → `{1,13,15,17,19,21}`; `query(1,3)` → **45**; full → **86**
- `update(0,2,-5)` → `{-4,8,10,17,19,21}`; `query(0,2)` → **14**; full → **71**

## Time & Space Complexity
Build **O(N)**; update/query **O(log N)**; space **O(N)** for `tree` + `lazy`. Why: each op visits O(log N) nodes and pushes at most once per visit (section 4).

## Trade-offs & Alternatives
Lazy is the standard for range updates. Prefer Fenwick/diff when only range-add + prefix queries. For assignment (set range to x), use overwrite lazy with a “has pending set” flag.

## Common Mistakes / Edge Cases
Forgetting to push before reading/splitting; applying lazy length wrong (`end-start+1`); not clearing lazy after push; mixing 0-based vs 1-based child indexing.

## Interview Follow-ups / Variations
Range assign; range min + range add; persistent segtree; Beats (Chtholly) for special range ops.

## Tags
`segment-tree`, `lazy-propagation`, `range-update`, `range-sum`, `difficulty:hard`
