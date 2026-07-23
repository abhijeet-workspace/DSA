# Binary Search

## Problem Statement

In a **sorted** ascending array, return any index of `target`, or `-1` if absent.

## Intuition

Sorted order lets you discard half the range each step by comparing to the midpoint.

## Brute Force → Optimal

Linear scan O(N). Binary search O(log N) after the sorted precondition is met.

## Data Structure / Approach Justification

**Chosen:** iterative two-pointer range on `vector`.

- **vs recursive binary search:** same asymptotics; iterative uses O(1) stack.
- **vs hash map:** O(1) lookup but needs extra memory and loses order benefits for range queries.

## Logic Walkthrough

Maintain inclusive `[left,right]`. Compute `mid`. Equal → return. `arr[mid] < target` → raise `left`; else lower `right`.

## Dry Run

`{10,20,30,40,50,60}`, target `40`: mid=30 → go right; mid=50 → go left; mid=40 → return index `3`.

## Time & Space Complexity

Time O(log N). Space O(1).

## Trade-offs & Alternatives

Requires sorted input. Duplicate handling needs lower/upper bound variants.

## Common Mistakes / Edge Cases

- `mid = (left+right)/2` overflow on large indices.
- Loop condition `left < right` vs `<=` off-by-one.
- Searching unsorted data.

## Interview Follow-ups / Variations

Lower/upper bound; search in rotated sorted array; binary search on answer.

## Tags

`binary-search`, `sorted-array`, `difficulty:easy`
