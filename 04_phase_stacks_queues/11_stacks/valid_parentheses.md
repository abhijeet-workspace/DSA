# Valid Parentheses

## Problem Statement
[LeetCode 20](https://leetcode.com/problems/valid-parentheses/) — return true if string `s` of `()`, `{}`, `[]` is valid (correct order and nesting).

- **Inputs:** `string s`.
- **Output:** boolean.
- **Valid answer:** true iff every close matches the latest unmatched open and stack ends empty.
- **Edges:** empty string; single char; only closes; interleaved wrong types.

## Intuition
Valid nesting is LIFO: a close must match the most recent unmatched open.

## Brute Force → Optimal
- **Brute:** repeatedly erase adjacent pairs — O(N²).
- **Optimal:** stack of opens — O(N) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `stack<char>` of opening brackets.

- **vs counter (one type):** insufficient for three types / nesting order.
- **vs recursion/parse trees:** correct but heavier.

## Logic Walkthrough
Push opens. On close: empty → false; pop and check match. Return `st.empty()`.

## Dry Run
`"({[]})"`: push `( { [` → pop `] } )` → empty → true. `"(]"`: push `(` → `]` mismatches → false.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** worst case. Why: one pass + unmatched opens (section 4).

## Trade-offs & Alternatives
Same core as teaching `02_balanced_parentheses`. Map open→close can shorten match logic.

## Common Mistakes / Edge Cases
Pop without empty check; forgetting final empty check; accepting `([)]`.

## Interview Follow-ups / Variations
Longest valid substring (32); score of parentheses (856); remove invalid parentheses.

## Tags
`stack`, `parentheses`, `string`, `leetcode-20`, `difficulty:easy`
