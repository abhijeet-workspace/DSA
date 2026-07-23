# Compress Ranks

## Problem Statement
Map possibly large/sparse integers to dense ranks `1..U` among unique sorted values.

- **Inputs:** array of integers (any range, including negatives).
- **Output:** same-length array of 1-based ranks; equal values share a rank.
- **Valid answer:** rank = order statistic among unique values (`lower_bound` index + 1).
- **Edges:** all equal; already `1..N`; negatives; `INT_MIN`/`INT_MAX`.

## Intuition
Only relative order matters for many Fenwick/SegTree indices. Collect unique sorted values, then map each `a[i]` via `lower_bound`.

## Brute Force → Optimal
- **Brute / map:** assign ranks with `std::map` while iterating — same asymptotics, less cache-friendly.
- **Optimal:** copy → sort → `unique` → `lower_bound` per element — `O(N log N)`.

## Data Structure / Approach Justification
**Chosen:** sorted unique vector + binary search for ranks.

- **vs on-the-fly map:** clearer batch compression for offline arrays.
- **vs hash after sort:** `O(N)` map step after sorting uniques.

## Logic Walkthrough
Copy `a` into `vals`, sort, erase duplicates. For each `a[i]`, rank = `lower_bound` distance + 1.

## Dry Run
`[40,10,40,1000,-5]` → unique sorted `[-5,10,40,1000]` → ranks `[3,2,3,4,1]`.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort dominates; each lookup is `O(log U)` (section 4).

## Trade-offs & Alternatives
1-based ranks fit Fenwick trees that ignore index 0; 0-based is fine for plain arrays. Sorting unique drops multiplicity (desired).

## Common Mistakes / Edge Cases
Using distance without `unique` (duplicate ranks break trees); unstable mapping for equals.

## Interview Follow-ups / Variations
Compress pairs `(x,y)`? Compress online with dynamic trees?

## Tags
`coordinate-compression`, `sorting`, `binary-search`, `fenwick-prep`, `difficulty:easy`
