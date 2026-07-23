# Linear Search

## Problem Statement

Given an unsorted array `arr` and a `target`, return the index of the first occurrence, or `-1` if missing.

- **Inputs:** `vector<int>`, `target`.
- **Output:** index or `-1`.
- **Edges:** empty array; duplicates (first wins); target absent.

## Intuition

Without ordering, every element is a candidate — check sequentially.

## Brute Force → Optimal

This *is* the brute-force search. Optimal only when data is unsorted or N is tiny. Sorted data unlocks binary search (O(log N)).

## Data Structure / Approach Justification

**Chosen:** contiguous `vector` + forward scan.

- **vs hash set:** O(1) average membership but loses index unless you store indices; extra memory.
- **vs sorted + binary search:** requires preprocess O(N log N).
- Linear scan wins for one-shot unsorted queries.

## Logic Walkthrough

Loop `i` from `0..n-1`. If `arr[i]==target`, return `i`. After loop return `-1`.

## Dry Run

`arr={5,3,8,4,2,7,1,9}`, `target=4` → compare 5,3,8,4 → return `3`. `target=10` → full scan → `-1`.

## Time & Space Complexity

Time O(N) comparisons worst/average. Space O(1) extra.

## Trade-offs & Alternatives

Simple and cache-friendly. Poor for repeated queries on large static data (preprocess).

## Common Mistakes / Edge Cases

- Returning after last duplicate instead of first (if looping without break).
- Using `size_t` and mixing with `-1` sentinel incorrectly.
- Assuming sorted order.

## Interview Follow-ups / Variations

Find all occurrences; search in linked list; early exit heuristics.

## Tags

`search`, `linear-scan`, `array`, `difficulty:easy`
