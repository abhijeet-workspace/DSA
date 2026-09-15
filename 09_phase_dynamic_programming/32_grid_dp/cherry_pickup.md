# Cherry Pickup

## Problem Statement
[LeetCode 741](https://leetcode.com/problems/cherry-pickup/) — collect max cherries going (0,0)→(n-1,n-1) then back; thorns `-1`; cells emptied when picked.

- **Inputs:** `n×n` grid with `0/1/-1`.
- **Output:** max cherries (or 0 if impossible).
- **Valid answer:** one person round-trip ≡ two people moving to end simultaneously.
- **Edges:** blocked start/end; no path; n=1.

## Intuition
Two people move from start to end in lockstep; shared cell counted once.

## Brute Force → Optimal
- **Brute:** enumerate both paths — exponential.
- **Optimal:** 3D DP on `(r1,c1,r2)` with `c2 = r1+c1-r2`.

## Data Structure / Approach Justification
**Chosen:** memo `dp[r1][c1][r2]` max cherries for two agents.

- **vs two separate passes:** wrong — order of emptying interacts.
- **vs 4D:** reducible by equal Manhattan steps.

## Logic Walkthrough
At each step both move right or down; add cherries; thorn → -INF.

## Dry Run
`[[0,1,-1],[1,0,-1],[1,1,1]]` → **5**.

## Time & Space Complexity
Time **O(N³)**. Space **O(N³)**. Why: O(N³) states, O(1) transitions (section 4).

## Trade-offs & Alternatives
Hard interview problem; start with Unique Paths / Min Path Sum.

## Common Mistakes / Edge Cases
Double-counting same cell; not handling `-1`; wrong coordinate coupling.

## Interview Follow-ups / Variations
Cherry Pickup II (1463); grid path DP family.

## Tags
`2d-dp`, `grid-dp`, `leetcode-741`, `difficulty:hard`
