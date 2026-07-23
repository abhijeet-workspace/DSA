# Q5 — Even or Odd

## 1. Problem Statement
Read an integer and print whether it is even or odd.

- **Input:** `num`
- **Output:** `"<num> is even number"` or `"... odd number"`
- **Valid answer:** even iff `num % 2 == 0`
- **Edges:** negative odds/evens (`-3` is odd); `0` is even

## 2. Intuition
Parity is the remainder mod 2. Branch with `if/else`.

## 3. Brute Force → Optimal
- **Naive:** convert to string and check last character only for positives.
- **This approach:** `num % 2` works for negatives in C++ toward-zero division with care — still standard for this drill.

## 4. Data Structure / Approach Justification
Single `int` + conditional.

| Alternative | Why it loses here |
|-------------|-------------------|
| Bit test `(num & 1)` | Fast; less obvious for first modulo lesson |
| Ternary print | Fine compression; `if/else` is clearer here |

## 5. Logic Walkthrough
1. Read `num`.
2. If `num % 2 == 0` print even, else odd.

## 6. Dry Run
| `num` | `% 2` | Output |
|-------|-------|--------|
| 4 | 0 | even |
| 7 | 1 | odd |
| 0 | 0 | even |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Prefer `(n & 1) == 0` in bit-twiddling contexts; prefer `std::abs` discussions when defining parity for negatives in interviews.

## 9. Common Mistakes / Edge Cases
Using `/` instead of `%`; missing `else`; assuming negatives are undefined.

## 10. Interview Follow-ups / Variations
Check parity without `%` or `&`; classify many numbers in a stream.

## 11. Tags
`cpp-basics`, `conditionals`, `modulo`, `beginner`, `practice`
