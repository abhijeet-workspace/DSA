# Dutch National Flag (Sort Colors)

## Problem Statement
[LeetCode 75](https://leetcode.com/problems/sort-colors/) — sort an array of 0s, 1s, and 2s in-place so equal colors are adjacent in order 0, then 1, then 2.

- **Inputs:** `vector<int> nums` with values in `{0,1,2}`.
- **Output:** `nums` sorted in-place.
- **Valid answer:** nondecreasing order of colors.
- **Edges:** all same color; already sorted; length 1.

## Intuition
Three pointers partition into `[0..low)`, `[low..mid)`, unknown `[mid..high]`, `[high+1..] = 2s`.

## Brute Force → Optimal
- **Brute:** counting sort (two passes) or general sort O(N log N).
- **Optimal:** Dutch National Flag one-pass three-way partition — O(N)/O(1).

## Data Structure / Approach Justification
**Chosen:** three indices `low`, `mid`, `high` — classic 3-way partition.

- **vs counting + rewrite:** simpler, two passes, also O(N)/O(1).
- **vs `std::sort`:** correct but O(N log N) and ignores ternary domain.

## Logic Walkthrough
`mid==0`: swap with `low`, advance both. `mid==1`: advance `mid`. `mid==2`: swap with `high`, decrement `high` only (recheck swapped-in value).

## Dry Run
`[2,0,2,1,1,0]` → after partition `[0,0,1,1,2,2]`.

## Time & Space Complexity
Time **O(N)** single pass. Space **O(1)**. Why: constant pointers only (section 4).

## Trade-offs & Alternatives
Counting sort is clearer for interviews if one-pass not required. DNF shines when follow-up demands one pass.

## Common Mistakes / Edge Cases
Advancing `mid` after swapping a 2 (misses checking new value); `mid > high` loop condition off-by-one.

## Interview Follow-ups / Variations
k-way partition; sort only two colors; pivot partition (quicksort step).

## Tags
`array`, `two-pointers`, `dutch-national-flag`, `difficulty:medium`
