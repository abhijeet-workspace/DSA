# Maximum Average Subarray I

## 1. Problem Statement
[LeetCode 643](https://leetcode.com/problems/maximum-average-subarray-i/) — find a contiguous subarray of length exactly `k` with the maximum average value.

- **Input:** `nums` (integers), `k`
- **Output:** maximum average as `double`
- **Valid answer:** max over all windows of size `k` of `(sum / k)`
- **Edges:** `k = n`; negatives; single element

**Prerequisite note:** Sliding window specializes **two pointers** into a contiguous `[left, right]` segment whose validity is maintained as `right` advances (and `left` may follow). Here both ends move in lockstep because the window length is fixed.

## 2. Intuition
Average is sum divided by fixed `k`, so maximizing average ≡ maximizing sum. Adjacent windows of size `k` share `k−1` elements — update sum in O(1) per slide.

## 3. Brute Force → Optimal
- **Brute:** sum each window from scratch — O(N·K).
- **Optimal:** fixed sliding window — O(N).

## 4. Data Structure / Approach Justification
Two integers: running `window` sum and `best` sum. No extra DS.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested sum loops | O(N·K) |
| Prefix sums | O(N) time too, but O(N) space |

## 5. Logic Walkthrough
1. Sum first `k` elements → `window`, `best`.
2. For `i = k..n−1`: `window += nums[i] − nums[i−k]`; update `best`.
3. Return `best / k` as double.

## 6. Dry Run
`nums=[1,12,-5,-6,50,3]`, `k=4`
- windows sums: 2 → 51 → 42 → **max sum 51** → average **12.75**

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: each element enters and leaves the window once.

## 8. Trade-offs & Alternatives
Same skeleton as “max sum of size K.” Prefix sums help if many offline range queries arrive later.

## 9. Common Mistakes / Edge Cases
Integer overflow on large sums (use `long long`); dividing early and comparing floats; `k = 1`.

## 10. Interview Follow-ups / Variations
Max sum of size K; minimum average; variable-length average with constraints.

## 11. Tags
`sliding-window`, `fixed-window`, `array`, `leetcode-643`, `easy`
