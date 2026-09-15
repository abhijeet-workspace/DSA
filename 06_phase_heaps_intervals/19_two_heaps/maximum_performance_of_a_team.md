# Maximum Performance of a Team

## 1. Problem Statement
[LeetCode 1383](https://leetcode.com/problems/maximum-performance-of-a-team/) — performance = sum(speed) * min(efficiency) of chosen ≤k engineers; maximize; return mod 1e9+7.

- **Inputs:** `n`, `speed`, `efficiency`, `k`.
- **Output:** max performance mod 1e9+7.
- **Valid answer:** fix min-efficiency engineer as bottleneck; pick top speeds among higher/equal efficiency.
- **Edges:** k=1; k=n; large products need 64-bit.

## 2. Intuition
Sort by efficiency descending so current engineer is the min-efficiency in the team. Keep a min-heap of speeds to retain at most k members with max speed sum.

## 3. Brute Force → Optimal
- **Brute:** all subsets ≤k — exponential.
- **Optimal:** sort + min-heap — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort by efficiency + min-heap of speeds.

- **vs two heaps:** same “sort key + bounded heap” pattern as hire-k / subsequence score.

## 5. Logic Walkthrough
Sort desc efficiency. Add speed; if size>k drop smallest speed. Update best with sumSpeed * currentEfficiency.

## 6. Dry Run
speed `[2,10,3,1,5,8]`, eff `[5,4,3,9,7,2]`, k=2 → **60**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(K)**. Why: each engineer processed once with heap ops (section 4).

## 8. Trade-offs & Alternatives
Mod only at the end on the best value (use 64-bit for products).

## 9. Common Mistakes / Edge Cases
Modding intermediate products incorrectly; sorting ascending; heap of efficiencies.

## 10. Interview Follow-ups / Variations
Maximum Subsequence Score (2542); Minimum Cost to Hire K Workers (857).

## 11. Tags
`heap`, `greedy`, `sorting`, `leetcode-1383`, `difficulty:hard`
