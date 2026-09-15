# Minimum Number of Work Sessions to Finish the Tasks

## Problem Statement
[LeetCode 1986](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/) — tasks with sessionTime; min sessions (bin packing).

- **Inputs:** `tasks`, `sessionTime`.
- **Output:** min sessions.
- **Valid answer:** pack tasks into bins of capacity sessionTime.
- **Edges:** all fit one; each alone.

## Intuition
Bitmask DP: min sessions for subset; or DFS assign.

## Brute Force → Optimal
- **Brute:** partitions.
- **Optimal:** O(3^n) / O(n*2^n) DP.

## Data Structure / Approach Justification
**Chosen:** dp[mask] = min sessions; try pack remaining.

## Logic Walkthrough
n<=14 typical for bitmask.

## Dry Run
[1,2,3], sessionTime=3 -> **2**.

## Time & Space Complexity
Time **O(3^n)** or **O(n*2^n)**. Space **O(2^n)**.

## Trade-offs & Alternatives
First-fit decreasing heuristic not always optimal.

## Common Mistakes / Edge Cases
Exceeding sessionTime.

## Interview Follow-ups / Variations
Bin packing; Parallel Courses II.

## Tags
`bitmask-dp`, `leetcode-1986`, `difficulty:medium`
