# Contains Duplicate II

## 1. Problem Statement
[LeetCode 219](https://leetcode.com/problems/contains-duplicate-ii/) — return true if two distinct indices `i` and `j` exist with `nums[i] == nums[j]` and `|i − j| ≤ k`.

- **Input:** `nums`, integer `k`
- **Output:** bool
- **Valid answer:** any pair within distance `k`
- **Edges:** `k = 0`; all unique; duplicate exactly at distance `k`

**Prerequisite note:** Built on two-pointer / index distance thinking. The “window” is the last `k` positions — values outside that range are irrelevant to the current index.

## 2. Intuition
For each index, ask whether the same value last appeared within the last `k` steps. That is a sliding constraint on index distance.

## 3. Brute Force → Optimal
- **Brute:** check all pairs with `|i−j| ≤ k` — O(N·K).
- **Optimal:** hash map of last index (or set of values in a rolling window) — O(N).

## 4. Data Structure / Approach Justification
`unordered_map<int,int>` value → last index. Equivalent: `unordered_set` of the last `k` values with erase of `nums[i−k−1]`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested pair checks | O(N·K) |
| Sorting by value | Breaks index distances unless careful |

## 5. Logic Walkthrough
1. Scan `i` left → right.
2. If `v` seen and `i − last[v] ≤ k` → true.
3. Update `last[v] = i`.
4. If scan ends → false.

## 6. Dry Run
`[1,2,3,1]`, `k=3` — second `1` at index 3; previous at 0; distance 3 ≤ 3 → **true**.

## 7. Time & Space Complexity
- **Time:** O(N) average
- **Space:** O(min(N, distinct))
- Why: one pass; map stores last occurrence per value.

## 8. Trade-offs & Alternatives
Set-of-window variant stores at most `k+1` values — better when `k ≪ N` and many distinct keys overall.

## 9. Common Mistakes / Edge Cases
Using `< k` instead of `≤ k`; updating map before checking; `k = 0` (only same index, always false for distinct indices).

## 10. Interview Follow-ups / Variations
Contains Duplicate III (absolute value + index constraints); Contains Duplicate (any pair).

## 11. Tags
`sliding-window`, `hash-map`, `leetcode-219`, `easy`
