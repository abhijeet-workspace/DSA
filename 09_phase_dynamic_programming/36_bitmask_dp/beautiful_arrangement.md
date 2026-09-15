# Beautiful Arrangement

## Problem Statement
[LeetCode 526](https://leetcode.com/problems/beautiful-arrangement/) — count permutations of 1..n where for each i: perm[i]%i==0 or i%perm[i]==0.

- **Inputs:** `n`.
- **Output:** count.
- **Valid answer:** number of beautiful perms.
- **Edges:** n=1; n=15 max.

## Intuition
Backtracking / bitmask DP over used numbers at position.

## Brute Force → Optimal
- **Brute:** all perms.
- **Optimal:** O(n*2^n) bitmask.

## Data Structure / Approach Justification
**Chosen:** dfs(pos, mask) memo.

## Logic Walkthrough
At position pos try unused num satisfying rule.

## Dry Run
n=2 -> **2**.

## Time & Space Complexity
Time **O(n*2^n)**. Space **O(n*2^n)**. Why: masks (section 4).

## Trade-offs & Alternatives
n<=15.

## Common Mistakes / Edge Cases
1-index positions carefully.

## Interview Follow-ups / Variations
Permute uniqueness; bitmask DFS.

## Tags
`bitmask-dp`, `leetcode-526`, `difficulty:medium`
