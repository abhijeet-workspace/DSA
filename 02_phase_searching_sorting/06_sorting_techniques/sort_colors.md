# Sort Colors

## Problem Statement
[LeetCode 75](https://leetcode.com/problems/sort-colors/) — array of 0/1/2 only; sort in-place in one pass (Dutch National Flag).

- **Inputs:** `vector<int> nums` with values in `{0,1,2}`.
- **Output:** mutated `nums` sorted ascending.
- **Valid answer:** all 0s, then 1s, then 2s.
- **Edges:** all same; already sorted; single element.

## Intuition
Three pointers partition: `[0, low)` = 0s, `[low, mid)` = 1s, `(high, end]` = 2s; `mid` scans unknowns.

## Brute Force → Optimal
- **Brute:** count frequencies then rewrite — two passes.
- **Optimal:** one-pass three-way partition — O(N) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** `low`, `mid`, `high` with swaps on 0 and 2.

- **vs counting sort:** also O(N)/O(1) but two passes; DNF is the classic interview ask.
- **vs `std::sort`:** O(N log N); ignores ternary domain.

## Logic Walkthrough
`nums[mid]==0` → swap with `low++`, `mid++`. `==1` → `mid++`. `==2` → swap with `high--` (do not advance mid yet).

## Dry Run
`[2,0,2,1,1,0]` → ends `[0,0,1,1,2,2]`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: each index processed constantly (section 4).

## Trade-offs & Alternatives
Counting is simpler to code; DNF generalizes to 3-way QuickSort pivot step.

## Common Mistakes / Edge Cases
Incrementing `mid` after swapping a 2; `mid <= high` bound; assuming only two colors.

## Interview Follow-ups / Variations
k colors; partition around a pivot (QuickSort).

## Tags
`sorting`, `dutch-national-flag`, `two-pointers`, `difficulty:medium`
