# Combinations Count C(n,k)

## 1. Problem Statement
[LeetCode 77](https://leetcode.com/problems/combinations/) asks to generate; here return only C(n,k) as the combinatorial core.

## 2. Intuition
Multiplicative formula C(n,k)=Π (n-i+1)/i.

## 3. Brute Force → Optimal
- **Brute:** generate all.
- **Optimal:** O(k) multiply.

## 4. Data Structure / Approach Justification
**Chosen:** multiplicative nCr.

- **Pedagogy:** counting only; generation is subsets/backtracking topic.

## 5. Logic Walkthrough
Iterate i=1..k multiply (n-k+i)/i with integer-safe order.

## 6. Dry Run
C(5,3)=10.

## 7. Time & Space Complexity
Time **O(k)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Precompute for many queries.

## 9. Common Mistakes / Edge Cases
Not reducing fraction carefully.

## 10. Interview Follow-ups / Variations
Next combination iteration.

## 11. Tags
`combinatorics`, `binomial`, `difficulty:easy`
