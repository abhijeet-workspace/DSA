# Minimum Size Subarray Sum

## 1. Problem Statement
[LeetCode 209](https://leetcode.com/problems/minimum-size-subarray-sum/) — given positive integers `nums` and `target`, return the minimal length of a contiguous subarray whose sum is ≥ `target`, or `0` if none exists.

- **Input:** `target`, `nums` (all positive)
- **Output:** minimal length, or `0`
- **Valid answer:** shortest valid window
- **Edges:** single element ≥ target; total sum < target; whole array needed

**Prerequisite note:** Uses the two-pointer expand/shrink template. Formal window invariant: `[left, right]` is the shortest suffix ending at `right` that still satisfies (or just became invalid after shrink). Positive nums make the sum monotone in window growth — critical for correctness of greedy shrink.

## 2. Intuition
Expand `right` to grow the sum; once `sum ≥ target`, shrink `left` as far as possible while remaining valid, recording the best length.

## 3. Brute Force → Optimal
- **Brute:** all subarrays — O(N²).
- **Optimal:** variable sliding window — O(N). Binary search on prefix sums is O(N log N).

## 4. Data Structure / Approach Justification
Two pointers + running sum. Positive integers justify monotone shrink.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested sums | O(N²) |
| Prefix + binary search | Correct O(N log N), more code |

## 5. Logic Walkthrough
1. `sum += nums[right]`.
2. While `sum ≥ target`: update `best`, `sum -= nums[left]`, `++left`.
3. Return `0` if never updated.

## 6. Dry Run
`target=7`, `[2,3,1,2,4,3]` — when window reaches `[4,3]` sum=7 length **2** (minimal).

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: each index moves left/right at most once.

## 8. Trade-offs & Alternatives
Negatives break monotone shrink — need different techniques (prefix + map for exact sum variants).

## 9. Common Mistakes / Edge Cases
Assuming an answer always exists; off-by-one on length; using this template when negatives are allowed.

## 10. Interview Follow-ups / Variations
Exact sum K with positives; product < K; shortest covering window (LC 76).

## 11. Tags
`sliding-window`, `two-pointers`, `variable-window`, `leetcode-209`, `medium`
