# Largest Divisible Subset

## Problem Statement
[LeetCode 368](https://leetcode.com/problems/largest-divisible-subset/) — largest subset where every pair a|b or b|a.

- **Inputs:** `nums` distinct positives.
- **Output:** any largest divisible subset.
- **Valid answer:** chain under divisibility after sort.
- **Edges:** singles; primes only.

## Intuition
Sort; LIS where extend if nums[i]%nums[j]==0.

## Brute Force → Optimal
- **Brute:** subsets.
- **Optimal:** O(N^2) DP + parent reconstruct.

## Data Structure / Approach Justification
**Chosen:** dp[i] size ending at i; prev[i] parent.

## Logic Walkthrough
Sort; for j<i if divisible update; reconstruct from best end.

## Dry Run
[1,2,3] -> [1,2] or [1,3].

## Time & Space Complexity
Time **O(N^2)**. Space **O(N)**. Why: LIS-style (section 4).

## Trade-offs & Alternatives
Return any max subset.

## Common Mistakes / Edge Cases
Forgetting sort.

## Interview Follow-ups / Variations
LIS (300).

## Tags
`lis`, `leetcode-368`, `difficulty:medium`
