# Count Subsets With Given Sum

## Problem Statement
Teaching subset-count knapsack — number of subsets of `nums` that sum to `target`. Pattern behind Target Sum (494) after transform.

- **Inputs:** `nums`, `target`.
- **Output:** count of subsets.
- **Valid answer:** 0/1 count DP (empty subset counts for target 0).
- **Edges:** zeros in nums; target 0; no subsets.

## Intuition
`dp[s] += dp[s-x]` descending for each number.

## Brute Force → Optimal
- **Brute:** 2^N subsets.
- **Optimal:** O(N·target) count knapsack.

## Data Structure / Approach Justification
**Chosen:** 1D `dp[0]=1` ways.

- **vs recursion+memo:** same asymptotics.

## Logic Walkthrough
For each num, for s=target…num: dp[s]+=dp[s-num].

## Dry Run
nums=[1,1,2,3], target=4 → **3**.

## Time & Space Complexity
Time **O(N·T)**. Space **O(T)**. Why: count knapsack (section 4).

## Trade-offs & Alternatives
Handle zeros carefully (they double ways).

## Common Mistakes / Edge Cases
Ascending loop; ignoring empty subset for 0.

## Interview Follow-ups / Variations
Target Sum (494); Partition Equal Subset Sum (416).

## Tags
`knapsack`, `subset-sum`, `counting-dp`, `classic`, `difficulty:medium`
