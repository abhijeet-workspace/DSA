# Minimize the Difference Between Target and Chosen Elements

## Problem Statement
[LeetCode 1981](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/) — pick exactly one element from each row; minimize |sum - target|.

- **Inputs:** `mat`, `target`.
- **Output:** min absolute difference.
- **Valid answer:** one-per-row sum closest to target.
- **Edges:** one row; large values (cap by target+).

## Intuition
Row-by-row reachable sums (group knapsack); prune beyond target+max.

## Brute Force → Optimal
- **Brute:** product of row sizes.
- **Optimal:** set DP per row.

## Data Structure / Approach Justification
**Chosen:** unordered_set of reachable sums; cap at target+maxCell.

- **vs DFS+memo:** similar with pruning.

## Logic Walkthrough
Start {0}; for each row expand by adding each cell.

## Dry Run
mat=[[1,2,3],[4,5,6],[7,8,9]], target=13 → **0**.

## Time & Space Complexity
Time **O(R·C·Σ)**. Space **O(Σ)**. Why: knapsack reachability (section 4).

## Trade-offs & Alternatives
Bitset fast when sums bounded.

## Common Mistakes / Edge Cases
Picking multiple from one row; not capping sum growth.

## Interview Follow-ups / Variations
Closest Dessert Cost (1774).

## Tags
`knapsack`, `leetcode-1981`, `difficulty:medium`
