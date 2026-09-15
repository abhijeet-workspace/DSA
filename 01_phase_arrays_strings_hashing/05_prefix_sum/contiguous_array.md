# Contiguous Array

## Problem Statement
[LeetCode 525](https://leetcode.com/problems/contiguous-array/) — find the maximum length of a contiguous subarray with an equal number of `0`s and `1`s.

- **Input:** binary `vector<int> nums`
- **Output:** max length (0 if none)
- **Edges:** all zeros; all ones; single element; entire array balanced

## Intuition
Map `0 → -1`, `1 → +1`. Equal zeros and ones ⇔ subarray sum `0`. Store the **first** index of each prefix sum; when the same sum reappears, the span between them has sum 0.

## Brute Force → Optimal
- **Brute:** check every subarray balance — O(N²).
- **Optimal:** prefix sum + hashmap of first occurrence — O(N).

## Data Structure / Approach Justification
`unordered_map<int,int>`: prefix → earliest index. Seed `0 → -1` so a prefix from the start is covered.

| Alternative | Why it loses here |
|-------------|-------------------|
| Count zeros/ones per window naively | Quadratic |
| Keep only last index | Misses longest (need first index) |

## Logic Walkthrough
1. Running `sum += (nums[i]==0 ? -1 : 1)`.
2. If `sum` seen before, `best = max(best, i - firstIndex[sum])`.
3. Else record `firstIndex[sum] = i`.

## Dry Run
`[0,1,0,1]`: sums `-1,0,-1,0`. At i=1 sum 0 with first -1 → length 2; at i=3 sum 0 → length **4**.

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for distinct prefixes
- Why: one pass; map stores O(N) sums worst case.

## Trade-offs & Alternatives
Last-seen index finds *some* balanced subarray but not the longest. Counting approach without remap is equivalent if you track `#1 - #0`.

## Common Mistakes / Edge Cases
Updating map before computing length (overwrites first index); forgetting seed `0→-1`; using last index of prefix.

## Interview Follow-ups / Variations
Count number of balanced subarrays; equal number of two characters in a string.

## Tags
`prefix-sum`, `hash-map`, `binary-array`, `leetcode-525`, `medium`
