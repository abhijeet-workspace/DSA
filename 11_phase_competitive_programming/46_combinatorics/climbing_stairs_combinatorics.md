# Climbing Stairs (Combinatorics View)

## 1. Problem Statement
[LeetCode 70](https://leetcode.com/problems/climbing-stairs/) — n stairs, steps of 1 or 2; count ways. Framed as summing C(n-k,k) over k two-steps.

## 2. Intuition
If take k doubles, need n-2k singles; orderings C(n-k, k).

## 3. Brute Force → Optimal
- **Brute:** recursion.
- **Optimal:** Fibonacci DP or sum of binomials.

## 4. Data Structure / Approach Justification
**Chosen:** sum_k C(n-k, k).

- **Pedagogy:** combinatorics lens on a classic 1D-DP problem; 1D DP topic owns the Fibonacci recurrence framing.

## 5. Logic Walkthrough
For k=0..n//2 add binomial(n-k, k).

## 6. Dry Run
n=3 → 3.

## 7. Time & Space Complexity
Time **O(n^2)** with naive binomial or better with running nCr. Space **O(1)**.

## 8. Trade-offs & Alternatives
Fibonacci O(n) is simpler in interviews.

## 9. Common Mistakes / Edge Cases
Wrong upper bound on k.

## 10. Interview Follow-ups / Variations
Steps of size 1..m → generalized stars/bars / DP.

## 11. Tags
`combinatorics`, `binomial`, `leetcode-70`, `difficulty:easy`
