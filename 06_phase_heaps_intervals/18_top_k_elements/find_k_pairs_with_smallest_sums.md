# Find K Pairs with Smallest Sums

## 1. Problem Statement
[LeetCode 373](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) — given two sorted ascending arrays, return `k` pairs `(u,v)` with `u∈nums1`, `v∈nums2` having the smallest sums. Any order among ties OK.

- **Inputs:** `nums1`, `nums2`, `k`.
- **Output:** up to `k` pairs.
- **Valid answer:** the k smallest sums (pairs may repeat values from different indices).
- **Edges:** `k` larger than `n*m`; empty array; duplicates in arrays.

## 2. Intuition
Like merge-k lists: for each `nums2[j]`, pairs `(nums1[i], nums2[j])` increase with `i`. Seed heap with `(0,j)` for first `min(k,|nums2|)` columns; pop min sum and push `(i+1,j)`.

## 3. Brute Force → Optimal
- **Brute:** all pairs, sort — O(NM log(NM)).
- **Optimal:** bounded min-heap expansion — O(k log k).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of `(sum, i, j)`.

- **vs full cartesian product:** too large when k ≪ n·m.
- **vs binary search on sum threshold:** also valid; heap is the k-way-merge style taught here.

## 5. Logic Walkthrough
Push `(nums1[0]+nums2[j], 0, j)` for j in range. Repeat k times: pop best pair; if `i+1` exists push that next row for same j.

## 6. Dry Run
`nums1=[1,7,11]`, `nums2=[2,4,6]`, k=3: seed sums 3,5,7 → pop `[1,2]`, push `[7,2]`; pop `[1,4]`; pop `[1,6]`.

## 7. Time & Space Complexity
Time **O(k log k)**. Space **O(k)**. Why: heap size O(k), k pops (section 4).

## 8. Trade-offs & Alternatives
Seeding by rows vs columns is symmetric—pick the smaller array dimension for the seed loop when optimizing constants.

## 9. Common Mistakes / Edge Cases
Pushing both `(i+1,j)` and `(i,j+1)` without a visited set (duplicates); overflowing when k is huge (cap by n*m conceptually).

## 10. Interview Follow-ups / Variations
Kth smallest pair sum; merge k sorted lists; kth smallest in sorted matrix.

## 11. Tags
`heap`, `k-way-merge`, `two-arrays`, `leetcode-373`, `difficulty:medium`
