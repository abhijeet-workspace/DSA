# Sum of Subarray Ranges

## 1. Problem Statement
[LeetCode 2104](https://leetcode.com/problems/sum-of-subarray-ranges/) — the range of a subarray is `max - min`. Return the sum of ranges over **all** contiguous subarrays.

- **Inputs:** `vector<int> nums`.
- **Output:** `long long` sum of ranges.
- **Edges:** single element (0); all equal (0); duplicates (tie-breaking matters).

## 2. Intuition
`Σ(max − min) = Σ max − Σ min`. Each element’s contribution as subarray maximum / minimum uses the same monotonic-stack span technique as sum of subarray minimums.

## 3. Brute Force → Optimal
- **Brute:** enumerate all subarrays tracking min/max — O(N²).
- **Optimal:** two contribution passes (max and min) — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** previous/next greater (for max) and previous/next smaller (for min) spans via stacks; asymmetric compares for ties.

| Alternative | Why it loses here |
|-------------|-------------------|
| O(N²) nested loops | TLE for large N |
| Segment tree over all ranges | Unnecessary; contribution is enough |

## 5. Logic Walkthrough
1. For maxima: count how far `nums[i]` is the strict maximum on one side and non-strict on the other.
2. Same for minima with flipped comparisons.
3. Answer = sum of `nums[i] * left * right` for max minus the same for min.

## 6. Dry Run
`[1,2,3]`:
- subarrays ranges: `0+0+0 +1 +1 +2` wait — ranges: singles 0; `[1,2]→1`, `[2,3]→1`, `[1,2,3]→2` → **4**.

## 7. Time & Space Complexity
- **Time:** O(N).
- **Space:** O(N) for spans/stacks.

## 8. Trade-offs & Alternatives
Reuse the exact sum-of-subarray-minimums code twice (once on `nums`, once on negated values) instead of a `want_max` flag.

## 9. Common Mistakes / Edge Cases
Same compare direction on both sides (double-counts ties); 32-bit overflow (need `long long`); forgetting range is max−min not max alone.

## 10. Interview Follow-ups / Variations
Sum of subarray minimums (907); sum of subarray maximums; largest rectangle (span idea).

## 11. Tags
`stack`, `monotonic-stack`, `contribution`, `leetcode-2104`, `difficulty:medium`
