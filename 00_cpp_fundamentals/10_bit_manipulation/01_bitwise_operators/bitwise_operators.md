# Bitwise Operators

## 1. Problem Statement
Demonstrate the five bitwise operators on integers: `&`, `|`, `^`, `~`, `<<`, `>>`.

- **Input:** fixed demo values (`a = 5`, `b = 3`)
- **Output:** results of each operator printed in decimal
- **Valid answer:** matches binary truth tables / shift semantics
- **Edges:** `~` flips all bits (two’s complement); arithmetic vs logical right shift on signed types

## 2. Intuition
Bitwise ops work on each bit independently. Think in binary: `5` is `0101`, `3` is `0011`.

| Op | Name | Rule (per bit) |
|----|------|----------------|
| `&` | AND | 1 only if both 1 |
| `\|` | OR | 1 if either 1 |
| `^` | XOR | 1 if bits differ |
| `~` | NOT | flip every bit |
| `<<` / `>>` | shift | move bits left/right |

## 3. Brute Force → Optimal
- **Naive:** convert to strings of `'0'`/`'1'` and simulate with loops.
- **This approach:** use language operators — O(1) word ops on fixed-width integers.

## 4. Data Structure / Approach Justification
Plain `int` locals — no containers.

| Alternative | Why it loses here |
|-------------|-------------------|
| `std::bitset` | Useful later; hides raw operator syntax |
| Manual bit loops | Teaches less about the language operators |

## 5. Logic Walkthrough
1. Set `a = 5` (`0101`), `b = 3` (`0011`).
2. Print `a & b`, `a | b`, `a ^ b`, `~a`, `a << 1`, `a >> 1`.
3. Mentally verify against the binary forms.

## 6. Dry Run
| Expression | Binary view | Decimal |
|------------|-------------|---------|
| `5 & 3` | `0101 & 0011` → `0001` | 1 |
| `5 \| 3` | `0101 \| 0011` → `0111` | 7 |
| `5 ^ 3` | `0101 ^ 0011` → `0110` | 6 |
| `5 << 1` | `0101` → `1010` | 10 |
| `5 >> 1` | `0101` → `0010` | 2 |
| `~5` | flips all bits of `int` | platform two’s complement (e.g. `-6`) |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: fixed-width word operations

## 8. Trade-offs & Alternatives
- Prefer unsigned types when shifting to avoid signed-shift pitfalls.
- `std::bitset` / `<bit>` (C++20) for clearer named ops in larger codebases.

## 9. Common Mistakes / Edge Cases
- Confusing `&&` / `||` (logical) with `&` / `|` (bitwise)
- Left-shifting into the sign bit (undefined behavior for signed)
- Assuming `~0 == 0` (it is all ones, usually `-1`)

## 10. Interview Follow-ups / Variations
- Difference between logical and arithmetic right shift?
- How do you print an `int` in binary?
- When is `|` used for flag combination vs `||` for short-circuit logic?

## 11. Tags
`cpp-fundamentals`, `bit-manipulation`, `bitwise-operators`, `beginner`
