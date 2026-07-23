# Valid Parenthesis String

## Problem Statement
[LeetCode 678](https://leetcode.com/problems/valid-parenthesis-string/) — check if a string of `(`, `)`, and `*` can be valid parentheses (`*` = `(`, `)`, or empty).

- **Inputs:** string `s`.
- **Output:** bool validity.
- **Valid answer:** true if any assignment of `*` works.
- **Edges:** empty; all `*`; leading `)`; trailing `(`.

## Intuition
Track the range `[lo, hi]` of possible open-paren counts. `(` raises both; `)` lowers both (clamp `lo`); `*` can lower `lo` or raise `hi`. Fail if `hi < 0`; succeed if `lo == 0` at end.

## Brute Force → Optimal
- **Brute:** recurse on each `*` — exponential.
- **Optimal:** two counters / balance range — O(N).

## Data Structure / Approach Justification
**Chosen:** `lo`/`hi` balance range (greedy interval).

- **vs two stacks (indexes of `(` and `*`):** also O(N), more code.
- **vs DP:** O(N²) overkill.

## Logic Walkthrough
Scan left→right updating range; abort if `hi < 0`; require `lo == 0` after scan (all opens closable).

## Dry Run
`"(*))"`: `*` absorbs imbalance → ends with `lo=0` → true.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: possible balances form a contiguous range (section 4).

## Trade-offs & Alternatives
Stack method is more intuitive for some; range method is constant space and concise.

## Common Mistakes / Edge Cases
Not clamping `lo` at 0; requiring `hi==0` instead of `lo==0`; treating `*` only as one role.

## Interview Follow-ups / Variations
Count ways? Only `*` as empty or `(`? Longest valid substring with `*`.

## Tags
`greedy`, `string`, `parentheses`, `difficulty:medium`
