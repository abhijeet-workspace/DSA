# Binary Subarrays With Sum

## Problem Statement
[LeetCode 930](https://leetcode.com/problems/binary-subarrays-with-sum/) — count binary subarrays whose sum equals `goal`.

- **Input:** binary `nums`, integer `goal`
- **Output:** number of subarrays with sum `goal`
- **Edges:** `goal = 0` (all-zero windows); `goal` larger than total ones; single 1

## Intuition
Number with sum **exactly** `goal` = number with sum **at most** `goal` minus **at most** `goal-1`. On a binary array, the sliding window for “at most” is easy because sum only changes by 0/1.

Alternatively: prefix sum + hashmap counting previous prefixes equal to `cur - goal`.

## Brute Force → Optimal
- **Brute:** all subarrays — O(N²).
- **Optimal:** `atMost` twice, or prefix hashmap — O(N).

## Data Structure / Approach Justification
Two-pointer `atMost` (chosen here): expand right, shrink while `sum > goal`, add `right-left+1` windows ending at `right`.

| Alternative | Why choose / lose |
|-------------|-------------------|
| Prefix + hashmap | Also O(N); more space; works for general integers |
| Nested loops | Too slow |

## Logic Walkthrough
1. Implement `atMost(g)`: count subarrays with sum ≤ g.
2. Return `atMost(goal) - atMost(goal - 1)` (treat `goal-1 < 0` as 0).

## Dry Run
`[1,0,1,0,1]`, goal 2: exact windows are four → **4**. All zeros length 5, goal 0 → C(5,2)+5 = **15**.

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) for atMost approach
- Why: each index moves at most once per `atMost` call.

## Trade-offs & Alternatives
Hashmap generalizes beyond binary arrays (like Subarray Sum Equals K). `atMost` trick needs non-negative elements.

## Common Mistakes / Edge Cases
`goal == 0` handling; forgetting `goal-1 < 0`; counting windows incorrectly as 1 instead of `right-left+1`.

## Interview Follow-ups / Variations
Subarray Sum Equals K (560); Count Number of Nice Subarrays (1248) — same atMost pattern.

## Tags
`prefix-sum`, `sliding-window`, `binary-array`, `leetcode-930`, `medium`
