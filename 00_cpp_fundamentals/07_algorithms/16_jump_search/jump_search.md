# Jump Search

## Problem Statement

Find `target` in a **sorted** ascending array by jumping fixed-size blocks of about √N, then scanning linearly inside the candidate block.

## Intuition

Binary search halves the range; jump search skips ahead in √N strides so you touch fewer elements than linear search without needing recursive midpoints.

## Brute Force → Optimal

Linear scan O(N). Jump search O(√N). Binary search O(log N) is usually better when random access and log factors are fine.

## Data Structure / Approach Justification

**Chosen:** block jump of size `√n` on `vector<int>`.

- **vs linear:** fewer comparisons on sorted data.
- **vs binary:** simpler locality (sequential jumps); worse asymptotics than binary.

## Logic Walkthrough

Set `step = √n`. Advance `prev`/`step` while the element at the end of the jump block is still `< target`. Linear scan `[prev, min(step,n))`.

## Dry Run

`{0,1,1,2,3,5,8,13,21,34,55,...}`, target `55`, `√n ≈ 4`: jump to indices 3,7,11 → block contains 55 → linear finds index of 55.

## Time & Space Complexity

Time O(√N). Space O(1).

## Trade-offs & Alternatives

Prefer binary search in interviews unless the problem emphasizes jump/block scanning or limited random access cost models.

## Common Mistakes / Edge Cases

- Using on unsorted arrays.
- Off-by-one when clamping `min(step, n)`.
- Empty array.

## Interview Follow-ups / Variations

Optimal jump size √N; exponential search when bound is unknown; Fibonacci search.

## Tags

`jump-search`, `sorted-array`, `difficulty:easy`
