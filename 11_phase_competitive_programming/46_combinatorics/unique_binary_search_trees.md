# Unique Binary Search Trees

## 1. Problem Statement
[LeetCode 96](https://leetcode.com/problems/unique-binary-search-trees/) — count structurally unique BSTs with n distinct keys (Catalan).

## 2. Intuition
G_n = sum G_i G_{n-1-i}; also Catalan C_n = (1/(n+1))C(2n,n).

## 3. Brute Force → Optimal
- **Brute:** recurse structures.
- **Optimal:** DP Catalan or binomial Catalan formula.

## 4. Data Structure / Approach Justification
**Chosen:** Catalan via binomial.

- **Pedagogy:** Catalan number application; tree DP topic may rebuild via root-split DP without naming Catalan.

## 5. Logic Walkthrough
Compute C(2n,n)/(n+1) carefully with integers.

## 6. Dry Run
n=3 → 5.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
DP transition clearer for variants (unique BST II).

## 9. Common Mistakes / Edge Cases
Division order causing non-integer intermediate.

## 10. Interview Follow-ups / Variations
Catalan applications: parentheses, paths not above diagonal.

## 11. Tags
`combinatorics`, `catalan`, `leetcode-96`, `difficulty:medium`
