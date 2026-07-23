# Interpolation Search

## Problem Statement

Search in a sorted array that is roughly uniformly distributed by probing a predicted index from key values.

## Intuition

Like opening a dictionary near the expected page instead of the middle.

## Brute Force → Optimal

Binary search always probes mid. Interpolation uses a linear estimate; average O(log log N) on uniform data, O(N) worst.

## Data Structure / Approach Justification

**Chosen:** interpolation probe on `vector<int>`.

- **vs binary:** better average on uniform numeric keys; worse on skewed data / duplicates extremes.
- Guard against divide-by-zero when `arr[high]==arr[low]`.

## Logic Walkthrough

While target is inside `[arr[low],arr[high]]`, compute `pos` via interpolation formula; narrow `low`/`high` like binary search.

## Dry Run

Array `{10..30}` uniform-ish, target `18` → probe lands near 18 quickly → return its index.

## Time & Space Complexity

Average O(log log N) uniform; worst O(N). Space O(1).

## Trade-offs & Alternatives

Fragile on non-uniform distributions. Prefer binary search as default.

## Common Mistakes / Edge Cases

- Division by zero when endpoints equal.
- Missing bounds checks → out-of-range `pos`.
- Using on unsorted arrays.

## Interview Follow-ups / Variations

Exponential search for unbounded arrays; interpolation for floating keys.

## Tags

`interpolation-search`, `sorted-array`, `difficulty:medium`
