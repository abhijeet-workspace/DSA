# Insertion Sort

## Problem Statement

Sort an integer array by inserting each new element into its correct place inside the already-sorted left prefix.

## Intuition

Like sorting cards in hand: take next card, shift larger cards right, drop it into the gap.

## Brute Force → Optimal

Prior stub returned unsorted input. Correct insertion is still O(N²) worst-case but O(N) on nearly sorted data — better practical baseline than bubble/selection for small arrays.

## Data Structure / Approach Justification

**Chosen:** in-place shifting on `vector`.

- **vs bubble/selection:** adaptive + stable with `>`.
- **vs shell sort:** shell uses diminishing gaps to reduce shifts.
- Building block inside TimSort / hybrid sorts.

## Logic Walkthrough

For `i=1..n-1`, set `key=arr[i]`. While `j>=0` and `arr[j]>key`, shift `arr[j]` to `j+1`. Write `key` at `j+1`.

## Dry Run

`{5,4,6,8,2,1}`: insert 4 → `{4,5,6,8,2,1}`; … insert 2 → shifts 8,6,5,4; final `{1,2,4,5,6,8}`.

## Time & Space Complexity

Worst/average O(N²). Best O(N) when already sorted. Space O(1) extra (plus by-value copy in demo).

## Trade-offs & Alternatives

Great for tiny or nearly sorted inputs. Poor for large random arrays vs O(N log N) sorts.

## Common Mistakes / Edge Cases

- Using `>=` loses stability.
- Forgetting `j >= 0` guard.
- Empty function body (previous bug).

## Interview Follow-ups / Variations

Binary insertion sort; online insertion; link to shell sort gaps.

## Tags

`sorting`, `insertion-sort`, `stable`, `difficulty:easy`
