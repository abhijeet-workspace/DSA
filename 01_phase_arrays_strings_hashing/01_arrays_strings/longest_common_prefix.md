# Longest Common Prefix

## Problem Statement
[LeetCode 14](https://leetcode.com/problems/longest-common-prefix/) — find the longest prefix shared by every string in `strs`. If none, return `""`.

- **Inputs:** `vector<string> strs` (at least one string; each string length 0–200).
- **Output:** the common prefix string.
- **Valid answer:** characters that appear at the same index in **all** strings, from the start, until the first mismatch or end of a string.
- **Edges:** single string; empty string in the list; no shared first character; one string is a prefix of all others.

## Intuition
The answer cannot be longer than the shortest string. Compare column by column (same index across all strings) and stop at the first mismatch.

## Brute Force → Optimal
- **Brute:** for every possible prefix of `strs[0]`, check all strings — extra work on failed prefixes.
- **Optimal (vertical scan):** walk index `i` of the first string; if any string is shorter than `i` or differs at `i`, return prefix `[0, i)`. One pass over all characters that can still be in the answer.

## Data Structure / Approach Justification
**Chosen:** vertical scan using `strs[0]` as the candidate.

- **vs sort then LCP of first/last:** sorting is O(N log N · L); vertical scan is O(N · L) with no extra ordering.
- **vs trie:** overkill for one LCP query; useful if many prefix queries.

## Logic Walkthrough
1. If `strs` is empty, return `""` (LeetCode guarantees length ≥ 1).
2. For each index `i` in `strs[0]`:
   - For each other string `s`: if `i == s.size()` or `s[i] != strs[0][i]`, return `strs[0].substr(0, i)`.
3. If the loop finishes, `strs[0]` itself is a prefix of every string.

## Dry Run
`["flower","flow","flight"]` — index 0: `f` matches; 1: `l` matches; 2: `o` vs `i` → return `"fl"`.

`["dog","racecar","car"]` — index 0: `d` vs `r` → `""`.

## Time & Space Complexity
Time **O(S)** where S is the total number of characters compared (at most all characters). Space **O(1)** extra besides the output substring.

## Trade-offs & Alternatives
Horizontal scan: `prefix = LCP(prefix, strs[i])` in a loop; same complexity, can shrink early if an early string is very different.

## Common Mistakes / Edge Cases
Indexing past a short string; returning the first string when later strings diverge; treating empty `strs[i]` as a non-empty prefix.

## Interview Follow-ups / Variations
LCP of two strings; LCP after inserting into a trie; LCP array of a suffix array.

## Tags
`string`, `prefix`, `leetcode-14`, `difficulty:easy`
