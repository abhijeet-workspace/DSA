# Running Sum of 1d Array

## Problem Statement
[LeetCode 1480](https://leetcode.com/problems/running-sum-of-1d-array/) — return `runningSum` where `runningSum[i] = sum(nums[0]…nums[i])`.

- **Inputs:** `vector<int> nums`.
- **Output:** prefix sums vector same length.
- **Edges:** single element; negatives.

## Intuition
Each prefix is previous prefix plus current element — classic 1D prefix sum.

## Brute Force → Optimal
- **Brute:** for each `i`, sum `0..i` — O(N²).
- **Optimal:** one left-to-right accumulation — O(N).

## Data Structure / Approach Justification
**Chosen:** in-place or new array prefix (folder: `05_prefix_sum`).

## Logic Walkthrough
`ans[0] = nums[0]`; for `i>=1`, `ans[i] = ans[i-1] + nums[i]`.

## Dry Run
`[1,2,3,4]` → `[1,3,6,10]`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** aux if mutating / O(N) for new array.

## Trade-offs & Alternatives
In-place overwrite of `nums` saves allocation when mutation allowed.

## Common Mistakes / Edge Cases
Starting loop at `0` and reading `ans[-1]`; empty input.

## Interview Follow-ups / Variations
Range Sum Query (303); Product of Array Except Self (238).

## Tags
`prefix-sum`, `array`, `leetcode-1480`, `difficulty:easy`
