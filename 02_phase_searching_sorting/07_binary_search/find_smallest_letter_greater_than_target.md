# Find Smallest Letter Greater Than Target

## Problem Statement
[LeetCode 744](https://leetcode.com/problems/find-smallest-letter-greater-than-target/) — sorted circular `letters`; return the smallest letter strictly greater than `target` (wrap to `letters[0]`).

- **Inputs:** `vector<char> letters` (non-decreasing, wrapping), `char target`.
- **Output:** `char`.
- **Valid answer:** upper bound in the circle.
- **Edges:** target ≥ last letter; duplicates; target before first.

## Intuition
The array is sorted, so the first letter `> target` is an upper bound. If none exists, wrap.

## Brute Force → Optimal
- **Brute:** linear scan — O(N).
- **Optimal:** binary search upper bound — O(log N).

## Data Structure / Approach Justification
**Chosen:** half-open `[lo, hi)` search for first `letters[i] > target`.

- **vs linear:** fine for tiny alphabets; log is the intended pattern
- **vs extra copy of letters+first:** unnecessary if wrap is handled at the end

## Logic Walkthrough
If `lo == n`, return `letters[0]`; else return `letters[lo]`.

## Dry Run
`[c,f,j]`, target `c` → first `> c` is `f`. Target `j` → wrap to `c`.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: binary search over n letters.

## Trade-offs & Alternatives
Same template as `std::upper_bound`.

## Common Mistakes / Edge Cases
Returning ≥ instead of >; forgetting wrap-around; assuming unique letters.

## Interview Follow-ups / Variations
Search insert position (35); next permutation of a circular buffer.

## Tags
`binary-search`, `upper-bound`, `leetcode-744`, `difficulty:easy`
