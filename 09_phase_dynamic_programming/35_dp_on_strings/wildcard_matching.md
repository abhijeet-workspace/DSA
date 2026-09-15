# Wildcard Matching

## Problem Statement
[LeetCode 44](https://leetcode.com/problems/wildcard-matching/) — full match with `?` (exactly one) and `*` (any sequence including empty).

- **Inputs:** `s`, pattern `p`.
- **Output:** bool.
- **Valid answer:** must consume entire string.
- **Edges:** empty; only `*`; trailing `*`.

## Intuition
DP: `*` can match empty (take left) or one more char (take up); `?`/literal need diagonal.

## Brute Force → Optimal
- **Brute:** recursion — exponential.
- **Optimal:** DP O(mn); greedy two-pointer also O(mn) worst with better constants.

## Data Structure / Approach Justification
**Chosen:** 2D boolean DP.

- **vs regex `*` (LC10):** different semantics — here `*` is standalone wildcard.

## Logic Walkthrough
Init first row for leading `*`. Transition as above; answer `dp[m][n]`.

## Dry Run
`adceb` vs `*a*b`: stars absorb prefixes/suffixes around `a` and `b`.

## Time & Space Complexity
Time **O(mn)**. Space **O(mn)**.

## Trade-offs & Alternatives
Greedy with star-backtrack pointer for O(1)/O(n) space.

## Common Mistakes / Edge Cases
Confusing with regex star; not allowing `*` to match empty.

## Interview Follow-ups / Variations
Regular Expression Matching (10); glob matching.

## Tags
`dp`, `string`, `wildcard`, `leetcode-44`, `difficulty:hard`
