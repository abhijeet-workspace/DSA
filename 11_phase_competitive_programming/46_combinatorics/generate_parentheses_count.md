# Generate Parentheses — Count Only

## 1. Problem Statement
Count valid parentheses strings with n pairs (Catalan). Related to [LeetCode 22](https://leetcode.com/problems/generate-parentheses/) but we only return the count.

## 2. Intuition
Valid n-pair strings counted by Catalan number C_n.

## 3. Brute Force → Optimal
- **Brute:** generate all and filter.
- **Optimal:** Catalan formula/DP.

## 4. Data Structure / Approach Justification
**Chosen:** Catalan DP G[0]=1; G[n]=sum G[i]G[n-1-i].

- **Pedagogy:** count-only Catalan; generation lives in backtracking topic.

## 5. Logic Walkthrough
Standard Catalan DP up to n.

## 6. Dry Run
n=3 → 5.

## 7. Time & Space Complexity
Time **O(n^2)**. Space **O(n)**.

## 8. Trade-offs & Alternatives
Formula C(2n,n)/(n+1) is O(n).

## 9. Common Mistakes / Edge Cases
Confusing with total 2n-bit strings.

## 10. Interview Follow-ups / Variations
Score of parentheses; longest valid.

## 11. Tags
`combinatorics`, `catalan`, `difficulty:medium`
