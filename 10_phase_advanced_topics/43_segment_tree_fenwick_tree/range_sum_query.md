# Range Sum Query — Mutable

## Problem Statement
[LeetCode 307](https://leetcode.com/problems/range-sum-query-mutable/) — maintain an array supporting point updates and range sum queries.

- **Inputs:** `vector<int> nums`; `update(index, val)`; `sumRange(left, right)`.
- **Output:** sum of `nums[left..right]` inclusive after updates.
- **Valid answer:** exact sum.
- **Edges:** empty array; single element; update then overlapping queries.

## Intuition
A binary tree over the array: each node stores the sum of a contiguous segment. Point update climbs to the leaf and refreshes ancestors; a query covers the range with O(log N) disjoint nodes.

## Brute Force → Optimal
- **Brute:** mutate array, scan range — O(1) update, O(N) query.
- **Prefix sums:** O(1) query, O(N) update.
- **Optimal:** segment tree — O(log N) for both.

## Data Structure / Approach Justification
**Chosen:** 1-based heap-style segment tree in `vector` of size `4N`.

- **vs Fenwick:** both O(log N) for sum; segtree generalizes to min/max and teaches lazy updates later.
- **vs sqrt decomposition:** similar asymptotic but larger constants / harder for interviews.

## Logic Walkthrough
`build` recurses to leaves then `parent = left + right`. `update` goes to the leaf for `idx`, sets value, rebuilds path. `sumRange` returns 0 on no overlap, node value on full cover, else sum of both children.

## Dry Run
`nums={1,3,5}`:
- `sumRange(0,2)` → **9**
- `update(1, 2)` → array `{1,2,5}`
- `sumRange(0,2)` → **8**

## Time & Space Complexity
Build **O(N)**; update/query **O(log N)**; space **O(N)** (`~4N` nodes). Why: tree height is log N (section 4).

## Trade-offs & Alternatives
Fenwick is shorter for pure sums. Use this pattern when follow-ups add min/max or range updates (then add lazy). Prefix arrays lose if updates are frequent.

## Common Mistakes / Edge Cases
Wrong child indices (`2*node` vs `2*node+1`); returning on partial overlap without recursing; forgetting empty `n==0`; off-by-one on inclusive `right`.

## Interview Follow-ups / Variations
Range add (lazy); range min/max; 2D segtree; online vs offline Mo’s algorithm.

## Tags
`segment-tree`, `range-sum`, `point-update`, `leetcode-307`, `difficulty:medium`
