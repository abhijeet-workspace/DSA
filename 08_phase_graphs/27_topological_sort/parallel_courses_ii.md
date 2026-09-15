# Parallel Courses II

## 1. Problem Statement
[LeetCode 1494](https://leetcode.com/problems/parallel-courses-ii/) — `n` courses `1..n`, prerequisite pairs, at most `k` courses per semester (prereqs must be done). Return minimum semesters to finish all.

- **Inputs:** `n`, `relations`, `k`.
- **Output:** min semesters.
- **Valid answer:** optimal schedule under parallel limit k.
- **Edges:** k=1; no prereqs; tight chains.

## 2. Intuition
Bitmask DP over sets of completed courses. From mask, find available courses (prereqs ⊆ mask); try all submasks of size ≤k as next semester.

## 3. Brute Force → Optimal
- **Brute:** search schedules — huge.
- **Optimal:** DP on 2^n states with submask enumeration — n≤15.

## 4. Data Structure / Approach Justification
**Chosen:** `dp[mask]` min semesters to achieve mask; prereq bitsets.

- **vs greedy by indegree:** incorrect for this problem.
- **vs topo only:** ignores k-limit optimally.

## 5. Logic Walkthrough
Precompute prereq mask per course. For each mask, compute available; enumerate submasks ≤k; relax `dp[mask|sub]`.

## 6. Dry Run
Sample n=4, k=2 → **3** semesters.

## 7. Time & Space Complexity
Time **O(3^n)**-ish via submasks. Space **O(2^n)**. Why: subset DP (section 4).

## 8. Trade-offs & Alternatives
Meet-in-the-middle not typical; constraints require exponential DP.

## 9. Common Mistakes / Edge Cases
Off-by-one course indices; taking courses without prereqs; greedy mistakes.

## 10. Interview Follow-ups / Variations
Parallel Courses I/III; course schedule with semester limits.

## 11. Tags
`bitmask-dp`, `topological`, `leetcode-1494`, `difficulty:hard`
