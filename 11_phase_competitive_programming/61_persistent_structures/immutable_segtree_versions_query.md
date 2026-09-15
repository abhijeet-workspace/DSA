# Immutable SegTree Versions Query

## 1. Problem Statement
Build many immutable prefix versions of a sum segtree and answer range sum on a chosen version.

- **Inputs:** array updates creating versions `root[i]`; queries `(version, L, R)`.
- **Output:** sum on that historical array state.
- **Edges:** empty range; version 0.

## 2. Intuition
Same as persistent range-sum: each prefix version shares structure with previous.

## 3. Brute Force → Optimal
- **Brute:** store full arrays.
- **Persistent roots:** O(log N) query.

## 4. Data Structure / Approach Justification
**Chosen:** persistent sum segtree; keep `vector<root>`.

| Alternative | Note |
|-------------|------|
| Fenwick + rebuild | Not historical |
| Sparse table | Static only |

## 5. Logic Walkthrough
1. Build empty/zero tree.
2. For each set, push new root.
3. Query walks one root.

## 6. Dry Run
Set idx1+=5 then idx2+=3; query version1 [1,2] may miss second update.

## 7. Time & Space Complexity
**O(log N)** per update/query.

## 8. Trade-offs & Alternatives
Classic CP template piece.

## 9. Common Mistakes / Edge Cases
Using wrong root index; inclusive/exclusive bounds.

## 10. Interview Follow-ups / Variations
k-th; min; reversible updates.

## 11. Tags
`persistent-segtree`, `versions`, `range-sum`, `difficulty:hard`
