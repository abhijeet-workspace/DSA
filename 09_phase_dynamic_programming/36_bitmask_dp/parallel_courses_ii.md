# Parallel Courses II

## Problem Statement
[LeetCode 1494](https://leetcode.com/problems/parallel-courses-ii/) — n courses with prereqs; take up to k per semester; min semesters.

- **Inputs:** `n`, `relations`, `k`.
- **Output:** min semesters.
- **Valid answer:** bitmask DP over completed set.
- **Edges:** no edges; k=1.

## Intuition
dp[mask] = min semesters to complete mask; from mask, take subset of available <=k.

## Brute Force → Optimal
- **Brute:** schedule search.
- **Optimal:** O(3^n) or O(2^n * n) with care.

## Data Structure / Approach Justification
**Chosen:** iterate masks; enumerate submasks of canTake.

## Logic Walkthrough
Prereq mask per course; only take if prereqs in mask.

## Dry Run
n=4, relations=[[2,1],[3,1],[1,4]], k=2 -> **3**.

## Time & Space Complexity
Time **O(3^n)**. Space **O(2^n)**. Why: submask enumeration (section 4).

## Trade-offs & Alternatives
n<=15 typical.

## Common Mistakes / Edge Cases
Taking courses without prereqs; exceeding k.

## Interview Follow-ups / Variations
Course Schedule; bitmask subset DP.

## Tags
`bitmask-dp`, `leetcode-1494`, `difficulty:hard`
