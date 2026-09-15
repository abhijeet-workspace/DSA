# Wiggle Subsequence

## Problem Statement
[LeetCode 376](https://leetcode.com/problems/wiggle-subsequence/) — longest wiggle subsequence (differences alternate sign).

- **Inputs:** `nums`.
- **Output:** length.
- **Valid answer:** max alternating up/down subsequence.
- **Edges:** equals; monotonic.

## Intuition
Greedy peaks/valleys; or DP up/down lengths.

## Brute Force → Optimal
- **Brute:** subsets.
- **Optimal:** O(N) greedy or DP.

## Data Structure / Approach Justification
**Chosen:** up/down ending lengths.

## Logic Walkthrough
If nums[i]>nums[i-1] up=down+1; elif < down=up+1.

## Dry Run
[1,7,4,9,2,5] -> **6**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one pass (section 4).

## Trade-offs & Alternatives
Turbulent is contiguous version.

## Common Mistakes / Edge Cases
Counting equals as flips.

## Interview Follow-ups / Variations
Longest Turbulent Subarray (978).

## Tags
`lis`, `greedy`, `leetcode-376`, `difficulty:medium`
