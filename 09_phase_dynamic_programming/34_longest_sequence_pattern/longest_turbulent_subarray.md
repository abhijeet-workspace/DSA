# Longest Turbulent Subarray

## Problem Statement
[LeetCode 978](https://leetcode.com/problems/longest-turbulent-subarray/) — longest turbulent contiguous subarray.

- **Inputs:** `arr`.
- **Output:** length.
- **Valid answer:** max window with strict alternating inequality.
- **Edges:** equals; length 1.

## Intuition
Two running lengths for ending with up vs down comparison.

## Brute Force → Optimal
- **Brute:** check all subarrays.
- **Optimal:** O(N) one pass.

## Data Structure / Approach Justification
**Chosen:** reset/extend based on sign of arr[i]-arr[i-1].

## Logic Walkthrough
If equal reset to 1; else flip expected comparison and grow.

## Dry Run
[9,4,2,10,7,8,8,1,9] -> **5**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: single scan (section 4).

## Trade-offs & Alternatives
Wiggle Subsequence is subsequence not subarray.

## Common Mistakes / Edge Cases
Treating equals as turbulent.

## Interview Follow-ups / Variations
Wiggle Subsequence (376).

## Tags
`dp`, `array`, `leetcode-978`, `difficulty:medium`
