# Shortest Subarray with Sum at Least K

## 1. Problem Statement
[LeetCode 862](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/) — shortest contiguous subarray whose sum ≥ `k` (array may contain negatives). Return length or `-1`.

- **Inputs:** `nums`, target `k`.
- **Output:** minimal length, or `-1`.
- **Edges:** single element ≥ k; all negative; exact `k`; no answer.

## 2. Intuition
Prefix sums: need minimal `j-i` with `prefix[j]-prefix[i] ≥ k`. Maintain increasing prefixes in a deque so the best (smallest) `prefix[i]` for a fixed `j` is at the front; also drop worse longer candidates from the back.

## 3. Brute Force → Optimal
- **Brute:** all subarrays — O(N²).
- **Sliding window (positive only):** fails with negatives.
- **Optimal:** prefix + monotonic deque — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `prefix[0]=0`, deque of indices with increasing `prefix`.

| Alternative | Why weaker |
|-------------|------------|
| Two pointers | Breaks on negatives |
| Segment tree on prefixes | O(N log N) |

## 5. Logic Walkthrough
1. Build `prefix[i+1]=prefix[i]+nums[i]`.
2. For each `j`: while front satisfies `prefix[j]-prefix[front]≥k`, update ans and pop front.
3. While back has `prefix[back] ≥ prefix[j]`, pop back; push `j`.

## 6. Dry Run
`nums=[2,-1,2]`, `k=3`: prefixes `0,2,1,3` → at `j=3`, `3-0≥3` length 3.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) prefixes + deque

## 8. Trade-offs & Alternatives
Hard variant of “minimum size subarray sum” once negatives appear — deque is the standard fix.

## 9. Common Mistakes / Edge Cases
Using `int` for prefix overflow (use `long long`); forgetting `prefix[0]=0`; returning 0 instead of `-1`.

## 10. Interview Follow-ups / Variations
Min size subarray sum (209, positives); max value of equation (1499).

## 11. Tags
`deque`, `prefix-sum`, `monotonic-queue`, `leetcode-862`, `difficulty:hard`
