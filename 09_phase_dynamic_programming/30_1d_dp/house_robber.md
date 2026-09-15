# House Robber

## 1. Problem Statement
[LeetCode 198](https://leetcode.com/problems/house-robber/) — max money from houses in a line; cannot rob two adjacent houses.

- **Inputs:** `vector<int> nums` (loot per house).
- **Output:** max total loot.
- **Valid answer:** best non-adjacent subset sum.
- **Edges:** empty; one house; all zeros; decreasing values.

## 2. Intuition
At house `i`: max(skip = best so far, take = best before previous + `nums[i]`).

## 3. Brute Force → Optimal
- **Brute:** all non-adjacent subsets — exponential.
- **Optimal:** rolling DP — O(N)/O(1).

## 4. Data Structure / Approach Justification
**Chosen:** two scalars (`prev2`, `prev1`) for prefix optima.

- **vs explicit `dp[]`:** clearer for teaching; same time.
- **vs recursion+memo:** fine but more stack / boilerplate.

## 5. Logic Walkthrough
For each `x`: `cur = max(prev1, prev2 + x)`; shift. Return `prev1`.

## 6. Dry Run
`[2,7,9,3,1]`:
- 2 → 2; 7 → max(2,0+7)=7; 9 → max(7,2+9)=11; 3 → max(11,7+3)=11; 1 → max(11,11+1)=12

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: optimal substructure on prefixes (section 4).

## 8. Trade-offs & Alternatives
Keep `dp[]` while learning; compress once recurrence is solid.

## 9. Common Mistakes / Edge Cases
Robbing both neighbors of a skipped house incorrectly; empty/single base cases.

## 10. Interview Follow-ups / Variations
Circular (213); tree version (337).

## 11. Tags
`1d-dp`, `house-robber`, `leetcode-198`, `difficulty:medium`
