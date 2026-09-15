# Ugly Number II (LC 264)

## 1. Problem Statement
[LeetCode 264 — Ugly Number II](https://leetcode.com/problems/ugly-number-ii/): return the `n`-th ugly number (1-indexed; 1 is first).

- **Inputs:** n (1 ≤ n ≤ 1690 typical LC).
- **Output:** n-th number of form 2^a 3^b 5^c.
- **Edges:** n=1 → 1.

## 2. Intuition
Each ugly number comes from a prior one ×2, ×3, or ×5. Three pointers merge like a multi-list.

## 3. Brute Force → Optimal
- **Brute:** scan integers testing LC263 — slow.
- **Optimal:** DP with three indices — O(n).

## 4. Data Structure / Approach Justification
**Chosen:** `dp[i]` + indices i2,i3,i5.

**Pedagogy:** framed as multiplicative number generation / Hamming. Heap-based generation appears under top-k/heaps elsewhere — here we use the classic O(n) three-pointer DP for CP number sequences.

## 5. Logic Walkthrough
dp[0]=1. Next candidates dp[i2]*2, dp[i3]*3, dp[i5]*5; take min; advance all ties.

## 6. Dry Run
`n=10` → sequence … 1,2,3,4,5,6,8,9,10,12 → **12**.

## 7. Time & Space Complexity
Time **O(n)**, space **O(n)**.

## 8. Trade-offs & Alternatives
Priority queue + set also works; more log factors.

## 9. Common Mistakes / Edge Cases
Not advancing all equal pointers → duplicates; off-by-one index.

## 10. Interview Follow-ups / Variations
Super ugly (k primes); nth perfect number variants.

## 11. Tags
`number-theory`, `dp`, `leetcode-264`, `difficulty:medium`
