# Count of Range Sum

## 1. Problem Statement
[LeetCode 327](https://leetcode.com/problems/count-of-range-sum/) — count subarrays whose sum lies in `[lower, upper]`.

- **Inputs:** `nums`, `lower`, `upper`.
- **Output:** count of qualifying subarrays.
- **Valid answer:** exact count.
- **Edges:** empty; negative sums; large prefix values.

## 2. Intuition
Prefix sums: want `lower ≤ prefix[j]-prefix[i] ≤ upper`. For each right prefix, count earlier prefixes in `[prefix[j]-upper, prefix[j]-lower]`. Fenwick/merge on prefixes.

## 3. Brute Force → Optimal
- **Brute:** all subarrays — O(N²).
- **Optimal:** merge-sort on prefixes or Fenwick — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** merge-sort counting on prefix array (same family as reverse pairs).

- **vs Fenwick:** needs compression of all candidate bounds.

## 5. Logic Walkthrough
Build prefixes. Merge-sort prefixes; while merging count valid left partners for each right value.

## 6. Dry Run
`nums=[−2,5,−1]`, `[−2,2]` → **3**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Fenwick with compressed `prefix-upper/lower` keys is more online-friendly.

## 9. Common Mistakes / Edge Cases
Forgetting prefix 0; overflow; off-by-one on inclusive bounds.

## 10. Interview Follow-ups / Variations
Range sum query mutable; count inversions.

## 11. Tags
`prefix-sum`, `merge-sort`, `leetcode-327`, `difficulty:hard`
