# Palindrome Partitioning

## Problem Statement
[LeetCode 131](https://leetcode.com/problems/palindrome-partitioning/) — partition string `s` so every piece is a palindrome; return all partitions.

- **Inputs:** `string s`.
- **Output:** `vector<vector<string>>` — each inner vector is one partition.
- **Valid answer:** all partitions; order may vary.
- **Edges:** empty / single char; all identical chars; no multi-char palindromes.

## Intuition
At each start index, try every end that makes `s[start..i]` a palindrome, append that piece, recurse from `i+1`, then pop.

## Brute Force → Optimal
- **Brute:** all 2^(N-1) cut sets, filter non-palindrome parts.
- **Optimal:** backtracking that only extends with palindromic prefixes; optional DP table for O(1) palindrome queries.

## Data Structure / Approach Justification
**Chosen:** recursion + `current` path + expand-check palindrome.

- **vs DP palindrome table:** same search; precompute cuts O(N²) checks to O(1).
- **vs generate all cuts then filter:** wastes work on invalid prefixes.

## Logic Walkthrough
`backtrack(start)`: if `start==n`, record `current`. Else for `i` in `[start,n)`, if `s[start..i]` palindrome → push, recurse `i+1`, pop.

## Dry Run
`s="aab"`:
- cut `"a"` → from `"ab"`: `"a"|"b"` → `["a","a","b"]`; `"ab"` not pal → done
- cut `"aa"` → from `"b"`: `"b"` → `["aa","b"]`

## Time & Space Complexity
Time **O(N · 2^N)** worst (partitions × check/copy). Space **O(N)** recursion + path (plus output). Why: each position can cut or not, pruned by palindrome (section 4).

## Trade-offs & Alternatives
Expand-check is clear for interviews. Precompute DP when N is larger / many queries. Palindrome Partitioning II asks min cuts, not all lists.

## Common Mistakes / Edge Cases
Off-by-one on substr length; forgetting `pop_back`; treating single chars as non-palindrome (they always are).

## Interview Follow-ups / Variations
Min cuts (132). Count partitions only. Return any one valid partition. Case-insensitive / ignore non-alnum.

## Tags
`backtracking`, `string`, `palindrome`, `leetcode-131`, `difficulty:medium`
