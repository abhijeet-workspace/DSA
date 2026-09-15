# Number of Pairs Satisfying Inequality

## 1. Problem Statement
[LeetCode 2426](https://leetcode.com/problems/number-of-pairs-satisfying-inequality/) — count pairs `i < j` with `nums1[i]-nums1[j] ≤ nums2[i]-nums2[j] + diff`.

- **Inputs:** `nums1`, `nums2`, `diff`.
- **Output:** pair count.
- **Valid answer:** exact count.
- **Edges:** negatives; large values needing compression.

## 2. Intuition
Rewrite as `(nums1[i]-nums2[i]) ≤ (nums1[j]-nums2[j]) + diff`. Let `a[k]=nums1[k]-nums2[k]`; count `i<j` with `a[i] ≤ a[j]+diff`. Fenwick from left or right.

## 3. Brute Force → Optimal
- **Brute:** O(N²).
- **Optimal:** compress `a` + Fenwick — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** Fenwick of frequencies of `a` values while scanning left→right.

- **vs merge-sort:** also valid.

## 5. Logic Walkthrough
Compress values of `a` and `a+diff`. For each j: query count of prior `a[i] ≤ a[j]+diff`; then insert `a[j]`.

## 6. Dry Run
`nums1=[3,2,5]`, `nums2=[2,2,1]`, `diff=1` → **3**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Merge-sort counting avoids Fenwick API but is longer.

## 9. Common Mistakes / Edge Cases
Wrong inequality direction; compression missing `a[j]+diff` keys.

## 10. Interview Follow-ups / Variations
Reverse pairs; count smaller.

## 11. Tags
`fenwick`, `coordinate-compression`, `leetcode-2426`, `difficulty:hard`
