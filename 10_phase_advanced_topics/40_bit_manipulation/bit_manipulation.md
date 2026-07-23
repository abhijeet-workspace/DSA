# Bit Manipulation

## Problem Statement
Demo of core bit tricks: Single Number I/II/III (LC 136/137/260), power-of-two check, Hamming weight, and addition without `+`.

- **Inputs:** integer arrays / integers as shown in `main`.
- **Output:** unique values, bools, counts, sums.
- **Valid answer:** matches XOR / modular-bit / Kernighan identities.
- **Edges:** negatives for add; `n<=0` for power-of-two; INT_MIN lowbit via unsigned.

## Intuition
XOR cancels pairs. Bits modulo 3 recover a singleton among triples. Lowbit of `a^b` partitions two uniques. `n&(n-1)` clears or detects a single set bit. XOR + AND-shift simulate a full adder.

## Brute Force → Optimal
- **Brute:** hash maps / sort — extra space or time.
- **Optimal:** constant-space bit identities — O(N) or O(1) word ops.

## Data Structure / Approach Justification
**Chosen:** pure integers / XOR accumulators — no aux containers.

- **vs hash set:** O(N) space.
- **vs sorting:** O(N log N).

## Logic Walkthrough
I: fold XOR. II: per-bit count `%3`. III: XOR all → lowbit split → XOR each bucket. Power: `n>0 && !(n&(n-1))`. Popcount: Kernighan loop. Add: repeat `carry=(a&b)<<1`, `a^=b`.

## Dry Run
`{2,2,1}` → `1`. `{2,2,3,2}` → `3`. `{1,2,1,3,2,5}` → `{3,5}`. `15+27` → `42`.

## Time & Space Complexity
Single-number scans **O(N)** time, **O(1)** space. Bit loops **O(32)**. Why: algebraic cancellation (section 4).

## Trade-offs & Alternatives
II has a finite-state machine (ones/twos) that is faster in practice. Builtins (`__builtin_popcount`) for production.

## Common Mistakes / Edge Cases
Signed left-shift UB on carry — cast unsigned; `isPowerOfTwo(0)`; wrong modulo for II.

## Interview Follow-ups / Variations
Single Number II FSM; missing number via XOR; subset XOR DP.

## Tags
`bit-manipulation`, `xor`, `difficulty:medium`
