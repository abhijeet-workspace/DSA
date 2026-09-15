# Length of the Longest Subsequence That Sums to Target

## Problem Statement
[LeetCode 2915](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/) — longest subsequence length summing exactly to `target` (or -1).

- **Inputs:** `nums`, `target`.
- **Output:** max length or -1.
- **Valid answer:** 0/1 knapsack maximizing count for exact sum.
- **Edges:** impossible; single hit.

## Intuition
`dp[s] = max length achieving sum s`; take/skip each num once.

## Brute Force → Optimal
- **Brute:** subsets.
- **Optimal:** O(N·target) max-length knapsack.

## Data Structure / Approach Justification
**Chosen:** `dp[0]=0`, rest -INF; descending updates dp[s]=max(dp[s], dp[s-x]+1).

- **vs unbounded:** would reuse numbers incorrectly.

## Logic Walkthrough
Init; for each x update descending; answer dp[target] or -1.

## Dry Run
nums=[1,2,3,4,5], target=9 → **3**.

## Time & Space Complexity
Time **O(N·T)**. Space **O(T)**. Why: 0/1 knapsack (section 4).

## Trade-offs & Alternatives
Track predecessors if you need the subsequence itself.

## Common Mistakes / Edge Cases
Ascending reuse; returning 0 instead of -1.

## Interview Follow-ups / Variations
Count subsets; Coin Change length variants.

## Tags
`knapsack`, `leetcode-2915`, `difficulty:medium`
