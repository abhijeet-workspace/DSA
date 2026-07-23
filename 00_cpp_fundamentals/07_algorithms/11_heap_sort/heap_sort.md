# Heap Sort

## Problem Statement

Sort an array using a binary max-heap: after heapify, swap max to the end and re-heapify the reduced prefix.

## Intuition

A max-heap always exposes the largest remaining element at index 0 in O(log N) after each extraction.

## Brute Force → Optimal

Selection sort finds max in O(N). Heap structure reduces extract-max to O(log N), total O(N log N).

## Data Structure / Approach Justification

**Chosen:** implicit binary heap inside the same `vector`.

- **vs merge:** in-place, unstable, usually worse constants.
- **vs quick:** guaranteed O(N log N) worst-case; often slower average.
- Foundation for priority queues.

## Logic Walkthrough

Build: `heapify` from last parent `n/2-1` down to 0. Extract: swap `arr[0]` with `arr[i]`, `heapify(arr, i, 0)`.

## Dry Run

`{12,11,13,5,6,7}` → max-heap → swap 13 to end → heapify → … → `{5,6,7,11,12,13}`.

## Time & Space Complexity

Build O(N); each of N extracts O(log N) → O(N log N). Space O(1) extra (+ recursion in `heapify`).

## Trade-offs & Alternatives

Predictable time, in-place, not stable, weaker cache behavior than quick/merge.

## Common Mistakes / Edge Cases

- Wrong child indices `2*i+1`.
- Heapifying with full `n` after extract (must use shrunk size).
- Bottom-up build starting from leaves instead of last parent.

## Interview Follow-ups / Variations

Iterative heapify; min-heap for descending; introsort fallback.

## Tags

`sorting`, `heap-sort`, `binary-heap`, `difficulty:medium`
