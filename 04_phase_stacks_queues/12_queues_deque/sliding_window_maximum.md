# Sliding Window Maximum

## 1. Problem Statement
[LeetCode 239](https://leetcode.com/problems/sliding-window-maximum/) — for each contiguous window of size `k`, return its maximum.

- **Inputs:** `vector<int> nums`, `int k`.
- **Output:** vector of window maxima (length `n - k + 1`).
- **Constraints:** `1 ≤ k ≤ n`; values may be negative.
- **Edges:** `k == 1`; `k == n`; strictly decreasing / increasing arrays.

## 2. Intuition
In a window, any index whose value is smaller than a newer one can never be the max while both are present. A deque of indices in decreasing `nums` order keeps the current max at the front.

## 3. Brute Force → Optimal
- **Brute:** for each window start, scan `k` elements — O(NK) time, O(1) space.
- **Optimal:** monotonic deque — each index enters/leaves once — O(N) time, O(K) space.

## 4. Data Structure / Approach Justification
**Chosen:** `deque` of indices, front = max in window.

| Alternative | Cost / note |
|-------------|-------------|
| Multiset / priority queue | O(N log K), heavier eviction |
| Segment tree | Overkill for fixed sliding windows |

## 5. Logic Walkthrough
1. For each `i`: drop `front` if `front == i - k`.
2. Pop back while `nums[back] < nums[i]`; push `i`.
3. If `i >= k - 1`, append `nums[front]`.

## 6. Dry Run
`nums=[1,3,-1,-3,5,3,6,7]`, `k=3`:
- `i=0..2`: deque ends `[1,2]` → max `3`
- `i=3`: max `3`; `i=4`: max `5`; … last windows → `6`, `7`

## 7. Time & Space Complexity
- **Time:** O(N) amortized (one push/pop per index)
- **Space:** O(K) for the deque

## 8. Trade-offs & Alternatives
Deque is interview-standard. Multiset is simpler to reason about but slower. Two heaps with lazy delete also work.

## 9. Common Mistakes / Edge Cases
Storing values instead of indices (can't expire by window); forgetting to pop `i - k`; using strict vs non-strict compare inconsistently.

## 10. Interview Follow-ups / Variations
Sliding window minimum; window median; first negative in window; jump game VI (1696).

## 11. Tags
`deque`, `monotonic-queue`, `sliding-window`, `leetcode-239`, `difficulty:hard`
