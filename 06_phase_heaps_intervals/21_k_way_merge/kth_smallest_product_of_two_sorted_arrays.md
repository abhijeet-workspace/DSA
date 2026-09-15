# Kth Smallest Product of Two Sorted Arrays

## 1. Problem Statement
[LeetCode 2040](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/) — two sorted arrays. Consider all products `nums1[i]*nums2[j]`. Return the k-th smallest product.

## 2. Intuition
Products form a monotone structure per row; binary-search the answer and count pairs ≤ mid with binary search per `nums1[i]` (handles negatives).

## 3. Brute Force → Optimal
- **Brute:** all products + select.
- **Heap of frontiers:** possible but awkward with negatives.
- **Optimal:** value BS — O(N log M log A).

## 4. Data Structure / Approach Justification
**Chosen:** binary search on product; per a in nums1 binary-search boundary in nums2.

- **vs materializing:** O(NM).
- **vs two heaps for pos/neg:** more complex.

## 5. Logic Walkthrough
Search mid in a wide range. Count products ≤ mid; adjust lo/hi.

## 6. Dry Run
`[2,5]*[3,4]`, k=2 → **8**.

## 7. Time & Space Complexity
Time **O(N log M log A)**. Space **O(1)**. Why: sorted-matrix kth on products (section 4).

## 8. Trade-offs & Alternatives
Hard extension of kth-in-matrix / prime fractions.

## 9. Common Mistakes / Edge Cases
Zero/negative handling; overflow; off-by-one k.

## 10. Interview Follow-ups / Variations
Kth largest product; three arrays.

## 11. Tags
`binary-search`, `k-way-merge`, `two-pointers`, `leetcode-2040`, `difficulty:hard`
