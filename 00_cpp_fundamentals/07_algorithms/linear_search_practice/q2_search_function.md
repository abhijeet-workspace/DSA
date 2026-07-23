# Linear Search Function

## Problem Statement
Implement `linearSearch(arr, length, key)` returning index or `-1`. Demo searches for `9` in a 10-element array.

## Intuition
Package the scan in a function so callers stay thin.

## Brute Force → Optimal
Same O(N) scan; function form enables reuse/testing.

## Data Structure / Approach Justification
C-array + length parameter mirrors legacy APIs. Prefer `std::span`/`vector` in modern code for bounds safety.

## Logic Walkthrough
Loop; return on hit; return `-1` after exhaustion.

## Dry Run
Key `9` is at index `9` in the demo array.

## Time & Space Complexity
**Time:** O(N). **Space:** O(1).

## Trade-offs & Alternatives
Template/`std::find` from `<algorithm>` is the STL alternative.

## Common Mistakes / Edge Cases
Wrong length; returning `0` for not-found (ambiguous if key at index 0).

## Interview Follow-ups / Variations
Use iterators; return `std::optional<size_t>`.

## Tags
`topic: searching` · `pattern: linear-scan` · `difficulty: easy`
