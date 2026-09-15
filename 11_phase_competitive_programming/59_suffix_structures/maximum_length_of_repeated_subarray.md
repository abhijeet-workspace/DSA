# Maximum Length of Repeated Subarray

## 1. Problem Statement
[LeetCode 718](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) — longest common contiguous subarray of two integer arrays.

- **Inputs:** arrays `A`, `B`.
- **Output:** length of LCS contiguous.
- **Edges:** no overlap → 0; identical arrays.

## 2. Intuition
DP `dp[i][j]` = length ending at A[i-1],B[j-1]; or SA on concatenated with separator (LCP across parts).

## 3. Brute Force → Optimal
- **Brute:** all pairs of starts.
- **DP:** O(nm).
- **SA:** O((n+m) log) + LCP scan.

## 4. Data Structure / Approach Justification
**Chosen:** classic DP for clarity.

| Alternative | Note |
|-------------|------|
| Suffix array on A+# +B | Scales better for strings |
| Rolling hash BS | Also common |

**Pedagogy:** LC 718 as DP baseline; SA/hash alternatives live in this suffix track.

## 5. Logic Walkthrough
Fill DP when equal; track max.

## 6. Dry Run
`[1,2,3,2,1]` vs `[3,2,1,4,7]` → `3`.

## 7. Time & Space Complexity
Time **O(nm)**. Space **O(nm)** (rollable to O(m)).

## 8. Trade-offs & Alternatives
Connects to `sa_longest_common_substring`.

## 9. Common Mistakes / Edge Cases
Confusing with non-contiguous LCS.

## 10. Interview Follow-ups / Variations
Generalize to k arrays.

## 11. Tags
`leetcode-718`, `dp`, `lcs-contiguous`, `difficulty:medium`
