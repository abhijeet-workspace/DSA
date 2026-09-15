# Find the Index of the First Occurrence in a String

## 1. Problem Statement
[LeetCode 28](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) — return the first index of `needle` in `haystack`, or `-1` (classic `strStr`).

- **Inputs:** `haystack`, `needle`.
- **Output:** first start index or `-1`.
- **Valid answer:** leftmost occurrence.
- **Edges:** empty needle; needle longer than haystack; overlapping.

## 2. Intuition
KMP (or Z/RK) finds the first match in linear time without restarting the text pointer naively.

## 3. Brute Force → Optimal
- **Brute:** O((N-M)M) sliding compare.
- **Optimal:** KMP O(N+M).

## 4. Data Structure / Approach Justification
**Chosen:** KMP with LPS — matches this topic's classic algorithms.

- **vs STL find:** fine in production; here we practice KMP.

## 5. Logic Walkthrough
Build LPS of needle; run KMP; on full match return `i-m`.

## 6. Dry Run
`haystack="sadbutsad"`, `needle="sad"` → **0**. `"leetcode","leeto"` → **-1**.

## 7. Time & Space Complexity
Time **O(N+M)**. Space **O(M)**.

## 8. Trade-offs & Alternatives
Rabin–Karp is fine if hash collisions are handled.

## 9. Common Mistakes / Edge Cases
Empty needle → 0 on LC; off-by-one on LPS jumps.

## 10. Interview Follow-ups / Variations
Repeated String Match; Longest Happy Prefix.

## 11. Tags
`kmp`, `string`, `leetcode-28`, `difficulty:easy`
