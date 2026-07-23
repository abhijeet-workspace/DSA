# Quick Sort

## Problem Statement
Classic algorithm — partition around a pivot, then recursively sort both sides (randomized pivot).

- **Inputs:** `vector<int> arr`, range `[lo, hi]`.
- **Output:** `arr[lo..hi]` sorted ascending.
- **Valid answer:** non-decreasing (not stable).
- **Edges:** empty; all equal; already sorted.

## Intuition
After partition, the pivot sits in its final index; left side ≤ pivot, right side > pivot. Recurse independently.

## Brute Force → Optimal
- **Fragile:** always last element as pivot → O(N²) on sorted input.
- **Better:** randomize pivot to avoid adversarial order with high probability → O(N log N) expected.

## Data Structure / Approach Justification
**Chosen:** Lomuto partition + random pivot swap to end.

- **vs Hoare:** fewer swaps typically; same asymptotic.
- **vs merge:** in-place avg, cache-friendly; not stable; worst O(N²).

## Logic Walkthrough
Pick random index, swap with `hi`. Scan `j=lo..hi-1`; grow `i` for elements ≤ pivot. Swap pivot to `i+1`; recurse on `[lo,pi-1]` and `[pi+1,hi]`.

## Dry Run
`[3,1,4,2]`, pivot `2` → `[1]|2|[3,4]` → recurse sides.

## Time & Space Complexity
Time **O(N log N)** avg, **O(N²)** worst. Space **O(log N)** recursion avg. Why: balanced partitions × O(N) partition work (section 4).

## Trade-offs & Alternatives
Fast in practice; not stable. Introsort / `std::sort` hybrid bounds worst case with heap fallback. 3-way partition helps many duplicates.

## Common Mistakes / Edge Cases
Off-by-one in partition indices; forgetting `srand` in demos; infinite recursion when pivot not excluded.

## Interview Follow-ups / Variations
How does introsort bound worst case? Dutch-flag 3-way quicksort. Iterative / dual-pivot variants.

## Tags
`sorting`, `quick-sort`, `partition`, `randomized`, `difficulty:medium`
