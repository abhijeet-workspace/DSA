# Selection Sort

## Problem Statement

Sort `arr` ascending by placing the next minimum into index `i` for each prefix position.

## Intuition

Grow a sorted prefix: scan the unsorted suffix for its min, swap into `arr[i]`.

## Brute Force → Optimal

Same O(N²) family as bubble. Selection does ≤ N swaps (good when writes are expensive) but always Θ(N²) comparisons.

## Data Structure / Approach Justification

**Chosen:** in-place min-selection on `vector`.

- **vs bubble:** fewer swaps, not adaptive.
- **vs heap sort:** heap also repeatedly extracts max/min but in O(N log N).
- Selection is unstable with naive swaps.

## Logic Walkthrough

For `i` in `0..n-2`, track `smallIndex` in `i..n-1`, then `swap(arr[i], arr[smallIndex])`.

## Dry Run

`{5,4,2,3,1}` → i=0 min=1 swap → `{1,4,2,3,5}` → i=1 min=2 → `{1,2,4,3,5}` → … → `{1,2,3,4,5}`.

## Time & Space Complexity

Time Θ(N²). Space O(1). Swaps O(N).

## Trade-offs & Alternatives

Useful when writes cost more than reads. Prefer `std::sort` / merge / heap for large N.

## Common Mistakes / Edge Cases

- Starting inner loop at `i` instead of `i+1` (wastes work, still correct).
- Swapping even when `smallIndex==i` (harmless).
- Assuming stability.

## Interview Follow-ups / Variations

Stable selection via rotations; partial selection for top-k (leads to quickselect/heap).

## Tags

`sorting`, `selection-sort`, `in-place`, `difficulty:easy`
