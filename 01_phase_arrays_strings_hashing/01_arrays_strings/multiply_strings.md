# Multiply Strings

## Problem Statement
[LeetCode 43](https://leetcode.com/problems/multiply-strings/) — multiply two non-negative integers given as strings; return the product as a string (no big-integer library / direct convert-to-int).

- **Inputs:** `num1`, `num2` digit strings.
- **Output:** product string without leading zeros (except `"0"`).
- **Valid answer:** exact decimal product.
- **Edges:** either operand `"0"`; single-digit; long carries.

## Intuition
Grade-school multiplication: digit `i` × digit `j` contributes to positions `i+j` (carry) and `i+j+1` (ones) in a length `m+n` buffer.

## Brute Force → Optimal
- **Brute:** convert to big int naively via repeated add — slow and messy.
- **Optimal:** digit DP into `m+n` array — O(MN) time.

## Data Structure / Approach Justification
**Chosen:** `vector<int>` of size `m+n` for place values.

- **vs string accumulation only:** harder carry management.
- **vs built-in 64-bit int:** overflows / forbidden for arbitrary length.

## Logic Walkthrough
From LSDs: `mul = d1*d2 + a[i+j+1]`; write `%10` to `a[i+j+1]`, add `/10` to `a[i+j]`. Strip leading zeros into result string.

## Dry Run
`"123" × "456"` → buffer builds to digits of **56088**.

## Time & Space Complexity
Time **O(MN)**. Space **O(M+N)**. Why: every digit pair contributes once to a fixed buffer (section 4).

## Trade-offs & Alternatives
Karatsuba/FFT for huge inputs — overkill for interview constraints.

## Common Mistakes / Edge Cases
Wrong index for carry (`i+j` vs `i+j+1`); returning empty instead of `"0"`; not stripping leading zeros.

## Interview Follow-ups / Variations
Add strings (415); divide strings; handle negatives/signs.

## Tags
`string`, `math`, `simulation`, `difficulty:medium`
