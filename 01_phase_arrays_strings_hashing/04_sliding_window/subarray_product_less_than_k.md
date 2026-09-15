# Subarray Product Less Than K

## 1. Problem Statement
[LeetCode 713](https://leetcode.com/problems/subarray-product-less-than-k/) — count contiguous subarrays whose product is strictly less than `k`.

- **Input:** `nums` (positive integers), `k`
- **Output:** count of valid subarrays
- **Valid answer:** number of windows with product `< k`
- **Edges:** `k ≤ 1` → 0; single elements; whole array product still `< k`

**Prerequisite note:** Classic variable window on a two-pointer base. Because products grow with window length (positives), shrinking restores the invariant `product(window) < k`.

## 2. Intuition
For each `right`, maintain the longest window ending at `right` with product `< k`. Every subarray ending at `right` that starts in `[left, right]` is valid — add `right − left + 1`.

## 3. Brute Force → Optimal
- **Brute:** all subarrays, multiply — O(N²).
- **Optimal:** sliding window count trick — O(N).

## 4. Data Structure / Approach Justification
Running `product` + `left` pointer. Use `long long` to avoid overflow while multiplying.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested multiply | O(N²) |
| Log-sum / binary search | More fragile numerically |

## 5. Logic Walkthrough
1. If `k ≤ 1` return 0.
2. Multiply in `nums[right]`; while `product ≥ k`, divide out `nums[left]`, `++left`.
3. `count += right − left + 1`.

## 6. Dry Run
`[10,5,2,6]`, `k=100` — valid windows yield total **8**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: each index enters/leaves once; answer is a count.

## 8. Trade-offs & Alternatives
Same “count endings at right” pattern appears in “nice subarrays” / “binary subarrays with sum” via `atMost` differences.

## 9. Common Mistakes / Edge Cases
Forgetting `k ≤ 1`; integer overflow; counting only maximal windows instead of all endings.

## 10. Interview Follow-ups / Variations
Sum less than K; product ≤ K; at most K distinct (count version).

## 11. Tags
`sliding-window`, `counting`, `variable-window`, `leetcode-713`, `medium`
