# Common Bit Tricks

## 1. Problem Statement
Show four interview-frequent bit tricks on integers:

1. Even / odd check with `& 1`
2. Power-of-two test with `n & (n - 1)`
3. XOR swap of two values
4. Count set bits (Brian Kernighan’s algorithm)

- **Input:** demo values in `main`
- **Output:** parity, power-of-two bools, swapped pair, popcount
- **Edges:** `n <= 0` is not a power of two; XOR swap fails if both refs alias the same object

## 2. Intuition
- Odd numbers have LSB = 1 → `n & 1`.
- Powers of two have exactly one set bit → `n & (n - 1) == 0` (and `n > 0`).
- XOR is its own inverse → three XORs swap without a temp.
- `n &= (n - 1)` clears the lowest set bit → loop until zero.

## 3. Brute Force → Optimal
- **Parity:** `% 2` works; `& 1` is the bit form.
- **Power of two:** loop divide by 2; bit test is O(1).
- **Swap:** temp variable; XOR is a classic trick (temp is clearer in real code).
- **Popcount:** check all 32 bits; Kernighan is O(set bits). Builtins (`__builtin_popcount` / `std::popcount`) are production-optimal.

## 4. Data Structure / Approach Justification
Pure integer arithmetic — no aux storage beyond a few scalars.

| Alternative | Why it loses here |
|-------------|-------------------|
| `%` / loops for parity & powers | Correct but hides bit identity |
| Hash / sort for uniqueness | Different problem; see advanced phase |

## 5. Logic Walkthrough
1. `isOdd(5)` → true; `isOdd(4)` → false.
2. `isPowerOfTwo(16)` → true; `isPowerOfTwo(18)` → false.
3. XOR-swap `a=3`, `b=7` → `a=7`, `b=3`.
4. Kernighan on `15` (`1111`) → 4 set bits.

## 6. Dry Run
| Trick | Input | Steps | Result |
|-------|-------|-------|--------|
| odd | 5 (`101`) | `101 & 001` | true |
| power2 | 16 (`10000`) | `10000 & 01111 = 0` | true |
| xor swap | 3, 7 | a^=b; b^=a; a^=b | 7, 3 |
| popcount | 15 | clear lowbit 4 times | 4 |

## 7. Time & Space Complexity
- Even/odd, power-of-two, XOR swap: **O(1)** time/space
- Kernighan popcount: **O(k)** time where k = number of set bits, **O(1)** space

## 8. Trade-offs & Alternatives
- Prefer a temp for swap in production (clearer, alias-safe).
- Prefer `std::popcount` (C++20) or compiler builtins for speed.
- Advanced XOR problems (Single Number, etc.) live in `10_phase_advanced_topics/40_bit_manipulation`.

## 9. Common Mistakes / Edge Cases
- `isPowerOfTwo(0)` must be false
- XOR swap when `a` and `b` refer to the same variable → zeros the value
- Right-shifting negatives without understanding arithmetic shift

## 10. Interview Follow-ups / Variations
- Find the only non-duplicate with XOR (Single Number).
- Add two numbers without `+` using XOR and carry.
- Isolate lowest set bit: `n & -n` (unsigned-safe form preferred).

## 11. Tags
`cpp-fundamentals`, `bit-manipulation`, `bit-tricks`, `kernighan`, `beginner`
