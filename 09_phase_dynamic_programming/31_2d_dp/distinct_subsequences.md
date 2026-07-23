# Distinct Subsequences

## Problem Statement
[LeetCode 115](https://leetcode.com/problems/distinct-subsequences/) — count how many distinct subsequences of `s` equal `t`.

- **Inputs:** strings `s`, `t`.
- **Output:** integer count of ways.
- **Valid answer:** different index sequences count as distinct.
- **Edges:** `t` empty → 1; `s` shorter than `t` → 0; many duplicate letters.

## Intuition
Process characters of `s`; for each char, extend prefixes of `t` already matched. Matching char `t[j-1]` adds ways from prefix `j-1`.

## Brute Force → Optimal
- **Brute:** recurse on every take/skip of `s[i]` — exponential.
- **Optimal:** 1D DP rolling over `s`, reverse scan on `t` — O(MN) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `dp[j]` = ways to form `t[0..j)` using characters seen from `s` so far; `unsigned long long` avoids overflow mid-sum.

- **vs full 2D `dp[i][j]`:** clearer but O(MN) space; 1D is enough.
- **vs recursion without memo:** TLE on long duplicate-heavy strings.

## Logic Walkthrough
`dp[0]=1`. For each `c` in `s`, scan `j` from `n` down to `1`: if `c==t[j-1]`, `dp[j]+=dp[j-1]`. Return `dp[n]`.

## Dry Run
`s=rabbbit`, `t=rabbit`: three ways to pick the three `b`s in `s` for the two `b`s in `t` → **3**.

## Time & Space Complexity
Time **O(MN)**. Space **O(N)** for `t`. Why: each `(s char, t index)` transition once (section 4).

## Trade-offs & Alternatives
Full 2D table easier to debug. Modulo arithmetic if problem requires it (this LC returns int without mod).

## Common Mistakes / Edge Cases
Forward inner loop reuses same `s` char; `int` overflow; forgetting empty-`t` base case.

## Interview Follow-ups / Variations
Print one subsequence; count with modulo; LCS length vs distinct count.

## Tags
`string-dp`, `2d-dp`, `subsequence`, `leetcode-115`, `difficulty:hard`
