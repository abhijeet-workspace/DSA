# Find All Numbers Disappeared in an Array

## Problem Statement
[LeetCode 448](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) — `nums` length `n` with values in `[1, n]`; return all missing numbers in `[1, n]`.

- **Inputs:** `vector<int> nums`.
- **Output:** vector of missing values (any order).
- **Edges:** none missing; many missing; duplicates present.

## Intuition
Cyclic-sort family: place each value `v` at index `v-1`. After placement, indices where `nums[i] != i+1` mark missing `i+1`.

## Brute Force → Optimal
- **Brute:** hash set of present values — O(N) space.
- **Optimal:** cyclic placement / negate-in-place — O(1) extra space.

## Data Structure / Approach Justification
**Chosen:** cyclic sort placement (matches Missing Number / Find Duplicate in this folder).

- **vs marking negatives:** also O(1) space; cyclic sort unifies the pattern.

## Logic Walkthrough
1. Swap until each `v` sits at `v-1` (skip when already correct or duplicate blocks).
2. Collect every `i+1` where `nums[i] != i+1`.

## Dry Run
`[4,3,2,7,8,2,3,1]` → after placement holes at indices for **5** and **6**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** auxiliary (output excluded). Why: bounded swaps + one scan.

## Trade-offs & Alternatives
Hash set is simpler if extra space is allowed.

## Common Mistakes / Edge Cases
Infinite swap on duplicates — only swap when `nums[i] != nums[correct]`.

## Interview Follow-ups / Variations
Missing Number (268); First Missing Positive (41); Find All Duplicates (442).

## Tags
`cyclic-sort`, `array`, `leetcode-448`, `difficulty:easy`
