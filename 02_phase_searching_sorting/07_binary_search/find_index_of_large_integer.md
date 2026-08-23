# Find the Index of the Large Integer

## Problem Statement
[LeetCode 1533](https://leetcode.com/problems/find-the-index-of-the-large-integer/) — array of equal integers except one strictly larger; find its index using `compareSub` on ranges (cannot read values).

- **Inputs:** `ArrayReader` with `length()` and `compareSub(l,r,x,y)`. Premium.
- **Output:** `int` index of the larger element.
- **Valid answer:** the unique index whose range-sum is heavier.
- **Edges:** n odd (middle element); large element at an end.

## Intuition
Comparing equal-length halves tells which half contains the larger value. Recurse like binary search.

## Brute Force → Optimal
- **Brute:** not allowed to scan values.
- **Optimal:** halve with compareSub — O(log N) comparisons.

## Data Structure / Approach Justification
**Chosen:** even length: split in half. Odd: skip the middle and test it when halves tie.

- **vs reading the array:** the API forbids it
- **vs three-way split always:** even/odd handling is enough

## Logic Walkthrough
Even: compare `[lo,mid]` vs `[mid+1,hi]`. Odd: compare `[lo,mid]` vs `[mid+2,hi]`; 0 means index `mid+1`.

## Dry Run
`[7,7,7,7,10,7,7,7]` → heavier right then left-of-right lands on index 4.

## Time & Space Complexity
Time **O(log N)** comparisons. Space **O(1)**. Why: each step discards half the range.

## Trade-offs & Alternatives
Related to finding the heavier coin with a balance scale.

## Common Mistakes / Edge Cases
Mismatched subarray lengths; forgetting the odd-length middle.

## Interview Follow-ups / Variations
Unknown-size search (702); single element in sorted array (540).

## Tags
`binary-search`, `interactive`, `premium`, `leetcode-1533`, `difficulty:medium`
