# Balanced Parentheses

## Problem Statement
Check whether an expression’s `()`, `[]`, and `{}` are correctly nested and matched.

- **Inputs:** string `expr` (other chars ignored if present).
- **Output:** true iff every close matches the most recent unmatched open and none remain.
- **Valid answer:** boolean balance result.
- **Edges:** empty; only opens; only closes; crossing types like `([)]`.

## Intuition
Valid nesting is LIFO: the next close must match the latest unmatched open — exactly a stack.

## Brute Force → Optimal
- **Brute:** repeatedly erase adjacent pairs — O(N²).
- **Optimal:** one pass with a stack — O(N) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `stack<char>` of opening brackets.

- **vs counters only:** fails for multiple types / nesting order.
- **vs recursion/parse tree:** correct but heavier for this check.

## Logic Walkthrough
Push opens. On close: if empty or top mismatches → false; else pop. End with empty stack.

## Dry Run
`({[]})`: push `( { [` → pop `] } )` → empty → true. `([)]`: push `( [` → `)` mismatches `[` → false.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** worst case (all opens). Why: one pass + stack of opens (section 4).

## Trade-offs & Alternatives
Same idea as LeetCode 20. Counter works only for a single bracket type.

## Common Mistakes / Edge Cases
Popping empty stack; forgetting final `empty()` check; treating `([)]` as valid.

## Interview Follow-ups / Variations
Longest valid parentheses; score of parentheses; only one type with a counter.

## Tags
`stack`, `parentheses`, `string`, `difficulty:easy`
