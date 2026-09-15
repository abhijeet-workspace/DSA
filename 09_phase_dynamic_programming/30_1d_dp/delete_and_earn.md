# Delete and Earn

## 1. Problem Statement
[LeetCode 740](https://leetcode.com/problems/delete-and-earn/) — pick `nums[i]=x` to earn `x` points, then delete all `x-1` and `x+1`. Return max points.

- **Inputs:** `vector<int> nums`.
- **Output:** maximum points.
- **Edges:** empty; single value; many duplicates; consecutive values.

## 2. Intuition
Taking value `v` earns `v * count(v)` and forbids `v-1` and `v+1` — same recurrence as House Robber on the value line.

## 3. Brute Force → Optimal
- **Brute:** subsets of distinct values with adjacency constraints — exponential.
- **Optimal:** bucket sums + O(maxV) house-robber DP.

## 4. Data Structure / Approach Justification
**Chosen:** `points[v] = v * freq(v)`; rob along `0..maxV`.

| Alternative | Why skip |
|-------------|---------|
| Sort unique + map | Similar; denser code |
| Tree DP | Overkill |

## 5. Logic Walkthrough
1. Aggregate points per value.
2. `cur = max(skip=prev1, take=prev2+points[i])`.
3. Return final `prev1`.

## 6. Dry Run
`[2,2,3,3,3,4]`: points `2→4, 3→9, 4→4`. Rob: take 2s (4) then 4s (4)=8, or take 3s=9 → **9**.

## 7. Time & Space Complexity
- **Time:** O(n + M) where M = max value
- **Space:** O(M)

## 8. Trade-offs & Alternatives
If M ≫ n, compress to sorted unique keys and skip gaps carefully (still house-robber on neighbors).

## 9. Common Mistakes / Edge Cases
Deleting only one neighbor; counting freq instead of `v*freq`; off-by-one on max value.

## 10. Interview Follow-ups / Variations
House Robber II circular; delete range constraints.

## 11. Tags
`1d-dp`, `house-robber`, `leetcode-740`, `difficulty:medium`
