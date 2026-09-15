# Reverse Pairs

## 1. Problem Statement
[LeetCode 493](https://leetcode.com/problems/reverse-pairs/) — count pairs `(i,j)` with `i < j` and `nums[i] > 2 * nums[j]`.

- **Inputs:** `vector<int> nums`.
- **Output:** pair count.
- **Valid answer:** exact count.
- **Edges:** negatives; overflow on `2*nums[j]`; empty.

## 2. Intuition
Like inversions with threshold `2*nums[j]`. Fenwick on compressed values: insert from right, query count of values `> 2*nums[i]` when processing left… or merge-sort variant.

## 3. Brute Force → Optimal
- **Brute:** O(N²) compare.
- **Optimal:** merge-sort count or Fenwick — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** merge-sort style count during merge (classic for this LC); Fenwick alternative noted.

- **vs Fenwick:** same asymptotics; merge-sort avoids 2× overflow via careful compare.

## 5. Logic Walkthrough
In merge-sort, before merging, for each left element advance a right pointer while `left > 2*right`; add that count; then merge sorted.

## 6. Dry Run
`[1,3,2,3,1]` → **2**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Fenwick with long ranks also works; watch `2LL*nums[j]` overflow.

## 9. Common Mistakes / Edge Cases
`2*nums[j]` 32-bit overflow; counting `≥` instead of `>`; unstable merge indices.

## 10. Interview Follow-ups / Variations
Count of range sum (327); standard inversions.

## 11. Tags
`merge-sort`, `divide-conquer`, `leetcode-493`, `difficulty:hard`
