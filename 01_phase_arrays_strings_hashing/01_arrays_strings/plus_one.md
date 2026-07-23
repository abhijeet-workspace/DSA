# Plus One

## Problem Statement
[LeetCode 66](https://leetcode.com/problems/plus-one/) — `digits` represents a non-negative integer (MSB at index 0). Add one; return the resulting digit array.

- **Inputs:** `vector<int> digits` each in `0..9`, no leading zero except `0` itself.
- **Output:** digit vector of `number + 1`.
- **Valid answer:** correct decimal increment with possible length +1.
- **Edges:** trailing 9s; all 9s (`[9,9]` → `[1,0,0]`); single `[0]`.

## Intuition
Add from the least significant digit; carry while digits are 9. If carry survives the MSB, prepend 1.

## Brute Force → Optimal
- **Brute:** convert to integer / big int, add, convert back — overflow risk / extra work.
- **Optimal:** in-place right-to-left carry — O(N).

## Data Structure / Approach Justification
**Chosen:** mutate the input vector from the right; `insert` only on all-9s.

- **vs new vector always:** more allocations when no length change.
- **vs string conversion:** unnecessary indirection for digit arrays.

## Logic Walkthrough
From right: if digit `<9`, increment and return. Else set 0 and continue. If loop ends, insert `1` at front.

## Dry Run
`[1,2,9]` → last becomes 0, middle `2→3` → `[1,3,0]`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** amortized extra (O(N) only when growing). Why: single reverse scan (section 4).

## Trade-offs & Alternatives
Preallocating `n+1` buffer avoids mid-vector `insert` cost on all-9s.

## Common Mistakes / Edge Cases
Forgetting length growth on all 9s; treating MSB as LSD; mutating after early return incorrectly.

## Interview Follow-ups / Variations
Plus `k`; arbitrary-precision add of two digit arrays.

## Tags
`array`, `math`, `carry`, `difficulty:easy`
