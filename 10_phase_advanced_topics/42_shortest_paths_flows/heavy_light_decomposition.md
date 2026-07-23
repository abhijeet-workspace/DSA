# Heavy-Light Decomposition

## Problem Statement
Support path aggregates (here: path sum) on a tree by decomposing into heavy/light chains and querying contiguous segments.

- **Inputs:** tree edges, node values, path endpoints `(a,b)`.
- **Output:** sum of node values on the unique path.
- **Valid answer:** exact path sum.
- **Edges:** skew trees; path through root; `a==b`.

## Intuition
Heavy edge goes to the largest subtree. Any root path crosses O(log N) light edges, so it breaks into O(log N) contiguous chains mappable to a Fenwick/segment tree.

## Brute Force → Optimal
- **Brute:** climb to LCA adding values — O(N) per query.
- **Optimal:** HLD + BIT/segTree — O(log² N) path queries/updates.

## Data Structure / Approach Justification
**Chosen:** HLD chains + Fenwick on discovery `pos`.

- **vs binary lifting alone:** LCA/distance only, not arbitrary path sums with updates.
- **vs centroid decomposition:** different problem family (subtree/path distance counts).

## Logic Walkthrough
DFS sizes → mark heavy child → decompose chains → place values at `pos[v]`. Path query: while heads differ, add deeper head→node range, jump to parent of head; finally add in-chain range.

## Dry Run
Values `{1,2,3,4}` on `0-1-3`, `0-2`. Path `3→2`: 4+2+1+3=10.

## Time & Space Complexity
Build **O(N)**. Query/update **O(log² N)**. Space **O(N)**. Why: O(log N) chains × O(log N) BIT (section 4).

## Trade-offs & Alternatives
Heavy machinery; rare in FAANG, common in CP path updates. For static path max, sometimes binary lifting + sparse tables suffice.

## Common Mistakes / Edge Cases
Not lifting the deeper head first; off-by-one in BIT ranges; forgetting light-child starts.

## Interview Follow-ups / Variations
Edge vs node values; path max with segtree; subtree queries via DFS order.

## Tags
`tree`, `hld`, `fenwick`, `path-query`, `difficulty:hard`
