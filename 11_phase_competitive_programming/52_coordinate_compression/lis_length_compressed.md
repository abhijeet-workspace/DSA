# LIS Length Compressed

## 1. Problem Statement
Length of the longest **strictly** increasing subsequence. [LeetCode 300](https://leetcode.com/problems/longest-increasing-subsequence/).

- **Inputs:** integer array `a`.
- **Output:** LIS length (0 if empty).
- **Valid answer:** max length of a strictly increasing subsequence (not necessarily contiguous).
- **Edges:** empty; strictly decreasing (1); duplicates (strict → equals don't extend).

## 2. Intuition
After compression, for rank `r`, best LIS ending here is `1 + max` among ranks `< r`. Maintain that max in a Fenwick (range-max) / segment tree.

## 3. Brute Force → Optimal
- **Brute:** DP `O(N²)`: `dp[i] = 1 + max{dp[j] : j<i, a[j]<a[i]}`.
- **Optimal:** compress → query max on `[1,r-1]` → update `r` — `O(N log N)`.

## 4. Data Structure / Approach Justification

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree
topic owns tree ops; here the skill is sparse→`1..U`.

**Chosen:** Fenwick-max on compressed ranks.

- **vs patience sorting / tails:** shorter for length-only; Fenwick generalizes to count/weighted LIS.
- **vs segment tree:** same role; Fenwick is compact for prefix-max.

## 5. Logic Walkthrough
Compress. For each rank `r`: `len = query(r-1)+1`, `update(r,len)`, track global `best`.

## 6. Dry Run
`[3,1,2,4]` → ranks `[3,1,2,4]`:
- 3→1; 1→1; 2→2; 4→3. LIS = **3**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: Fenwick stores best LIS ending at each rank seen so far (section 4).

## 8. Trade-offs & Alternatives
Tails binary search is shorter for length-only; Fenwick/SegTree extend to counting LIS more easily.

## 9. Common Mistakes / Edge Cases
Sum Fenwick instead of max; update before query; non-strict LIS without adjusting query range.

## 10. Interview Follow-ups / Variations
Count number of LIS (LC 673)? Longest non-decreasing?

## 11. Tags
`lis`, `fenwick`, `coordinate-compression`, `dp`, `difficulty:medium`
