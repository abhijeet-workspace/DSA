# Jump Game VI

## 1. Problem Statement
[LeetCode 1696](https://leetcode.com/problems/jump-game-vi/) — start at index 0; from `i` jump to any `i+1..i+k`; score is sum of visited `nums`. Maximize score ending at `n-1`.

- **Inputs:** `nums`, jump limit `k`.
- **Output:** max score.
- **Edges:** `k=1`; all negative; `k=n-1`.

## 2. Intuition
`dp[i] = nums[i] + max(dp[j])` for `j in [i-k, i-1]`. Maintain a monotonic decreasing deque of candidate `dp` indices in the window.

## 3. Brute Force → Optimal
- **Brute:** for each `i` scan last `k` — O(NK).
- **Optimal:** deque window maximum on `dp` — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** DP + monotonic deque of indices (front = best prior score).

| Alternative | Cost |
|-------------|------|
| Segment tree / sparse table | O(N log N), heavier |
| Priority queue + lazy delete | O(N log N) |

## 5. Logic Walkthrough
1. `dp[0]=nums[0]`; deque holds 0.
2. For `i=1..n-1`: expire `front < i-k`; `dp[i]=nums[i]+dp[front]`; pop back while `dp[back] <= dp[i]`; push `i`.
3. Answer `dp[n-1]`.

## 6. Dry Run
`nums=[1,-1,-2,4,-7,3]`, `k=2`: path scores build to `dp` ending `7` via `1→-1→4→3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for `dp` (can compress with care)

## 8. Trade-offs & Alternatives
Same deque pattern as sliding window maximum applied to DP values.

## 9. Common Mistakes / Edge Cases
Using `nums` order instead of `dp` in the deque; exclusive window `[i-k,i)`; overflow if using `int` on large sums — prefer `long long` when needed (LC constraints fit `int` here).

## 10. Interview Follow-ups / Variations
Constrained subsequence sum (1425); jump game II (min jumps).

## 11. Tags
`deque`, `dp`, `monotonic-queue`, `leetcode-1696`, `difficulty:hard`
