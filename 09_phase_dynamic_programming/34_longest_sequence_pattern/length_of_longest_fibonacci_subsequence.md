# Length of Longest Fibonacci Subsequence

## Problem Statement
[LeetCode 873](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/) — longest Fibonacci-like subsequence (len>=3) or 0.

- **Inputs:** strictly increasing `arr`.
- **Output:** length or 0.
- **Valid answer:** max Fib-like subsequence length.
- **Edges:** no Fib seq; short arrays.

## Intuition
For each pair (i,j) extend while sum exists via set.

## Brute Force → Optimal
- **Brute:** all pairs + extend.
- **Optimal:** O(N^2) with hash set.

## Data Structure / Approach Justification
**Chosen:** unordered_set membership; try all starts.

## Logic Walkthrough
For i<j: extend while x+y in set; track len.

## Dry Run
[1,2,3,4,5,6,7,8] -> **5**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(N)**. Why: pairs (section 4).

## Trade-offs & Alternatives
DP on pairs also works.

## Common Mistakes / Edge Cases
Returning 2; not requiring length >=3.

## Interview Follow-ups / Variations
Longest Arithmetic Subsequence (1027).

## Tags
`lis`, `leetcode-873`, `difficulty:medium`
