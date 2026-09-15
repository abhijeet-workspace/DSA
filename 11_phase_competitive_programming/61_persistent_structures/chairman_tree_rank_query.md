# Chairman Tree Rank Query

## 1. Problem Statement
Using a chairman (persistent freq) tree, answer how many values in `[L,R]` are ≤ `x` (rank query).

- **Inputs:** array; queries `(L,R,x)`.
- **Output:** count of elements ≤ x in range.
- **Edges:** x below/above all; empty counts.

## 2. Intuition
Same prefix versions as k-th; walk tree summing left parts where value domain ≤ rank(x).

## 3. Brute Force → Optimal
- **Brute:** scan subarray.
- **Chairman:** O(log U).

## 4. Data Structure / Approach Justification
**Chosen:** persistent frequency segtree on compressed values; prefix difference.

| Alternative | Note |
|-------------|------|
| Fenwick + Mo | Offline |
| Merge-sort tree | Count via binsearch |

## 5. Logic Walkthrough
1. Build prefix roots.
2. `rank(vl,vr,x)` sums counts on segments ≤ compressed x.

## 6. Dry Run
`[2,1,3,1]`, `[1,4]` ≤1 → **2**.

## 7. Time & Space Complexity
Build **O(N log U)**; query **O(log U)**.

## 8. Trade-offs & Alternatives
Dual to k-th walk.

## 9. Common Mistakes / Edge Cases
Using strict < vs ≤ inconsistently.

## 10. Interview Follow-ups / Variations
Count in [x,y]; distinct values.

## 11. Tags
`chairman-tree`, `rank`, `persistent`, `difficulty:hard`
