# Sliding Window Median

## Problem Statement
[LeetCode 480](https://leetcode.com/problems/sliding-window-median/) — for each contiguous window of size `k` in `nums`, return its median.

- **Inputs:** `vector<int> nums`, `int k`.
- **Output:** `vector<double>` of length `n-k+1`.
- **Valid answer:** odd `k` → middle element; even `k` → average of two middles.
- **Edges:** negatives; duplicates; `k==1`; `k==n`; large values when averaging.

## Intuition
Maintain the current window split into lower/upper halves (like median stream), but also remove the element leaving the window.

## Brute Force → Optimal
- **Brute:** copy each window, sort, take median — O(N K log K).
- **Optimal:** two `multiset`s (lazy two-heaps) — O(N log K) with erase/insert.

## Data Structure / Approach Justification
**Chosen:** `low` / `high` multisets; max of `low` and min of `high` are the middle(s).

- **vs priority_queues:** hard to delete arbitrary outgoing values.
- **vs sorted vector per window:** too slow for interview N.

## Logic Walkthrough
Add into the correct half, rebalance sizes. When window full, record median, then erase the outgoing value from the half that holds it and rebalance.

## Dry Run
`nums=[1,3,-1,-3,5,3,6,7]`, `k=3`: windows → medians `1, -1, -1, 3, 5, 6`.

## Time & Space Complexity
Time **O(N log K)**. Space **O(K)**. Why: each insert/erase is log of window size (section 4).

## Trade-offs & Alternatives
Two heaps + delayed deletion also works; policy-based order statistics trees are cleaner but non-portable.

## Common Mistakes / Edge Cases
Erasing all duplicates with `erase(key)` instead of one iterator; not rebalancing after remove; integer overflow on even-window average.

## Interview Follow-ups / Variations
Median data stream (295) without removals; sliding window maximum (deque); kth in window.

## Tags
`sliding-window`, `two-heaps`, `multiset`, `median`, `leetcode-480`, `difficulty:hard`
