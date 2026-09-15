# Find K-th Smallest Pair Distance

## 1. Problem Statement
[LeetCode 719](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) — pair distance = `|nums[i]-nums[j]|` (i<j); return the k-th smallest distance.

- **Inputs:** `nums`, `k`.
- **Output:** k-th smallest pairwise absolute difference.
- **Valid answer:** binary search on distance + two-pointer count.
- **Edges:** duplicates (distance 0); k=1; sorted already.

## 2. Intuition
After sorting, count pairs with distance ≤ mid in O(N) with two pointers; binary search the k-th distance.

## 3. Brute Force → Optimal
- **Brute:** all pairs + heap/sort — O(N² log N).
- **Optimal:** sort + binary search — O(N log N + N log W).

## 4. Data Structure / Approach Justification
**Chosen:** sort + binary search + sliding count.

- **Adjacent** to k-way/k-th selection family (not a pure heap merge).

## 5. Logic Walkthrough
Sort. lo=0, hi=max-min. While lo<hi: if count(mid)≥k then hi=mid else lo=mid+1.

## 6. Dry Run
`[1,3,1]`, k=1 → distances 0,2,2 → **0**.

## 7. Time & Space Complexity
Time **O(N log N + N log W)**. Space **O(1)**. Why: sort + O(log W) counts (section 4).

## 8. Trade-offs & Alternatives
Heap of all pairs is simpler but memory-heavy; prefer binary search in interviews.

## 9. Common Mistakes / Edge Cases
Off-by-one in count; searching values not distances; unsorted input.

## 10. Interview Follow-ups / Variations
Kth smallest in matrix; find k pairs with smallest sums (top-k folder).

## 11. Tags
`binary-search`, `two-pointers`, `k-way-merge-adjacent`, `leetcode-719`, `difficulty:hard`
