# Corporate Flight Bookings

## Problem Statement
[LeetCode 1109](https://leetcode.com/problems/corporate-flight-bookings/) — `n` flights labeled `1..n`. Each booking `[first, last, seats]` reserves `seats` on every flight in `[first, last]`. Return seats reserved per flight.

- **Inputs:** `bookings`, `n`.
- **Output:** `vector<int>` length `n` (0-based answer for flights 1..n).
- **Valid answer:** sum of all bookings covering each flight.
- **Edges:** single flight; booking covering all; overlapping ranges; `n=1`.

## Intuition
Range updates → difference array: `+seats` at `first`, `-seats` just after `last`. Prefix sum yields final occupancy (same pattern as car pooling).

## Brute Force → Optimal
- **Brute:** for each booking loop flights `first..last` — O(N · bookings).
- **Optimal:** difference array + prefix — O(bookings + N).

## Data Structure / Approach Justification
**Chosen:** difference array of size `n` (with sentinel for end).

- **vs nested loops:** too slow when ranges are long.
- **vs segment tree / fenwick:** overkill for offline full-array answer.

## Logic Walkthrough
For booking `[f,l,s]`: `diff[f-1] += s`, `diff[l] -= s` if `l < n`. Then prefix into `answer`.

## Dry Run
`n=5`, bookings `[1,2,10],[2,3,20],[2,5,25]`:
- diff after updates: `[10, 45, -10, -20, 0]` (conceptually)
- prefix → `[10, 55, 45, 25, 25]`

## Time & Space Complexity
Time **O(B + N)**. Space **O(N)**. Why: B range updates, one prefix pass (section 4).

## Trade-offs & Alternatives
Diff array needs dense flight ids `1..n`. Sparse / huge ids → event sort or fenwick.

## Common Mistakes / Edge Cases
1-index vs 0-index; subtracting at `last` instead of `last+1` position; forgetting last flight has no `-` when `last == n`.

## Interview Follow-ups / Variations
Car Pooling (1094); range add queries; online updates with fenwick.

## Tags
`difference-array`, `prefix-sum`, `range-update`, `leetcode-1109`, `difficulty:medium`
