# Target Sum

## Problem Statement
[LeetCode 494](https://leetcode.com/problems/target-sum/) — assign `+` or `-` to each number; count ways to reach `target`.

- **Inputs:** `vector<int> nums`, `int target`.
- **Output:** number of sign assignments.
- **Valid answer:** count of ways (0 if impossible).
- **Edges:** `target` out of range; zeros; odd `sum+target`.

## Intuition
Let P be the positive subset. Then `P - (sum-P) = target` ⇒ `P = (sum+target)/2`. Count subsets with that sum (0/1 knapsack).

## Brute Force → Optimal
- **Brute:** try all 2^N sign patterns.
- **Optimal:** subset-sum DP — O(N · S) where S = `(sum+target)/2`.

## Data Structure / Approach Justification
**Chosen:** 1D `dp[s]` ways to make sum `s`, filled backward.

- **vs DFS+memo on index/running sum:** same complexity, more recursion.
- **vs meet-in-the-middle:** useful for larger N; overkill here.

## Logic Walkthrough
If `(sum+target)` odd or `|target|>sum` → 0. Else `need=(sum+target)/2`; 0/1 knapsack count; return `dp[need]`.

## Dry Run
`nums=[1,1,1,1,1]`, `target=3`:
- `sum=5`, `need=(5+3)/2=4` → 5 subsets of size/sum 4 → answer 5

## Time & Space Complexity
Time **O(N · S)**. Space **O(S)**. Why: classic 0/1 knapsack counting (section 4).

## Trade-offs & Alternatives
Offset DP on running sum `[-sum..sum]` is direct but uses more space.

## Common Mistakes / Edge Cases
Parity check; forward knapsack (uses item twice); zeros double-count carefully (still OK with 0/1).

## Interview Follow-ups / Variations
Partition Equal Subset Sum (416); expression add operators.

## Tags
`1d-dp`, `subset-sum`, `knapsack`, `leetcode-494`, `difficulty:medium`
