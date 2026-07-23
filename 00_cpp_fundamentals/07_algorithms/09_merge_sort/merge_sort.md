# Merge Sort

## Problem Statement

Sort an array using divide-and-conquer: recursively sort halves, then merge two sorted runs.

## Intuition

Sorting two sorted lists is linear; if both halves are sorted, one merge finishes the range.

## Brute Force → Optimal

Quadratic simple sorts. Merge sort guarantees O(N log N) comparisons with O(N) auxiliary buffers.

## Data Structure / Approach Justification

**Chosen:** recursive top-down merge on `vector` with temp `L`/`R`.

- **vs quick sort:** merge has predictable O(N log N) worst case and is stable; uses more memory.
- **vs heap sort:** heap is in-place O(N log N) but unstable and less cache-friendly for merges of runs.
- Bottom-up merge avoids recursion depth issues.

## Logic Walkthrough

`mergeSort(left,right)`: if size≤1 return; mid split; recurse; `merge` copies halves and writes back in order using `<=` for stability.

## Dry Run

`{12,11,13,5,6,7}` splits to singles, merges to `{11,12}`, `{5,13}`, … finally `{5,6,7,11,12,13}`.

## Time & Space Complexity

Time Θ(N log N). Space O(N) for temps + O(log N) recursion stack.

## Trade-offs & Alternatives

Stable + guaranteed time. Extra memory and copy overhead; hybrids switch to insertion on small runs.

## Common Mistakes / Edge Cases

- Using `<` instead of `<=` (unstable).
- Wrong mid / off-by-one when copying `R`.
- Calling merge when `left>=right`.

## Interview Follow-ups / Variations

In-place merge (hard); external sorting; counting inversions during merge.

## Tags

`sorting`, `merge-sort`, `divide-and-conquer`, `stable`, `difficulty:medium`
