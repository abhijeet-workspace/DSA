# Maximum Sum Subarray of Size K

## 1. Problem Statement
Find the maximum sum of any contiguous subarray of length exactly `k`.

- **Input:** `vector<int> nums`, int `k`
- **Output:** int max sum, or `-1` if `n < k`
- **Valid answer:** max over all windows of size k
- **Edges:** `n < k`; negatives; k = n

## 2. Intuition
Adjacent windows share k−1 elements. Recompute by adding the new right and dropping the old left.

## 3. Brute Force → Optimal
- **Brute:** sum each window from scratch — O(N·K).
- **Optimal:** fixed sliding window — O(N).

## 4. Data Structure / Approach Justification
Two integers: `windowSum` and `maxSum`. No extra DS.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested sum loops | O(N·K) |
| Prefix sums | O(N) too, but more memory |

## 5. Logic Walkthrough
1. Sum first k elements → `windowSum`, `maxSum`.
2. For i = k..n−1: `windowSum += nums[i] − nums[i−k]`; update max.
3. Return `maxSum`.

## 6. Dry Run
`nums=[2,1,5,1,3,2]`, `k=3`
- windows: 2+1+5=8 → 1+5+1=7 → 5+1+3=9 → 1+3+2=6 → **max=9**

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: each element enters/leaves the window once.

## 8. Trade-offs & Alternatives
Prefix sums also O(N) with O(N) space — useful if many offline range queries.

## 9. Common Mistakes / Edge Cases
Forgetting `n < k`; off-by-one on `i - k`; not initializing with first window.

## 10. Interview Follow-ups / Variations
Min sum of size k? Average? Variable-size max sum (Kadane)?

## 11. Tags
`sliding-window`, `fixed-window`, `array`, `easy`
