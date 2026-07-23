# Missing Number

## Problem Statement
[LeetCode 268](https://leetcode.com/problems/missing-number/) — `nums` holds `n` distinct numbers from `[0, n]`; return the missing one.

- **Inputs:** `vector<int> nums` length `n`.
- **Output:** the missing integer in `[0, n]`.
- **Valid answer:** unique missing value.
- **Edges:** missing `0`; missing `n`; `n = 1`.

## Intuition
Place each `v < n` at index `v`. After placement, first index with `nums[i] != i` is the hole (or `n` if all match).

## Brute Force → Optimal
- **Brute:** sort then scan — O(N log N); hash set — O(N) space.
- **Optimal:** cyclic sort / XOR / Gauss sum — O(N) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** cyclic placement with guard `v < n` so `n` never indexes out of range.

- **vs XOR:** shorter code; cyclic sort teaches the family pattern.
- **vs sum formula:** overflow risk on large `n` without wide types.

## Logic Walkthrough
Swap until each `v < n` sits at `nums[v]`. Scan for first mismatch; else return `n`.

## Dry Run
`nums = [3,0,1]`:
- place → `[0,1,3]`; index `2` holds `3` ≠ `2` → return `2`

## Time & Space Complexity
Time **O(N)**. Space **O(1)** auxiliary (mutates input). Why: bounded swaps + one scan (section 4).

## Trade-offs & Alternatives
XOR/sum leave the array untouched. Prefer those if mutation is forbidden.

## Common Mistakes / Edge Cases
Swapping when `nums[i] == n` without a guard; assuming missing is always inside `[0, n-1]`.

## Interview Follow-ups / Variations
Find the Duplicate Number (287); First Missing Positive (41).

## Tags
`cyclic-sort`, `array`, `math`, `difficulty:easy`
