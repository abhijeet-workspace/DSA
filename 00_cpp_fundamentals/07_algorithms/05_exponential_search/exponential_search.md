# Exponential Search

## Problem Statement

Find `target` in a sorted array (especially useful when size is huge/unbounded) by exponentially growing a high bound, then binary searching the window.

## Intuition

If the answer is near the front, doubling finds a range fast without scanning everything first.

## Brute Force → Optimal

Binary search needs known `n`. Exponential search discovers a range containing the target in O(log i) where i is the index.

## Data Structure / Approach Justification

**Chosen:** doubling + binary search helper on `vector`.

- **vs pure binary:** similar O(log N) when N known; exponential helps unbounded lists / very large N with early targets.
- **vs linear:** much faster on sorted data.

## Logic Walkthrough

Handle empty/`arr[0]`. Double `i` while `arr[i] <= target`. Binary search in `[i/2, min(i,n-1)]`.

## Dry Run

Target `35` in multiples of 5: `i` goes 1→2→4→8; window `[4,8]` contains 35 → binary finds index of 35.

## Time & Space Complexity

Time O(log N). Space O(1).

## Trade-offs & Alternatives

Extra phase vs plain binary when N is known and target is uniform.

## Common Mistakes / Edge Cases

- Forgetting empty check.
- Using `min(i,n-1)` incorrectly.
- Applying to unsorted arrays.

## Interview Follow-ups / Variations

Unbounded array search interview variant; galloping search in merge.

## Tags

`exponential-search`, `binary-search`, `difficulty:medium`
