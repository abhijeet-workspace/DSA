# Arranging Coins (LC 441)

## 1. Problem Statement
[LeetCode 441 — Arranging Coins](https://leetcode.com/problems/arranging-coins/): you have `n` coins; row i needs i coins. How many complete rows can you build?

- **Inputs:** nonnegative `n`.
- **Output:** max k with k(k+1)/2 ≤ n.
- **Edges:** n=0/1.

## 2. Intuition
Triangular numbers; binary search k or closed form floor((-1+√(1+8n))/2).

## 3. Brute Force → Optimal
- **Brute:** subtract 1,2,3,… until coins run out.
- **Optimal:** binary search / formula — O(log n).

## 4. Data Structure / Approach Justification
**Chosen:** binary search on k with mid*(mid+1)/2.

**Pedagogy:** integer math / triangular inverse — number-theory-ish CP pattern (avoid float error).

## 5. Logic Walkthrough
lo=0,hi=n; while lo≤hi mid; if mid(mid+1)/2 ≤ n lo=mid+1 else hi=mid-1; return hi.

## 6. Dry Run
`n=5` → rows 1+2 leftover 2 → **2**. `n=8` → **3**.

## 7. Time & Space Complexity
Time **O(log n)**, space **O(1)**.

## 8. Trade-offs & Alternatives
Quadratic formula needs careful long double / integer sqrt.

## 9. Common Mistakes / Edge Cases
Overflow on mid*(mid+1); using int for n=2e9.

## 10. Interview Follow-ups / Variations
k-simple polytopic numbers; coin rows with cost a·i.

## 11. Tags
`binary-search`, `math`, `leetcode-441`, `difficulty:easy`
