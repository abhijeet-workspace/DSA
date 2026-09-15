# Minimum Falling Path Sum

## Problem Statement
[LeetCode 931](https://leetcode.com/problems/minimum-falling-path-sum/) — n×n grid; falling path picks one per row, next col in {c-1,c,c+1}; minimize sum.

- **Inputs:** `vector<vector<int>> matrix`.
- **Output:** min falling path sum.
- **Valid answer:** any valid adjacency path sum optimal.
- **Edges:** n=1; large negatives.

## Intuition
Bottom-up from last row: each cell += min of three possible below.

## Brute Force → Optimal
- **Brute:** DFS — exponential.
- **Optimal:** O(N²) DP.

## Data Structure / Approach Justification
**Chosen:** in-place from bottom.

- **vs II (1289):** next col cannot be same.

## Logic Walkthrough
For row from n-2→0, for each c take min of valid children.

## Dry Run
[[2,1,3],[6,5,4],[7,8,9]] → **13**.

## Time & Space Complexity
Time **O(N²)**. Space **O(1)** in-place. Why: each cell once (section 4).

## Trade-offs & Alternatives
Keep previous row copy if mutation forbidden.

## Common Mistakes / Edge Cases
Leaving same-column child out incorrectly.

## Interview Follow-ups / Variations
Minimum Falling Path Sum II (1289).

## Tags
`grid-dp`, `leetcode-931`, `difficulty:medium`
