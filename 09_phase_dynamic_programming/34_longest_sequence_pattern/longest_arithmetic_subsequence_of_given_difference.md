# Longest Arithmetic Subsequence of Given Difference

## Problem Statement
[LeetCode 1218](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/) — LAS with fixed difference.

- **Inputs:** `arr`, `difference`.
- **Output:** length.
- **Valid answer:** max AP subsequence with that common diff.
- **Edges:** diff=0; negatives.

## Intuition
dp[x] = dp[x-diff]+1 via hashmap left-to-right.

## Brute Force → Optimal
- **Brute:** O(N^2).
- **Optimal:** O(N) map.

## Data Structure / Approach Justification
**Chosen:** unordered_map value->best length ending there.

## Logic Walkthrough
For each x: best[x]=best[x-d]+1; track max.

## Dry Run
[1,2,3,4], difference=1 -> **4**.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: one pass (section 4).

## Trade-offs & Alternatives
Handle missing predecessor as length 1.

## Common Mistakes / Edge Cases
Wrong update order with duplicates.

## Interview Follow-ups / Variations
Longest Arithmetic Subsequence (1027).

## Tags
`lis`, `hashmap`, `leetcode-1218`, `difficulty:medium`
