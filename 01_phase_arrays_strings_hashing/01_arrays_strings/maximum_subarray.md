# Maximum Subarray

## Problem Statement
[LeetCode 53](https://leetcode.com/problems/maximum-subarray/) — contiguous subarray with the largest sum; return that sum.

- **Inputs:** non-empty `vector<int> nums`.
- **Output:** maximum subarray sum (integer).
- **Valid answer:** at least one element (empty subarray not allowed).
- **Edges:** all negative (pick largest element); single element.

## Intuition
Kadane — extend current sum or start fresh at `nums[i]`; track global max. Optimal ending at `i` is either `nums[i]` or `prev + nums[i]`.

## Brute Force → Optimal
- **Brute:** all subarrays — O(N²).
- **Optimal:** Kadane — O(N)/O(1).

## Data Structure / Approach Justification
**Chosen:** two running scalars (`cur`, `best`) — classic Kadane.

- **vs divide and conquer:** O(N log N), more code, same correctness.
- **vs prefix sums:** O(N) space; still O(N²) if naively scanning ranges.

## Logic Walkthrough
`cur = max(nums[i], cur + nums[i])`; then `best = max(best, cur)`.

## Dry Run
`[-2,1,-3,4,-1,2,1,-5,4]` → best becomes 6 from `[4,-1,2,1]`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: local optimal recurrence needs only previous `cur` (section 4).

## Trade-offs & Alternatives
Kadane is interview-classic and optimal. Divide-and-conquer is useful when teaching merge of mid-crossing sums.

## Common Mistakes / Edge Cases
Resetting `cur` to 0 (wrong when all-negative and empty forbidden); starting `best` at 0 instead of `nums[0]`.

## Interview Follow-ups / Variations
Return indices; circular max subarray (918); max product (152).

## Tags
`array`, `kadane`, `dp`, `difficulty:medium`
