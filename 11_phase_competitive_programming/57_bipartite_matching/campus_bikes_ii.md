# Campus Bikes II

## 1. Problem Statement
[LeetCode 1066](https://leetcode.com/problems/campus-bikes-ii/) (premium) — assign each worker a unique bike minimizing total Manhattan distance.

- **Inputs:** `workers`, `bikes` coordinates (`n≤m≤10`).
- **Output:** minimum total distance.
- **Edges:** n=1; far bikes.

## 2. Intuition
Minimum-cost assignment; bitmask DP over taken bikes.

## 3. Brute Force → Optimal
- **Brute:** P(m,n) assignments.
- **Optimal:** DP O(n·2^m·m) / Hungarian.

## 4. Data Structure / Approach Justification
**Chosen:** bitmask DP (worker index = popcount(mask)).

| Alternative | Note |
|-------------|------|
| Hungarian | O(m³) |
| LC 1057 | Greedy different rule |

## 5. Logic Walkthrough
For each mask, next worker is `popcount(mask)`; try unused bikes.

## 6. Dry Run
Sample → total distance `6`.

## 7. Time & Space Complexity
Time **O(m·2^m)** roughly. Space **O(2^m)**.

## 8. Trade-offs & Alternatives
Weighted bipartite matching special case.

## 9. Common Mistakes / Edge Cases
Using Euclidean; reusing bikes.

## 10. Interview Follow-ups / Variations
LC 1057 Campus Bikes (priority pairing).

## 11. Tags
`leetcode-1066`, `assignment`, `bitmask-dp`, `difficulty:medium`
