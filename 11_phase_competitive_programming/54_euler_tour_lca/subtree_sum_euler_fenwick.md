# Subtree Sum Euler Fenwick

## Problem Statement
Assign a value to each node; answer sum of values in the subtree of `u` (including `u`), with optional point updates.

- **Inputs:** rooted tree, node values, subtree queries / point updates.
- **Output:** subtree aggregate as `long long`.
- **Valid answer:** sum of values on nodes in `subtree(u)`.
- **Edges:** leaf; update then query; negatives; root subtree = total.

## Intuition
Map `subtree(u)` to contiguous indices `[in[u], out[u]]` on a flattened array (enter-only timing). Fenwick range-sum answers aggregates; point add supports updates.

## Brute Force → Optimal
- **Brute:** DFS sum per query — `O(N)` each.
- **Optimal:** one DFS for in/out; place value at `in[u]`; query `sum(in[u]..out[u])` — `O(log N)`.

## Data Structure / Approach Justification
**Chosen:** enter-only Euler + Fenwick (1-based).

- **vs SegTree on Euler:** same idea; Fenwick is lighter for point update / range sum.
- **vs HLD:** needed when mixing path + subtree ops heavily.

## Logic Walkthrough
DFS: `in[u]=timer++`, children, `out[u]=timer-1`. `fw.add(in[u], val[u])`. Subtree sum = `sumRange(in[u], out[u])`.

## Dry Run
Values `[5,1,2,3]` on `0-1-3`, `0-2`:
- `subtree(1)=4`, `subtree(0)=11`; after `+7` on node 3, `subtree(1)=11`.

## Time & Space Complexity
Build/queries **O(N log N)** total typical. Space **O(N)**. Why: Euler intervals nest as subtrees; Fenwick preserves range sums (section 4).

## Trade-offs & Alternatives
Enter+exit dual slots need care (put value only at enter). Enter-only timing is cleaner for contiguous blocks.

## Common Mistakes / Edge Cases
Writing value at both in and out; wrong bounds; 0-based vs 1-based Fenwick indices.

## Interview Follow-ups / Variations
Path sum `u→v` via Euler + LCA? Subtree add (range update)?

## Tags
`euler-tour`, `fenwick`, `subtree-sum`, `tree`, `difficulty:medium`
