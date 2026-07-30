# Bit Flags (Get / Set / Clear / Toggle)

## 1. Problem Statement
Manipulate a single bit at position `k` (0-based from the LSB) using masks built with `1 << k`.

- **Input:** `n = 0b1010` (10), positions shown in `main`
- **Output:** results after get / set / clear / toggle
- **Valid answer:** only the targeted bit changes (or is read)
- **Edges:** `k` must be in range for the type; prefer unsigned masks

## 2. Intuition
A **mask** isolates one bit. With mask `1 << k`:
- **Get:** `(n & mask) != 0`
- **Set:** `n | mask`
- **Clear:** `n & ~mask`
- **Toggle:** `n ^ mask`

## 3. Brute Force → Optimal
- **Naive:** convert number ↔ binary string, edit char at index, convert back.
- **This approach:** one mask and one bitwise op — O(1).

## 4. Data Structure / Approach Justification
Integer + shift mask — the standard bit-flag pattern (permissions, feature flags).

| Alternative | Why it loses here |
|-------------|-------------------|
| `bool` array of 32 slots | Extra space; not how hardware flags work |
| `std::bitset` | Cleaner API; learn raw masks first |

## 5. Logic Walkthrough
1. Start with `n = 0b1010` each time (ops are independent demos).
2. Get bit 1 → `1`.
3. Set bit 0 → `0b1011` (11).
4. Clear bit 3 → `0b0010` (2).
5. Toggle bit 1 → `0b1000` (8).

## 6. Dry Run
Start `n = 0b1010` (bit3=1, bit2=0, bit1=1, bit0=0).

| Op | Mask | Result bits | Decimal |
|----|------|-------------|---------|
| get(1) | `0010` | true | — |
| set(0) | `0001` | `1011` | 11 |
| clear(3) | `~1000` | `0010` | 2 |
| toggle(1) | `0010` | `1000` | 8 |

## 7. Time & Space Complexity
- **Time:** O(1) per operation
- **Space:** O(1)
- Why: fixed-width integer ops

## 8. Trade-offs & Alternatives
- Pack many booleans into one `int`/`uint64_t` for compact state.
- Prefer `unsigned` / `1u << k` to avoid signed-shift issues.
- `enum` bitmasks (`FLAG_READ = 1 << 0`) for readable flag APIs.

## 9. Common Mistakes / Edge Cases
- Using `1 << 31` on signed `int` (UB / sign-bit problems)
- Off-by-one on bit index (LSB is index 0)
- Clearing with `n & mask` instead of `n & ~mask`

## 10. Interview Follow-ups / Variations
- Set the i-th bit of all elements in an array.
- Count how many numbers have bit `k` set.
- Implement a tiny permission system with OR-combined flags.

## 11. Tags
`cpp-fundamentals`, `bit-manipulation`, `bit-flags`, `masks`, `beginner`
