# Heap Sort

## Problem Statement
Classic algorithm — build a max-heap, then repeatedly extract the maximum into the sorted suffix.

- **Inputs:** `vector<int> arr` (mutated in place).
- **Output:** `arr` sorted ascending.
- **Valid answer:** non-decreasing (not stable).
- **Edges:** empty; one element; duplicates.

## Intuition
Heap root is the max. Swap it with the last unsorted index, shrink heap size, siftdown to restore heap property — sorted suffix grows.

## Brute Force → Optimal
- **Brute:** selection with linear min/max scan — O(N²).
- **Optimal:** build-heap O(N) + N × extract-max O(log N) → O(N log N) guaranteed.

## Data Structure / Approach Justification
**Chosen:** binary max-heap over the array itself (indices `2i+1`, `2i+2`).

- **vs quick:** worse constants, better worst-case bound, in-place.
- **vs priority_queue copy:** same idea with extra O(N) space.

## Logic Walkthrough
Heapify from last parent `n/2-1` down to 0. Then for `i=n-1..1`: swap `arr[0]` with `arr[i]`, heapify root in size `i`.

## Dry Run
`[3,1,4]` → heapify `[4,1,3]` → swap → `[3,1,4]` → heapify → `[3,1]|4` → … → `[1,3,4]`.

## Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra (recursion depth O(log N) if recursive siftdown). Why: N extracts × O(log N) (section 4).

## Trade-offs & Alternatives
Guaranteed bound and in-place; not stable; slower constants than quick. Introsort uses heap as worst-case fallback.

## Common Mistakes / Edge Cases
Wrong child indices; heapifying with wrong live size after extract; off-by-one on build loop start.

## Interview Follow-ups / Variations
Why prefer heap when worst-case bound matters? Soft heaps / smoothsort. Top-K with partial heapify.

## Tags
`sorting`, `heap-sort`, `binary-heap`, `in-place`, `difficulty:medium`
