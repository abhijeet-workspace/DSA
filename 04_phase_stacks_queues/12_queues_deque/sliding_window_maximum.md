# Sliding Window Maximum

## Problem Statement
[LeetCode 239](https://leetcode.com/problems/sliding-window-maximum/) — for each contiguous window of size `k`, return its maximum.

- **Inputs:** `vector<int> nums`, `int k`.
- **Output:** vector of window maxima (length `n - k + 1`).
- **Constraints:** `1 ≤ k ≤ n`; values may be negative.
- **Edges:** `k == 1`; `k == n`; strictly decreasing / increasing arrays.

## Intuition
In a window, any index whose value is smaller than a newer one can never be the max while both are present. A deque of indices in decreasing `nums` order keeps the current max at the front.

## Brute Force → Optimal
- **Brute:** for each window start, scan `k` elements — O(NK) time, O(1) space.
- **Optimal:** monotonic deque — each index enters/leaves once — O(N) time, O(K) space.

## Data Structure / Approach Justification
**Chosen:** `deque` of indices, front = max in window.

- **vs multiset / priority queue:** also O(N log K), heavier constants and harder eviction.
- **vs segment tree:** overkill for fixed sliding windows.

## Logic Walkthrough
For each `i`: drop `front` if `front == i - k`; pop back while `nums[back] < nums[i]`; push `i`; if `i >= k - 1`, append `nums[front]`.

## Dry Run
`nums=[1,3,-1,-3,5,3,6,7]`, `k=3`:
- `i=0..2`: deque ends `[1,2]` → max `3`
- `i=3`: max `3`; `i=4`: max `5`; … last windows → `6`, `7`

## Time & Space Complexity
Time **O(N)** (amortized one push/pop per index). Space **O(K)** for the deque. Why: monotonic eviction (section 4).

## Trade-offs & Alternatives
Deque is interview-standard. Multiset is simpler to reason about but slower. Two heaps with lazy delete also work.

## Common Mistakes / Edge Cases
Storing values instead of indices (can't expire by window); forgetting to pop `i - k`; using strict vs non-strict compare inconsistently.

## Interview Follow-ups / Variations
Sliding window minimum; window median; first negative in window; sum of window maxima.

## Tags
`deque`, `monotonic-queue`, `sliding-window`, `difficulty:hard`
