# First Bad Version

## Problem Statement
[LeetCode 278](https://leetcode.com/problems/first-bad-version/) — versions `1..n` become bad after a hidden first bad version; find it with `isBadVersion`.

- **Inputs:** `int n`; boolean API.
- **Output:** `int` first bad version.
- **Valid answer:** lower bound of the `true` suffix.
- **Edges:** first version is bad; last only; `n=1`.

## Intuition
Monotone: `false,false,...,true,true`. Binary search the first `true`.

## Brute Force → Optimal
- **Brute:** scan from 1 — O(N) API calls.
- **Optimal:** lower-bound binary search — O(log N) calls.

## Data Structure / Approach Justification
**Chosen:** `while (lo < hi)` keeping `hi = mid` on bad.

- **vs 704:** we search a boundary, not an exact value
- **vs scanning:** too many API calls

## Logic Walkthrough
If mid is bad, first bad is at mid or left; else strictly right.

## Dry Run
`n=5`, first bad=4 → `isBad(3)=false`, `isBad(4)=true` → 4.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: log API calls.

## Trade-offs & Alternatives
Canonical “first true” template used all over search-on-answer.

## Common Mistakes / Edge Cases
`lo <= hi` plus `hi = mid-1` skipping the first bad; overflow mid.

## Interview Follow-ups / Variations
Guess number (374); lower bound (34).

## Tags
`binary-search`, `lower-bound`, `leetcode-278`, `difficulty:easy`
