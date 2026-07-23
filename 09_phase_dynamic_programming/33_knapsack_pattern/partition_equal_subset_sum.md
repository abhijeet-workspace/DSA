# Partition Equal Subset Sum

## Problem Statement
[LeetCode 416](https://leetcode.com/problems/partition-equal-subset-sum/) — return true if `nums` can be split into two subsets with equal sum.

- **Inputs:** `vector<int> nums`.
- **Output:** `bool`.
- **Valid answer:** true iff a subset sums to `total/2` when `total` is even.
- **Edges:** odd total → false; single element; zeros; duplicates.

## Intuition
Equal partition ⇔ subset sum to half. Classic 0/1 knapsack with boolean reachability over capacities.

## Brute Force → Optimal
- **Brute:** all subsets — O(2^N).
- **Optimal:** 1D boolean DP, capacity descending — O(N · S) time, O(S) space (`S = sum/2`).

## Data Structure / Approach Justification
**Chosen:** `vector<char> dp(target+1)`; `dp[s]` = reachable sum `s`.

- **vs 2D `dp[i][s]`:** same idea, more memory.
- **vs bitset:** often faster constants; same ascending/descending discipline.
- **Ascending inner loop:** wrong — turns into unbounded knapsack.

## Logic Walkthrough
Reject odd sum. `dp[0]=1`. For each `x`, for `s = target … x`: `dp[s] |= dp[s-x]`. Return `dp[target]`.

## Dry Run
`[1,5,11,5]`, sum=22, target=11:
- after 1: `{0,1}`
- after 5: `{0,1,5,6}`
- after 11: includes 11 → true (`11` alone or `1+5+5`)

## Time & Space Complexity
Time **O(N · S)**. Space **O(S)**. Why: each item updates all capacities once (section 4).

## Trade-offs & Alternatives
Clear interview DP. Bitset DP for speed; meet-in-the-middle if N is larger and sums huge.

## Common Mistakes / Edge Cases
Ascending capacity loop; forgetting odd-sum early exit; using `int` overflow on large sums without care.

## Interview Follow-ups / Variations
Partition to K equal sums (698); Target Sum (494); Last Stone Weight II (1049).

## Tags
`dp`, `0-1-knapsack`, `subset-sum`, `leetcode-416`, `difficulty:medium`
