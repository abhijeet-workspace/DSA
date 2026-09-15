# Reverse Pairs Compressed

## 1. Problem Statement
[LeetCode 493](https://leetcode.com/problems/reverse-pairs/) — count `nums[i]>2*nums[j]` for `i<j`.

## 2. Intuition
Right-to-left BIT of values; query how many `v` with `2v < nums[i]`.

## 3. Brute Force → Optimal
- Brute O(n²). Merge-sort / BIT O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** compress values; BIT ranks. Pedagogy vs Fenwick-topic copy.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Scan right; query; insert.

## 6. Dry Run
Samples → 2 and 3.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Watch `2*x` 64-bit.

## 9. Common Mistakes / Edge Cases
Overflow; wrong inequality.

## 10. Interview Follow-ups / Variations
Count of range sum.

## 11. Tags
`coordinate-compression`, `leetcode-493`, `difficulty:hard`

