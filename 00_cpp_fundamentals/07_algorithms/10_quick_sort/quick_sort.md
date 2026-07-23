# Quick Sort

## Problem Statement

Sort an array in place by partitioning around a pivot so left side < pivot ≤ right side, then recurse.

## Intuition

Once the pivot sits in its final index, the two sides are independent subproblems.

## Brute Force → Optimal

Quadratic sorts always O(N²). Quicksort averages O(N log N) with good constants; worst O(N²) on already-sorted data with fixed last-element pivot.

## Data Structure / Approach Justification

**Chosen:** Lomuto partition (pivot = `arr[high]`) inside a small class.

- **vs Hoare partition:** fewer swaps typically.
- **vs merge sort:** better cache locality / in-place, but unstable and worse worst-case without safeguards.
- Random pivot / median-of-three mitigates adversarial inputs.

## Logic Walkthrough

`partition`: scan `j`, grow `< pivot` region with `i`, place pivot at `i+1`. `sort`: recurse on `[low,pi-1]` and `[pi+1,high]`.

## Dry Run

`{10,7,8,9,1,5}`, pivot 5 → after partition `{1,5,8,9,10,7}`-style layout with 5 fixed; recurse left/right until sorted `{1,5,7,8,9,10}`.

## Time & Space Complexity

Average O(N log N); worst O(N²). Space O(log N) average stack (O(N) worst).

## Trade-offs & Alternatives

Fast in practice; not stable. Prefer introsort (`std::sort`) which falls back to heap sort.

## Common Mistakes / Edge Cases

- Off-by-one around `pi`.
- Infinite recursion if pivot not excluded.
- Assuming stability.

## Interview Follow-ups / Variations

3-way partition for duplicates; quickselect; randomized pivot.

## Tags

`sorting`, `quick-sort`, `partition`, `difficulty:medium`
