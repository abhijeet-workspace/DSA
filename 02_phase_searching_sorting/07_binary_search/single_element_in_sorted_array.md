# Single Element in a Sorted Array

## Problem Statement
[LeetCode 540](https://leetcode.com/problems/single-element-in-a-sorted-array/) — sorted array; every value appears twice except one; find that single in O(log N) time and O(1) space.

- **Inputs:** `vector<int> nums` odd length.
- **Output:** `int` the unique value.
- **Valid answer:** the unpaired element.
- **Edges:** single at start/end; single in the middle.

## Intuition
Before the single, pairs sit on (even,odd) indices. After it, pairing is shifted. Check the even-aligned mid.

## Brute Force → Optimal
- **Brute:** XOR all — O(N) time, O(1) space (violates log time).
- **Optimal:** index-parity binary search — O(log N).

## Data Structure / Approach Justification
**Chosen:** even-index pairing invariant.

- **vs XOR:** linear; misses the log requirement
- **vs hashmap:** extra space

## Logic Walkthrough
Force `mid` even. Equal to `mid+1` → single is right (`lo = mid+2`); else left including mid.

## Dry Run
`[1,1,2,3,3,...]` even mid 0 is a pair → go right; next even mid lands on 2.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: halving after a pair check.

## Trade-offs & Alternatives
XOR is a good follow-up if log time is dropped.

## Common Mistakes / Edge Cases
Forgetting to even-align mid; `lo = mid+1` splitting a pair.

## Interview Follow-ups / Variations
Find the large integer (1533); missing number.

## Tags
`binary-search`, `parity`, `leetcode-540`, `difficulty:medium`
