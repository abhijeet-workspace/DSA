# DP on Strings

## Problem Statement
String DP demos: [Distinct Subsequences (115)](https://leetcode.com/problems/distinct-subsequences/), [Wildcard Matching (44)](https://leetcode.com/problems/wildcard-matching/).

- **Inputs:** source/pattern strings (`s`, `t` / `p`).
- **Output:** count of ways `t` appears as subsequence of `s`; or bool match with `?`/`*`.
- **Valid answer:** `*` matches any sequence (including empty); `?` one char.
- **Edges:** empty pattern/string; `m < n` for 115; leading `*`s.

## Intuition
Align prefixes: decide whether current chars pair. For counts, add ways when equal; for wildcard, `*` = match empty or consume one more of `s`.

## Brute Force → Optimal
- **Brute:** recurse alignments — exponential.
- **Optimal:** O(M·N) DP; 115 rolls to O(N) with descending `j`.

## Data Structure / Approach Justification
**Chosen:** 1D `unsigned long long` for 115; 2D `bool` for 44.

- **vs regex engine:** overkill; DP teaches transitions.
- **Ascending `j` for 115:** corrupts 1D reuse (same 0/1 discipline).

## Logic Walkthrough
**115:** `dp[0]=1`; on match `dp[j]+=dp[j-1]` descending. **44:** `dp[0][0]=true`; propagate leading `*`; `?`/equal ← diag; `*` ← left or up.

## Dry Run
`rabbbit` / `rabbit` → **3** ways. `adceb` / `*a*b` → **true**.

## Time & Space Complexity
Time **O(M·N)**. Space **O(N)** (115) / **O(M·N)** (44). Why: fill alignment table (section 4).

## Trade-offs & Alternatives
Wildcard can roll to 1D with care. Regex Matching (10) is a related but different `*` semantics.

## Common Mistakes / Edge Cases
Confusing LC 10 vs 44 `*` rules; int overflow on 115; forgetting empty-`*` init row.

## Interview Follow-ups / Variations
Edit Distance (72); Regex Matching (10); LCS / LPS.

## Tags
`string-dp`, `distinct-subsequences`, `wildcard`, `leetcode-115`, `leetcode-44`, `difficulty:hard`
