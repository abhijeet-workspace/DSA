# Is Subsequence

## 1. Problem Statement
[LeetCode 392](https://leetcode.com/problems/is-subsequence/) — return whether `s` is a subsequence of `t` (characters of `s` appear in order in `t`, not necessarily contiguous).

- **Inputs:** strings `s`, `t`.
- **Output:** `true` / `false`.
- **Edges:** empty `s` (true); empty `t` with non-empty `s` (false); `s` longer than `t`; duplicates.

## 2. Intuition
Scan `t` left to right. Whenever the next needed char of `s` appears, take it. If every char of `s` is taken, `s` is a subsequence.

## 3. Brute Force → Optimal
- **Brute:** generate all subsequences of `t` — exponential.
- **Optimal:** one forward pass with two indices — O(|t|).

## 4. Data Structure / Approach Justification
**Chosen:** two pointers / greedy match (string analog of merge walk).

| Alternative | Why it loses here |
|-------------|-------------------|
| DP LCS length == \|s\| | Correct but O(\|s\|\|t\|) overkill |
| Binary search on positions per char | Useful for many queries on fixed `t` |

## 5. Logic Walkthrough
1. `i = 0` (index in `s`).
2. For each char in `t`: if it equals `s[i]`, `++i`.
3. Return `i == s.size()`.

## 6. Dry Run
`s=abc`, `t=ahbgdc` → match a,b,c → true.  
`s=axc`, `t=ahbgdc` → match a, then never x → false.

## 7. Time & Space Complexity
Time **O(|t|)**. Space **O(1)** auxiliary.

## 8. Trade-offs & Alternatives
Follow-up (many `s`, one `t`): preprocess `t` into char → sorted indices, binary-search next position.

## 9. Common Mistakes / Edge Cases
Requiring contiguous match (substring ≠ subsequence); forgetting empty `s` is always true.

## 10. Interview Follow-ups / Variations
Number of times `s` appears as subsequence; longest common subsequence; multi-query on fixed `t`.

## 11. Tags
`two-pointers`, `string`, `greedy`, `leetcode-392`, `difficulty:easy`, `leetcode-75`
