# 4Sum II (LC 454)

## 1. Problem Statement
Count tuples (i,j,k,l) with `A[i]+B[j]+C[k]+D[l]==0`.

- **Inputs:** four arrays of equal length.
- **Output:** number of tuples.
- **Valid answer:** [LC 454](https://leetcode.com/problems/4sum-ii/).
- **Edges:** zeros; large negatives.
- **Link:** [LC 454](https://leetcode.com/problems/4sum-ii/)

## 2. Intuition
Canonical MITM: hash all A+B sums; probe -(C+D).

## 3. Brute Force → Optimal
- **Brute:** O(N^4).
- **MITM hash:** O(N²).

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_map` of A[i]+B[j] frequencies.

| Alternative | Note |
|-------------|------|
| Sort+two pointers | Harder with four arrays |

## 5. Logic Walkthrough
1. Map all sums A+B.
2. For each C+D, add map[-sum].

## 6. Dry Run
`A=B=C=D=[1,-1]` → **16**? Actually classic example `[1,2],[-2,-1],[-1,2],[0,2]` → 2.

## 7. Time & Space Complexity
**O(N²)** time/space.

## 8. Trade-offs & Alternatives
Poster-child MITM on LeetCode.

## 9. Common Mistakes / Edge Cases
Using set instead of multiset counts.

## 10. Interview Follow-ups / Variations
k arrays; modulo.

## 11. Tags
`meet-in-the-middle`, `hashmap`, `lc-454`, `difficulty:medium`
