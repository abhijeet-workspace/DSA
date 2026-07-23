# Sliding Window Maximum

## 1. Problem Statement
Given `nums` and window size `k`, return the max of each contiguous window of size k.

- **Input:** `vector<int> nums`, int `k`
- **Output:** `vector<int>` of length `n−k+1`
- **Valid answer:** max of `nums[i..i+k−1]` for each i
- **Edges:** k=1; k=n; negatives; decreasing array

## 2. Intuition
Maintain a deque of candidate indices in decreasing value order; front is always the window max.

## 3. Brute Force → Optimal
- **Brute:** scan each window — O(N·K).
- **Optimal:** monotonic deque — O(N) (each index push/pop ≤ once).

## 4. Data Structure / Approach Justification
`deque<int>` storing indices (not values) so we can drop out-of-window fronts.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested max | O(N·K) |
| Multiset | O(N log K); heavier |

## 5. Logic Walkthrough
1. Drop front if index ≤ i−k.
2. Pop back while back value < nums[i].
3. Push i; if window full (`i ≥ k−1`), emit `nums[dq.front()]`.

## 6. Dry Run
`nums=[1,3,-1,-3,5,3,6,7]`, `k=3`
- windows max: 3, 3, 5, 5, 6, 7

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(K)
- Why: each index enqueued/dequeued at most once; deque ≤ k.

## 8. Trade-offs & Alternatives
Sparse table / segment tree for offline RMQ — overkill when only sliding windows matter.

## 9. Common Mistakes / Edge Cases
Storing values instead of indices; forgetting to evict `i−k`; using strictly `<` vs `≤` (ties).

## 10. Interview Follow-ups / Variations
Sliding window minimum? Window median (two heaps)?

## 11. Tags
`sliding-window`, `deque`, `monotonic-queue`, `leetcode-239`, `hard`
