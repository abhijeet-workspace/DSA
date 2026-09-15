# 4Sum (LC 18) — MITM Framing

## 1. Problem Statement
Find all unique quadruplets summing to `target`.

- **Inputs:** array `nums`, target.
- **Output:** unique quadruplets.
- **Valid answer:** [LC 18](https://leetcode.com/problems/4sum/).
- **MITM framing:** pair sums on two halves / two-pointer after sort — related family to MITM.
- **Link:** [LC 18](https://leetcode.com/problems/4sum/)

## 2. Intuition
Sort + two loops + two pointers (standard). MITM view: all pair sums from left indices vs right.

## 3. Brute Force → Optimal
- **Brute:** O(N^4).
- **Sort+2ptr:** O(N³).
- **Hash pair MITM:** O(N²).

## 4. Data Structure / Approach Justification
**Chosen:** classic O(N³) LC solution for clarity.

| Alternative | Note |
|-------------|------|
| Hash all pairs | MITM flavor, careful uniqueness |

## 5. Logic Walkthrough
1. Sort.
2. Fix i,j; two pointers l,r.
3. Skip duplicates.

## 6. Dry Run
`[1,0,-1,0,-2,2]`, target 0 → classic quads.

## 7. Time & Space Complexity
**O(N³)** time.

## 8. Trade-offs & Alternatives
Interview-standard; mention pair-hash MITM as variant.

## 9. Common Mistakes / Edge Cases
Duplicate quads; overflow.

## 10. Interview Follow-ups / Variations
k-sum generalization; MITM hash.

## 11. Tags
`two-pointers`, `k-sum`, `lc-18`, `mitm-framing`, `difficulty:medium`
