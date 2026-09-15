# Pascal's Triangle

## 1. Problem Statement
[LeetCode 118](https://leetcode.com/problems/pascals-triangle/) — return first numRows of Pascal's triangle.

## 2. Intuition
Each entry C(r,k) = C(r-1,k-1)+C(r-1,k).

## 3. Brute Force → Optimal
- **Brute:** compute each C(r,k) independently.
- **Optimal:** build row from previous.

## 4. Data Structure / Approach Justification
**Chosen:** row-by-row addition.

- **Pedagogy:** concrete binomial coefficient table; nCr_mod_prime later reuses the algebraic view.

## 5. Logic Walkthrough
row[0]=1; for j from end: row[j]+=row[j-1].

## 6. Dry Run
numRows=5 → [[1],[1,1],[1,2,1],...]

## 7. Time & Space Complexity
Time **O(numRows^2)**. Space **O(numRows^2)** output.

## 8. Trade-offs & Alternatives
Multiplicative nCr for a single entry is faster for one query.

## 9. Common Mistakes / Edge Cases
Off-by-one row length.

## 10. Interview Follow-ups / Variations
Pascal triangle II (only row k).

## 11. Tags
`combinatorics`, `binomial`, `leetcode-118`, `difficulty:easy`
