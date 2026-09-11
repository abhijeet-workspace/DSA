# Add Binary

## Problem Statement
[LeetCode 67](https://leetcode.com/problems/add-binary/) — add two binary strings `a` and `b`; return the sum as a binary string (no converting to int if length can exceed 64-bit).

- **Inputs:** binary digit strings `a`, `b` (no leading zeros except `"0"`).
- **Output:** binary sum string.
- **Edges:** unequal lengths; all carries (`"1"+"1"` → `"10"`); one operand `"0"`; long carry chain (`"111"+"1"` → `"1000"`).

## Intuition
Same as grade-school addition: walk both strings from the least significant bit, add bits plus carry, emit bit `% 2`, keep carry `/ 2`.

## Brute Force → Optimal
- **Brute:** convert to integers, add, convert back — fails for long strings / forbidden in spirit.
- **Optimal:** one right-to-left pass with carry — O(|a| + |b|).

## Data Structure / Approach Justification
**Chosen:** two indices from the ends + integer carry; build result then reverse (or prepend).

| Alternative | Why it loses here |
|-------------|-------------------|
| `stoll` / big-int library | Length / overflow / usually disallowed |
| Pad shorter string then zip | Extra allocation; same asymptotics |

## Logic Walkthrough
1. `i = |a|-1`, `j = |b|-1`, `carry = 0`.
2. While `i >= 0` or `j >= 0` or `carry`: sum bits (0 if exhausted) + carry; append `sum % 2`; `carry = sum / 2`.
3. Reverse the built string and return.

## Dry Run
`a=11`, `b=1`:  
`(1+1)=2` → bit `0`, carry `1`; `(1+0+1)=2` → bit `0`, carry `1`; leftover carry → `1` → reverse → **100**.

## Time & Space Complexity
Time **O(|a| + |b|)**. Space **O(|a| + |b|)** for the output (aux **O(1)** besides result).

## Trade-offs & Alternatives
Building with `push_back` + `reverse` is clearer than repeated `insert(0, …)` which is O(n²).

## Common Mistakes / Edge Cases
Forgetting final carry; treating missing digits as `'0'` incorrectly; returning with leading zeros when result should be `"0"` only for zero sum (not an issue if carry/bit logic is correct).

## Interview Follow-ups / Variations
Add Strings (415, base 10); Add to Array-Form of Integer (989); multiply binary strings.

## Tags
`string`, `math`, `simulation`, `two-pointers`, `leetcode-67`, `difficulty:easy`
