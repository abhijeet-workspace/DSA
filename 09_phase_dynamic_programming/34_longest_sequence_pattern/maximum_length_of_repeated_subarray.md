# Maximum Length of Repeated Subarray

## Problem Statement
[LeetCode 718](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) — longest common contiguous subarray length.

- **Inputs:** `nums1`, `nums2`.
- **Output:** length.
- **Valid answer:** max common subarray length.
- **Edges:** no overlap; identical.

## Intuition
2D DP: if equal dp[i][j]=dp[i-1][j-1]+1 else 0; track max.

## Brute Force → Optimal
- **Brute:** all subarrays.
- **Optimal:** O(NM) DP; rolling 1D.

## Data Structure / Approach Justification
**Chosen:** 1D rolling from back.

## Logic Walkthrough
Match extends diagonal; mismatch resets.

## Dry Run
[1,2,3,2,1] vs [3,2,1,4,7] -> **3**.

## Time & Space Complexity
Time **O(NM)**. Space **O(min)**. Why: classic DP (section 4).

## Trade-offs & Alternatives
Not the same as LCS (non-contiguous).

## Common Mistakes / Edge Cases
Using LCS recurrence without reset.

## Interview Follow-ups / Variations
LCS (1143).

## Tags
`dp`, `leetcode-718`, `difficulty:medium`
