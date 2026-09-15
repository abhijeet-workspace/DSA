# Remove Max Number of Edges to Keep Graph Fully Traversable

## 1. Problem Statement
[LeetCode 1579](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/) — edges typed `1` (Alice), `2` (Bob), `3` (both). Maximize deleted edges so both can still traverse all `n` nodes. Return `-1` if impossible.

- **Inputs:** `n`, `edges` as `[type,u,v]` (1-indexed nodes).
- **Output:** max removable count, or `-1`.
- **Valid answer:** `|E| -` minimum edges needed in a valid spanning structure.
- **Edges:** missing connectivity for one person; only type-3; dense graphs.

## 2. Intuition
Build spanning forests greedily: use type-3 first (helps both), then type-1 for Alice and type-2 for Bob. Every edge that does not unite is removable.

## 3. Brute Force → Optimal
- **Brute:** subset search — exponential.
- **Optimal:** dual DSU, type-3 first — **O(e α(n))**.

## 4. Data Structure / Approach Justification
**Chosen:** two DSUs (`alice`, `bob`); count `used` successful unions.

- **vs single DSU:** cannot model asymmetric type-1/2.
- **vs MST algorithms:** same spanning idea; DSU is enough (unweighted).

## 5. Logic Walkthrough
Unite type-3 into both DSUs; count if either side united. Then type-1 → Alice only, type-2 → Bob only. If either `components != 1` → `-1`. Else `|E|-used`.

## 6. Dry Run
LC sample `n=4`: after type-3 and needed 1/2 edges, `used=4`, removable `2`.

## 7. Time & Space Complexity
Time **O(e α(n))**. Space **O(n)**. Why: constant passes over edges (section 4).

## 8. Trade-offs & Alternatives
Must process type-3 before exclusive edges — otherwise you may keep redundant exclusives and drop useful shared ones.

## 9. Common Mistakes / Edge Cases
0-index vs 1-index nodes; counting type-3 twice as two used edges when only one physical edge; requiring both DSUs to unite on type-3 (use if either needs it — actually: if already connected in both, removable; if needed by either, keep once).

## 10. Interview Follow-ups / Variations
Min cost version with weights. Only two edge colors. Critical edges.

## 11. Tags
`union-find`, `spanning-tree`, `greedy`, `leetcode-1579`, `difficulty:hard`
