# Pascal's Triangle II

## 1. Problem Statement
[LeetCode 119](https://leetcode.com/problems/pascals-triangle-ii/) — return row `rowIndex` (0-based) of Pascal's triangle.

## 2. Intuition
Build one row in place with multiplicative updates.

## 3. Brute Force → Optimal
- **Brute:** full triangle.
- **Optimal:** O(k) space row.

## 4. Data Structure / Approach Justification
**Chosen:** in-place rolling row.

- **Pedagogy:** space-optimized binomial row; same algebra as nCr.

## 5. Logic Walkthrough
From right to left: a[j]+=a[j-1].

## 6. Dry Run
rowIndex=3 → [1,3,3,1].

## 7. Time & Space Complexity
Time **O(k^2)**. Space **O(k)**.

## 8. Trade-offs & Alternatives
Direct nCr for each entry also works.

## 9. Common Mistakes / Edge Cases
Updating left-to-right corrupts values.

## 10. Interview Follow-ups / Variations
Modulo prime rows.

## 11. Tags
`combinatorics`, `leetcode-119`, `difficulty:easy`
