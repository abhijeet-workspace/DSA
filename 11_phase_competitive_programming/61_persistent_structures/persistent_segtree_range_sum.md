# Persistent SegTree — Versioned Range Sum

## 1. Problem Statement
Support creating a version with a point add, and query range sum on any historical version.

- **Inputs:** size `n`, updates `(idx, add)` producing new roots, queries `(version, L, R)`.
- **Output:** sum on that version’s range.
- **Valid answer:** historical versions unchanged by later updates.
- **Edges:** query old root after newer updates; empty ranges.

## 2. Intuition
Each update copies O(log N) nodes on the path; unchanged children are shared. `roots[ver]` points at that version’s tree.

## 3. Brute Force → Optimal
- **Brute:** copy whole array per update — O(N) space/time.
- **Optimal:** persistent SegTree O(log N) time/space per update.

## 4. Data Structure / Approach Justification
**Chosen:** path-copying sum SegTree with explicit node pool.

| Alternative | Note |
|-------------|------|
| Rollback Fenwick | Offline chronologically |
| Full array snapshots | Memory blowup |
| Functional trees | Same idea, different API |

## 5. Logic Walkthrough
1. `build` empty tree → `root0`.
2. `upd(prev, idx, add)` allocates a new path, bumps `sum`.
3. `query(root, ql, qr)` standard SegTree recursion on that root only.

## 6. Dry Run
`v0` empty; `v1` idx2+=5 → query 5; `v2` idx2+=3 → query 8; `v0` still 0.

## 7. Time & Space Complexity
Per update/query **O(log N)**; space **O(Q log N)** new nodes. Why: path copy only (section 4).

## 8. Trade-offs & Alternatives
Memory is the main cost. Persistence enables “what-if” histories without undo stacks.

## 9. Common Mistakes / Edge Cases
Mutating nodes in place; querying wrong root; forgetting to copy child pointers from `prev`.

## 10. Interview Follow-ups / Variations
Persistent range updates (lazy); persist Fenwick via segment tree.

## 11. Tags
`persistent-segtree`, `range-sum`, `versions`, `cp`, `difficulty:hard`
