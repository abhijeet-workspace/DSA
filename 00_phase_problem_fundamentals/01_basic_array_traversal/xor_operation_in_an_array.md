# XOR Operation in an Array

## 1. Problem Statement
[LeetCode 1486](https://leetcode.com/problems/xor-operation-in-an-array/) — Build `nums` where `nums[i] = start + 2 * i` for `0 <= i < n`. Return the bitwise XOR of all elements.

- **Inputs:** `int n`, `int start`.
- **Output:** XOR of the generated sequence.
- **Edges:** `n = 1`; `start = 0`.

## 2. Intuition
You do not need to store the array — generate each term and fold with `^=` in one pass.

## 3. Brute Force → Optimal
Allocate `nums`, fill, then XOR — correct but wastes O(N) memory. Streaming XOR is optimal for this statement.

## 4. Data Structure / Approach Justification
**Chosen:** running XOR scalar; index `i` only to generate values.

| Alternative | Why it loses here |
|-------------|-------------------|
| Materialize full `vector` then reduce | Extra O(N) space with no benefit |
| Closed-form XOR of arithmetic progressions | Faster constants; opaque for this topic |

We deliberately generate-by-index so the learner practices “index → value → fold.”

## 5. Logic Walkthrough
1. `ans = 0`.
2. For `i = 0..n-1`: `ans ^= (start + 2 * i)`.
3. Return `ans`.

## 6. Dry Run
`n=5`, `start=0` → `0^2^4^6^8 = 8`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Bit-level formulas exist for XOR of ranges; keep the loop until number-theory comfort is higher.

## 9. Common Mistakes / Edge Cases
Using `start + i` instead of `start + 2*i`; XORing indices instead of values.

## 10. Interview Follow-ups / Variations
AND/OR reductions; generate then query range XORs (later: prefix XOR).

## 11. Tags
`array`, `bit-manipulation`, `simulation`, `leetcode-1486`, `difficulty:easy`
