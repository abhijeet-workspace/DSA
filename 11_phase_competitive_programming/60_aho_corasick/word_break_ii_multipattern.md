# Word Break II — multi-pattern angle (LC 140)

## 1. Problem Statement
Return all ways to segment `s` into dictionary words.

- **Inputs:** string `s`, word dictionary.
- **Output:** all sentences (words joined by spaces).
- **Valid answer:** [LC 140](https://leetcode.com/problems/word-break-ii/).
- **Edges:** no break; overlapping choices; exponential output size.
- **Multi-pattern angle:** dictionary is a pattern set; memoized DFS / DP over prefixes uses a trie (AC optional for dense dicts).
- **Link:** [LC 140](https://leetcode.com/problems/word-break-ii/)

## 2. Intuition
At each index, try words that match a prefix; memoize remaining string's segmentations.

## 3. Brute Force → Optimal
- **Brute:** try all cuts — exponential.
- **Memo DFS + set/trie:** prune impossible prefixes.

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_set` dictionary + memoized DFS returning vector of suffixes.

| Alternative | Note |
|-------------|------|
| Trie of dict | Faster prefix checks |
| AC | Useful if streaming many queries on fixed dict |

## 5. Logic Walkthrough
1. If memo hit, return.
2. For each dict word matching prefix at `i`, recurse on rest and prepend.
3. Store results in memo.

## 6. Dry Run
`s=catsanddog`, dict `{cat,cats,and,sand,dog}` → `cats and dog`, `cat sand dog`.

## 7. Time & Space Complexity
Time dominated by output size; with memo **O(#answers · |s|)** roughly. Space similar.

## 8. Trade-offs & Alternatives
Output-sensitive. Cap recursion / use DP when only counting (LC 139).

## 9. Common Mistakes / Edge Cases
Not memoizing; mutating shared buffers without backtrack; missing empty rest case.

## 10. Interview Follow-ups / Variations
Count ways only; longest break; AC-assisted matching.

## 11. Tags
`dp`, `backtracking`, `trie-adjacent`, `lc-140`, `difficulty:hard`
