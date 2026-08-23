# Peak Index in a Mountain Array

## Problem Statement
[LeetCode 852](https://leetcode.com/problems/peak-index-in-a-mountain-array/) — unimodal mountain (strict up then strict down); return the peak index.

- **Inputs:** `vector<int> arr` length ≥ 3.
- **Output:** `int` peak index.
- **Valid answer:** unique index i with `arr[i-1] < arr[i] > arr[i+1]`.
- **Edges:** peak near either end; long climb.

## Intuition
If `arr[mid] < arr[mid+1]` we are on the ascent, so the peak is to the right.

## Brute Force → Optimal
- **Brute:** linear scan of max — O(N).
- **Optimal:** binary search on slope — O(log N).

## Data Structure / Approach Justification
**Chosen:** unimodal search (same as find peak 162 with a guaranteed mountain).

- **vs 162:** 162 allows multiple peaks; 852 guarantees one mountain
- **vs ternary search:** unnecessary with adjacent compare

## Logic Walkthrough
`lo < hi`; climb → `lo = mid+1`; else `hi = mid`.

## Dry Run
`[0,10,5,2]`: mid 1 is 10 > 5 → hi=1 → peak 1.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: slope binary search.

## Trade-offs & Alternatives
Find Peak Element is the version without a guaranteed single mountain.

## Common Mistakes / Edge Cases
Comparing to `arr[mid-1]` without bounds; using `lo <= hi` and skipping the peak.

## Interview Follow-ups / Variations
Find peak element (162); find in mountain array (1095).

## Tags
`binary-search`, `unimodal`, `leetcode-852`, `difficulty:medium`
