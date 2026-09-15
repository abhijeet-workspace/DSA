# Buildings With an Ocean View

## Problem Statement
[LeetCode 1762](https://leetcode.com/problems/buildings-with-an-ocean-view/) — return indices of buildings with an ocean view to the right (strictly greater than every building to their right), left-to-right order.

- **Inputs:** `heights[i]` building height.
- **Output:** increasing indices with ocean view.
- **Valid answer:** rightmost always included.
- **Edges:** strictly decreasing; equal heights block view.

## Intuition
Scan right→left keeping max so far; a building sees ocean iff taller than max on its right.

## Brute Force → Optimal
- **Brute:** for each i scan right — O(N²).
- **Optimal:** right-to-left max — O(N). Monotonic stack also works.

## Data Structure / Approach Justification
**Chosen:** running max from the right (+ reverse answer).

- **vs decreasing stack left→right:** same complexity, more code.

## Logic Walkthrough
From right: if `h > maxRight`, record index and update max; reverse list.

## Dry Run
`[4,2,3,1]`: 1, then 3, then 4 → indices 3,2,0 → reverse `0 2 3`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** for output.

## Trade-offs & Alternatives
Stack variant if ocean is on the left.

## Common Mistakes / Edge Cases
Using `>=` instead of `>`; forgetting to reverse.

## Interview Follow-ups / Variations
Ocean on both sides; next greater element family.

## Tags
`array`, `stack`, `monotonic`, `leetcode-1762`, `difficulty:medium`
