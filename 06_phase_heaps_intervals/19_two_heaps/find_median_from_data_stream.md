# Find Median from Data Stream

## Problem Statement
[LeetCode 295](https://leetcode.com/problems/find-median-from-data-stream/) — design a structure that supports adding integers from a stream and returning the median so far.

- **Inputs:** stream via `addNum(int)`; query via `findMedian()`.
- **Output:** median as `double` (average of two middles when even count).
- **Valid answer:** after every insert, median of all numbers seen.
- **Edges:** single element; all equal; negatives; even vs odd count.

## Intuition
Partition the stream into a lower half and an upper half. The median sits at the boundary: max of lower, or average of max(lower) and min(upper).

## Brute Force → Optimal
- **Brute:** keep a sorted vector; insert with binary search — O(N) per add, O(1) median.
- **Optimal:** max-heap (low) + min-heap (high), sizes balanced — O(log N) add, O(1) median.

## Data Structure / Approach Justification
**Chosen:** `priority_queue` max-heap for lower half, min-heap for upper half; invariant `low.size() == high.size()` or `low` one larger.

- **vs sorted multiset:** O(log N) insert but median needs iterator mid — heavier constants.
- **vs sorting on each query:** too slow for a stream.

## Logic Walkthrough
Push into `low`, then move `low.top()` into `high`. If `high` is larger, move its top back to `low`. Median: `low.top()` if odd, else average of both tops.

## Dry Run
`add(1)`, `add(2)` → low={1}, high={2} → median 1.5. `add(3)` → rebalance → low={2}, high={3} (after steps) → median 2.

## Time & Space Complexity
Time **O(log N)** per `addNum`, **O(1)** `findMedian`. Space **O(N)**. Why: heap ops on N elements (section 4).

## Trade-offs & Alternatives
Two heaps are the classic interview answer. Indexed/policy-based trees also work; periodic full sort is simpler but slower.

## Common Mistakes / Edge Cases
Forgetting to rebalance after every insert; putting larger values only in `low`; integer overflow when averaging two tops (use `double`).

## Interview Follow-ups / Variations
Sliding window median (480); running mode; online percentile with two heaps of unequal size.

## Tags
`heap`, `two-heaps`, `stream`, `median`, `leetcode-295`, `difficulty:hard`
