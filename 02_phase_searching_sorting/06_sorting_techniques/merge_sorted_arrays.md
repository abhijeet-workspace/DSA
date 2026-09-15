# Merge Sorted Arrays

## 1. Problem Statement
[LeetCode 88](https://leetcode.com/problems/merge-sorted-array/) — merge `nums2` into `nums1` which has size `m+n` with trailing capacity; in-place.

- **Inputs:** `nums1` (first `m` valid), `m`, `nums2` (length `n`), `n`.
- **Output:** `nums1` holds merged sorted result.
- **Valid answer:** non-decreasing merge of both sequences.
- **Edges:** `n = 0`; `m = 0`; all `nums2` smaller; duplicates.

## 2. Intuition
Fill from the back (`k = m+n-1`) so writes never overwrite unread `nums1` values.

## 3. Brute Force → Optimal
- **Brute:** copy then sort — O((m+n) log(m+n)).
- **Optimal:** two-pointer from ends — O(m+n) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** pointers `i=m-1`, `j=n-1`, `k=m+n-1`.

- **vs extra buffer merge:** clearer but O(m+n) space.
- **vs insert + shift:** O((m+n)²) moves.

## 5. Logic Walkthrough
While both sides live, place the larger at `k--`. Drain remaining `nums2` into front (remaining `nums1` already in place).

## 6. Dry Run
`nums1=[1,2,3,0,0,0]`, `m=3`, `nums2=[2,5,6]`, `n=3` → `[1,2,2,3,5,6]`.

Also: `m=0` → copy all of `nums2`; `n=0` → `nums1` unchanged.

## 7. Time & Space Complexity
Time **O(m+n)**. Space **O(1)** extra. Why: each element written once (section 4).

## 8. Trade-offs & Alternatives
Forward merge needs a buffer. Prefer back-fill when capacity is at the end.

## 9. Common Mistakes / Edge Cases
Forgetting to copy leftover `nums2`; starting pointers at wrong ends; treating capacity zeros as data.

## 10. Interview Follow-ups / Variations
Merge k sorted lists; merge intervals.

## 11. Tags
`sorting`, `two-pointers`, `in-place`, `difficulty:easy`
