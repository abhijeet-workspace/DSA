# Find the Duplicate Number

## Problem Statement
[LeetCode 287](https://leetcode.com/problems/find-the-duplicate-number/) — array of `n + 1` integers in `[1, n]` with exactly one duplicate; return that duplicate.

- **Inputs:** `vector<int> nums` length `n + 1`.
- **Output:** the duplicated value.
- **Valid answer:** the single duplicate (may appear ≥2 times).
- **Edges:** duplicate at ends; all others unique; `n = 1` → `[1,1]`.

## Intuition
Cyclic-sort places value `v` at index `v - 1`. When placement finishes on a near-permutation, the duplicate lands in the leftover slot (here: last).

## Brute Force → Optimal
- **Brute:** sort / hash set — O(N log N) or O(N) space.
- **Optimal (interview constraint):** Floyd cycle detection — O(N) time, O(1) space, no mutation.
- **This file:** cyclic placement — O(N) time, O(1) space, mutates array.

## Data Structure / Approach Justification
**Chosen:** cyclic swaps for teaching the pattern; note LC 287 often forbids modifying the array.

- **vs Floyd:** preferred when read-only input is required.
- **vs hash set:** simple but uses O(N) memory.

## Logic Walkthrough
While `nums[i] != nums[nums[i]-1]`, swap into home. Else advance. Return `nums.back()`.

## Dry Run
`nums = [1,3,4,2,2]`:
- place until homes filled → duplicate `2` remains at the end → return `2`

## Time & Space Complexity
Time **O(N)**. Space **O(1)** auxiliary (mutates). Why: each value moves to its home once (section 4).

## Trade-offs & Alternatives
Use Floyd if mutation / extra memory are disallowed. Counting sort needs O(N) space.

## Common Mistakes / Edge Cases
Assuming duplicate always at `back` for other encodings; infinite loop without equality check on home index.

## Interview Follow-ups / Variations
Read-only Floyd solution; find all duplicates (442); missing number (268).

## Tags
`cyclic-sort`, `array`, `duplicate`, `difficulty:medium`
