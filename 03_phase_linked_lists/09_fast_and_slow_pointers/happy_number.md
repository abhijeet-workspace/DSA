# Happy Number

## Problem Statement
[LeetCode 202](https://leetcode.com/problems/happy-number/) — repeatedly replace `n` with the sum of squares of its digits; return whether you eventually reach `1`.

- **Inputs:** positive integer `n`.
- **Output:** `true` if happy, else `false`.
- **Valid answer:** reach `1` (not stuck in a non-1 cycle).
- **Edges:** `n = 1`; numbers that cycle (e.g. `2`); large `n` (digit process shrinks quickly).

## Intuition
Digit-square sequences either hit `1` or enter a cycle. Treat the sequence as an implicit linked list and use Floyd cycle detection.

## Brute Force → Optimal
- **Brute:** store seen values in a set until repeat or `1` — O(log n) space for the chain length.
- **Optimal:** slow/fast on `getNext` — O(1) extra space.

## Data Structure / Approach Justification
**Chosen:** Floyd tortoise/hare on the numeric sequence (no explicit list).

- **vs hash set:** same asymptotic time, uses memory proportional to cycle path.
- **vs math closed form:** less portable in interview; Floyd is the standard pattern transfer from lists.

## Logic Walkthrough
`getNext` sums squared digits. `slow` advances one `getNext`, `fast` two. Loop until `fast == 1` (happy) or `slow == fast` (cycle). Return `fast == 1`.

## Dry Run
`n = 19`:
- `getNext(19)=1²+9²=82`, `getNext(82)=68`, … eventually `1` → happy.
`n = 2`:
- sequence enters `4 → 16 → … → 4` cycle; slow meets fast → not happy.

## Time & Space Complexity
Time **O(log n)** per step and short chain before cycle/1. Space **O(1)**. Why: Floyd needs only two scalars (section 4).

## Trade-offs & Alternatives
Hash set is easier to explain; Floyd saves memory and mirrors list-cycle interviews.

## Common Mistakes / Edge Cases
Forgetting `fast` can reach `1` before a meet; overflow on huge intermediates (use 64-bit if needed); treating `0` incorrectly.

## Interview Follow-ups / Variations
Detect cycle entry value; sum of squares in other bases; Linked List Cycle II analogy.

## Tags
`math`, `fast-slow-pointers`, `cycle-detection`, `difficulty:easy`
