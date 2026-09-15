# Word Break

## 1. Problem Statement
[LeetCode 139](https://leetcode.com/problems/word-break/) — return true if `s` can be segmented into dictionary words (reuse allowed).

- **Inputs:** `string s`, `vector<string> wordDict`.
- **Output:** `bool`.
- **Valid answer:** true iff some concatenation of dict words equals `s`.
- **Edges:** empty `s`; word longer than `s`; overlapping (`"aaaa"`).

## 2. Intuition
`dp[i]=true` if some `j < i` with `dp[j]` and `s[j..i)` in the dictionary — prefix reachability.

## 3. Brute Force → Optimal
- **Brute:** recurse all cuts — exponential without memo.
- **Optimal:** boolean DP + hash set — O(N² · L) with substring checks.

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_set` dict + `vector<bool> dp(n+1)`.

- **vs Trie + DP:** faster prefix checks for large dicts.
- **vs BFS on break positions:** equivalent reachability framing.

## 5. Logic Walkthrough
`dp[0]=true`. For each end `i`, try starts `j`; set `dp[i]` when a dict word matches a true prefix.

## 6. Dry Run
`s=leetcode`, dict=`{leet,code}`:
- `dp[4]` via `"leet"`; `dp[8]` via `"code"` → true

## 7. Time & Space Complexity
Time **O(N² · L)** worst (substring/hash). Space **O(N + dict)**. Why: all break pairs checked (section 4).

## 8. Trade-offs & Alternatives
Bound inner loop by max word length to speed up. Trie helps dense dictionaries.

## 9. Common Mistakes / Edge Cases
Forbidding word reuse (reuse is allowed); not marking `dp[0]`; substring off-by-one.

## 10. Interview Follow-ups / Variations
Return all segmentations (140); min breaks.

## 11. Tags
`1d-dp`, `string`, `hash-set`, `leetcode-139`, `difficulty:medium`
