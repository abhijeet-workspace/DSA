# Compress Ranks

## 1. Problem Statement
Map possibly large/sparse integers to dense ranks `1..U` among unique sorted values.

- **Inputs:** array of integers (any range, including negatives).
- **Output:** same-length array of 1-based ranks; equal values share a rank.
- **Valid answer:** rank = order statistic among unique values (`lower_bound` index + 1).
- **Edges:** all equal; already `1..N`; negatives; `INT_MIN`/`INT_MAX`.

## 2. Intuition
Only relative order matters for many Fenwick/SegTree indices. Collect unique sorted values, then map each `a[i]` via `lower_bound`.

## 3. Brute Force → Optimal
- **Brute / map:** assign ranks with `std::map` while iterating — same asymptotics, less cache-friendly.
- **Optimal:** copy → sort → `unique` → `lower_bound` per element — `O(N log N)`.

## 4. Data Structure / Approach Justification

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree
topic owns tree ops; here the skill is sparse→`1..U`.

**Chosen:** sorted unique vector + binary search for ranks.

- **vs on-the-fly map:** clearer batch compression for offline arrays.
- **vs hash after sort:** `O(N)` map step after sorting uniques.

## 5. Logic Walkthrough
Copy `a` into `vals`, sort, erase duplicates. For each `a[i]`, rank = `lower_bound` distance + 1.

## 6. Dry Run
`[40,10,40,1000,-5]` → unique sorted `[-5,10,40,1000]` → ranks `[3,2,3,4,1]`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort dominates; each lookup is `O(log U)` (section 4).

## 8. Trade-offs & Alternatives
1-based ranks fit Fenwick trees that ignore index 0; 0-based is fine for plain arrays. Sorting unique drops multiplicity (desired).

## 9. Common Mistakes / Edge Cases
Using distance without `unique` (duplicate ranks break trees); unstable mapping for equals.

## 10. Interview Follow-ups / Variations
Compress pairs `(x,y)`? Compress online with dynamic trees?

## 11. Tags
`coordinate-compression`, `sorting`, `binary-search`, `fenwick-prep`, `difficulty:easy`
