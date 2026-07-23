# Number of 1 Bits

## Problem Statement
[LeetCode 191](https://leetcode.com/problems/number-of-1-bits/) — return the Hamming weight (set-bit count) of a 32-bit unsigned int.

- **Inputs:** `uint32_t n`.
- **Output:** count of `1` bits.
- **Valid answer:** exact popcount.
- **Edges:** `0`; all bits set.

## Intuition
`n &= (n-1)` clears the lowest set bit. Count iterations until `n==0` — O(#set bits).

## Brute Force → Optimal
- **Brute:** check each of 32 bits.
- **Optimal:** Brian Kernighan — fewer steps when sparse.

## Data Structure / Approach Justification
**Chosen:** Kernighan loop on `uint32_t`.

- **vs `__builtin_popcount`:** production shortcut.
- **vs SWAR parallel count:** faster constant, harder to explain.

## Logic Walkthrough
While `n`: clear lowest 1, `++c`. Return `c`.

## Dry Run
`11 = 1011b` → three clears → **3**. `128` → **1**.

## Time & Space Complexity
Time **O(k)** for k set bits (≤32). Space **O(1)**. Why: each step removes one 1 (section 4).

## Trade-offs & Alternatives
Fixed 32-iter bit test is simpler and branch-predictable for dense bits.

## Common Mistakes / Edge Cases
Arithmetic right shift on signed types — use unsigned; infinite loop if using wrong clear idiom.

## Interview Follow-ups / Variations
Counting Bits (338); parity; next number with same popcount.

## Tags
`bit-manipulation`, `hamming-weight`, `difficulty:easy`
