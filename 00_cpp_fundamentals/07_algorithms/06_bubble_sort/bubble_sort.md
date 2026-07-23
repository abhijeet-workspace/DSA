# Bubble Sort

## Problem Statement

Sort an array of integers in non-decreasing order by repeatedly swapping adjacent elements that are out of order.

- **Input:** `vector<int>` (demo: `{5,4,6,8,2,1}`).
- **Output:** ascending permutation of the same multiset.
- **Edges:** already sorted; reverse sorted; duplicates; empty/single element.

## Intuition

Large values “bubble” rightward each pass; after pass `i`, the last `i` positions are final.

## Brute Force → Optimal

Any comparison sort can work. Bubble is the naive adjacent-swap approach — easy to see, rarely optimal. Better teaching upgrades: insertion (small/nearly sorted), then merge/quick/heap for O(N log N).

## Data Structure / Approach Justification

**Chosen:** in-place adjacent swaps on `vector`.

- **vs insertion sort:** insertion moves elements with fewer swaps on nearly sorted data.
- **vs merge sort:** merge is O(N log N) worst-case but needs O(N) extra memory.
- Bubble wins only for pedagogy / tiny N.

## Logic Walkthrough

Outer loop `i` = pass count. Inner loop compares `arr[j]` and `arr[j+1]` for `j` in `0..n-i-2`. Swap when left > right. Return sorted copy (demo takes vector by value).

## Dry Run

Start `{5,4,6,8,2,1}`.
Pass0 adjacent swaps → `{4,5,6,2,1,8}` (8 sunk to end).
Continue passes until `{1,2,4,5,6,8}`.

## Time & Space Complexity

Time O(N²) comparisons/swaps worst and average. Best O(N²) in this code (no early-exit flag). Space O(1) extra beyond the by-value copy in the demo signature.

## Trade-offs & Alternatives

Stable if `>` (not `>=`) is used. Add a `swapped` flag to get O(N) best case. Prefer library `std::sort` in production.

## Common Mistakes / Edge Cases

- Off-by-one in `n-i-1`.
- Using `>=` and breaking stability needlessly.
- Forgetting that by-value parameter copies O(N) memory.

## Interview Follow-ups / Variations

Cocktail shaker sort; early termination; compare with selection/insertion on nearly sorted arrays.

## Tags

`sorting`, `bubble-sort`, `in-place`, `difficulty:easy`
