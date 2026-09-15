# Two City Scheduling

## 1. Problem Statement
[LeetCode 1029](https://leetcode.com/problems/two-city-scheduling/) — `2n` people; send exactly `n` to city A and `n` to B; minimize total flight cost.

- **Inputs:** `costs[i] = [costA, costB]`.
- **Output:** minimum total cost.
- **Valid answer:** optimal assignment sum.
- **Edges:** `n=1`; large A-B gaps; ties on `costA-costB`.

## 2. Intuition
Refund thinking: send all to B, then pick `n` people with largest savings for switching to A — equivalent to sorting by `costA - costB` ascending and taking first `n` as A.

## 3. Brute Force → Optimal
- **Brute:** choose any `n` for A — C(2n,n).
- **Optimal:** sort by `costA-costB` — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort comparator on `a[0]-a[1]`; first half A, second half B.

- **vs DP knapsack of “how many sent to A”:** O(N²); correct but slower.
- **vs heap of savings:** same greedy idea.

## 5. Logic Walkthrough
Sort so most A-favoring diffs come first. Sum `costs[i][0]` for `i<n`, `costs[i][1]` for `i>=n`.

## 6. Dry Run
`[[10,20],[30,200],[400,50],[30,20]]`: diffs −10, −170, +350, +10 → A gets first two after sort → cost **110**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra. Why: sort + one sum pass (section 4).

## 8. Trade-offs & Alternatives
DP clarifies “exactly n to A” for teaching; greedy is interview-expected.

## 9. Common Mistakes / Edge Cases
Sorting by absolute cost only; sending all cheaper-A without balancing count `n`.

## 10. Interview Follow-ups / Variations
Three cities; capacity constraints per city.

## 11. Tags
`greedy`, `sorting`, `leetcode-1029`, `difficulty:medium`
