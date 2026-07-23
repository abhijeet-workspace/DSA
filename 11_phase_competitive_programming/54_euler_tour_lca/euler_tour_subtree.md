# Euler Tour Subtree

## Problem Statement
Rooted tree: assign enter/exit times; answer whether node `u` is in the subtree of node `v` (including `v` itself).

- **Inputs:** undirected tree edges, root (here `0`), query pairs `(u,v)`.
- **Output:** true iff `u` lies in subtree of `v`.
- **Valid answer:** interval nesting of DFS timestamps.
- **Edges:** `u==v` (true); root queries; leaves; forest needs per-component DFS.

## Intuition
DFS timestamps: `[in[v], out[v]]` is a contiguous segment containing exactly the subtree of `v`. Tree edges nest intervals.

## Brute Force → Optimal
- **Brute:** DFS from `v` searching for `u` — `O(N)` per query.
- **Optimal:** one DFS builds `in`/`out`; query is two comparisons — `O(1)`.

## Data Structure / Approach Justification
**Chosen:** enter+exit timer arrays from a single DFS.

- **vs binary lifting ancestors:** heavier for pure membership.
- **vs subtree size alone:** insufficient without order/timestamps.

## Logic Walkthrough
On enter set `in[u]=timer++`; recurse children; on exit set `out[u]=timer++`. Membership: `in[v] ≤ in[u] && out[u] ≤ out[v]`.

## Dry Run
Tree `0-1-3`, `0-2`:
- `3` in subtree of `1`? yes; `2` in subtree of `1`? no; `0` in subtree of `0`? yes.

## Time & Space Complexity
Preprocess **O(N)**; query **O(1)**. Space **O(N)**. Why: subtree ≡ nested time interval (section 4).

## Trade-offs & Alternatives
In/out is ideal for static trees and many subtree queries; rebuild if the tree restructures often.

## Common Mistakes / Edge Cases
Comparing only `in[]` without `out[]`; off-by-one on timer.

## Interview Follow-ups / Variations
Path queries via Euler + RMQ? Subtree updates?

## Tags
`euler-tour`, `dfs`, `subtree`, `timestamps`, `difficulty:easy`
