# Longest Common Substring of K Strings

## 1. Problem Statement
Teaching lab — longest common **contiguous** substring.

For **two** strings: DP (implemented). For **k** strings: build a generalized suffix array of `s1 + #1 + s2 + #2 + …` and find the maximum LCP over a window of SA entries that touches all string ids (not implemented in full here; stated precisely in §4–5).

- **Inputs:** two strings in the runnable lab; k-string method described.
- **Output:** LCS length for two strings.
- **Edges:** no common; equal strings.

## 2. Intuition
Two-string DP mirrors `maximum_length_of_repeated_subarray`. Multi-string needs SA color windows.

## 3. Brute Force → Optimal
- **Brute:** all substrings of shortest.
- **2-string DP:** O(nm).
- **k-string SA:** O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** DP for 2 strings; document SA window for k.

| Alternative | Note |
|-------------|------|
| Pairwise min of LCS | **Incorrect** in general for k>2 |
| Binary search + hash | Works for k |

**Pedagogy:** multi-string LCS via generalized SA+LCP; teaches height-array windows.

## 5. Logic Walkthrough
2-string: DP. k-string: SA+LCP; two pointers maintaining set of string ids in window; track max LCP when all ids present.

## 6. Dry Run
`abcdef` vs `zbcdf` → `3` (`bcd`).

## 7. Time & Space Complexity
2-string **O(nm)**; k-string SA **O(N log N)**.

## 8. Trade-offs & Alternatives
See `sa_longest_common_substring` for the 2-string SA variant.

## 9. Common Mistakes / Edge Cases
Using pairwise minima for k>2; forgetting unique separators.

## 10. Interview Follow-ups / Variations
Return the substring itself; online.

## 11. Tags
`lcs`, `suffix-array`, `teaching`, `difficulty:hard`
