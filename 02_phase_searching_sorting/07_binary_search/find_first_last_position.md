# Find First and Last Position

## Problem Statement
[LeetCode 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) — sorted `nums`; return `[first, last]` indices of `target`, or `[-1, -1]`.

- **Inputs:** non-decreasing `vector<int> nums`, `int target`.
- **Output:** length-2 vector of bounds.
- **Valid answer:** leftmost and rightmost equal indices.
- **Edges:** absent; single occurrence; all equal; empty.

## Intuition
Two binary searches: when mid equals target, keep searching left (`isFirst`) or right to pin the extreme index.

## Brute Force → Optimal
- **Brute:** linear scan — O(N).
- **Optimal:** two bound searches — O(log N).

## Data Structure / Approach Justification
**Chosen:** shared `findBound(nums, target, isFirst)` then assemble `{first, last}`.

- **vs lower/upper bound:** equivalent (`[lb, ub-1]`); this form stays explicit.
- **vs one pass expand:** needs a hit then walks out — O(N) on all-equal arrays.

## Logic Walkthrough
On match, store `bound = mid` and continue left (`right = mid - 1`) or right (`left = mid + 1`). If first is `-1`, return `[-1, -1]`.

## Dry Run
`nums = [5,7,7,8,8,10]`, `target = 8`:
- first bound → 3; last bound → 4 → `[3, 4]`

## Time & Space Complexity
Time **O(log N)**. Space **O(1)** (aside from return). Why: two log passes (section 4).

## Trade-offs & Alternatives
`lower_bound` + `upper_bound - 1` is shorter with STL.

## Common Mistakes / Edge Cases
Stopping at first hit without continuing; returning wrong pair when target missing.

## Interview Follow-ups / Variations
Count occurrences; first bad version style problems.

## Tags
`binary-search`, `bounds`, `duplicates`, `difficulty:medium`
