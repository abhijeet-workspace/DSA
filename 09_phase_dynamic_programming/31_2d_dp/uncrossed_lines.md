# Uncrossed Lines

## Problem Statement
[LeetCode 1035](https://leetcode.com/problems/uncrossed-lines/) — max number of connecting lines between equal nums in two arrays that do not cross.

- **Inputs:** `nums1`, `nums2`.
- **Output:** max uncrossed lines.
- **Valid answer:** equivalently LCS length on the two sequences.
- **Edges:** empty; no matches; identical.

## Intuition
Non-crossing equal pairs = LCS. Same recurrence as LC 1143.

## Brute Force → Optimal
- **Brute:** subsets of matches checking crossings — exponential.
- **Optimal:** LCS DP O(NM).

## Data Structure / Approach Justification
**Chosen:** classic LCS DP on prefixes.

- **vs greedy nearest match:** can cross / suboptimal.

## Logic Walkthrough
Match → diag+1; else max(skip nums1, skip nums2).

## Dry Run
`[1,4,2]` vs `[1,2,4]` → **2**.

## Time & Space Complexity
Time **O(NM)**. Space **O(NM)** or **O(min)**. Why: LCS table (section 4).

## Trade-offs & Alternatives
Same code as Longest Common Subsequence; rename for story.

## Common Mistakes / Edge Cases
Allowing crossings; confusing with LIS.

## Interview Follow-ups / Variations
LCS (1143); Max Dot Product of Two Subsequences (1458).

## Tags
`2d-dp`, `lcs`, `leetcode-1035`, `difficulty:medium`
