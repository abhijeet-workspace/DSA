# Palindrome Number

## Problem Statement
[LeetCode 9](https://leetcode.com/problems/palindrome-number/) — return `true` if `x` reads the same forward and backward (base 10), else `false`.

- **Inputs:** `int x`.
- **Output:** bool.
- **Valid answer:** digit palindrome without converting to string (preferred).
- **Edges:** negatives; trailing zero (`10`); single digit; `INT_MIN`/`INT_MAX`.

## Intuition
Negatives are never palindromes. Reverse the second half of digits and compare to the first half.

## Brute Force → Optimal
- **Brute:** to-string and two-pointer check.
- **Optimal:** reverse half arithmetically — O(log |x|) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** half-reverse until `rev >= x`.

- **vs full reverse (LC 7):** avoids overflow for full-width ints; half is enough.
- **vs string:** clearer but uses extra memory.

## Logic Walkthrough
Reject `x < 0` or (`x % 10 == 0 && x != 0`). Build `rev` from trailing digits until `rev >= x`. Equal, or equal after `rev/10` (odd length).

## Dry Run
`121` → rev grows `1`, then `12`; `x` becomes `1`; `rev/10 == 1` → **true**. `10` → early reject → **false**.

## Time & Space Complexity
Time **O(log |x|)**. Space **O(1)**. Why: process half the digits.

## Trade-offs & Alternatives
Full reverse + compare works if you guard overflow like LC 7.

## Common Mistakes / Edge Cases
Accepting negatives; treating `10` as palindrome; comparing full reverse without odd-length `rev/10`.

## Interview Follow-ups / Variations
Palindrome string (125); reverse integer (7).

## Tags
`math`, `integer`, `palindrome`, `difficulty:easy`
