# Set Mismatch

## 1. Problem Statement
[LeetCode 645](https://leetcode.com/problems/set-mismatch/) — set `{1..n}` was corrupted: one number duplicated and another missing. Return `[duplicate, missing]`.

- **Inputs:** `vector<int> nums` length `n`, values in `[1, n]`.
- **Output:** `{dup, missing}`.
- **Edges:** dup/missing at ends; `n = 2`.

## 2. Intuition
Classic cyclic-sort “corrupt pair”: place each `v` at `v - 1`. The index where `nums[i] != i + 1` holds the duplicate; `i + 1` is missing.

## 3. Brute Force → Optimal
- **Brute:** count array / hash — O(N) time, O(N) space.
- **Math:** sum + sum-of-squares — O(N)/O(1), overflow-sensitive.
- **Optimal pedagogical:** cyclic placement — O(N)/O(1).

## 4. Data Structure / Approach Justification
**Chosen:** swap-to-home then one scan for the mismatch slot.

- **vs XOR:** clever but harder to extend to “find all” variants.
- **vs hash:** simpler interview fallback when space is free.

## 5. Logic Walkthrough
1. Place: while `nums[i] != nums[nums[i]-1]`, swap.
2. Scan `i`: if `nums[i] != i + 1`, return `{nums[i], i + 1}`.

## 6. Dry Run
`[1,2,2,4]` → place → `[1,2,2,4]`; index `2` has `2` ≠ `3` → `[2, 3]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary (mutates)

## 8. Trade-offs & Alternatives
XOR of `nums[i] ^ (i+1)` isolates `dup ^ missing`; still need a second pass to separate. Cyclic sort is more readable for this family.

## 9. Common Mistakes / Edge Cases
Returning `{missing, dup}` order swapped; infinite swap without equality guard on home cell.

## 10. Interview Follow-ups / Variations
Find all duplicates (442); missing number (268); Educative “Find Corrupt Pair”.

## 11. Tags
`cyclic-sort`, `array`, `leetcode-645`, `difficulty:easy`
