# Custom Sort String

## Problem Statement
[LeetCode 791](https://leetcode.com/problems/custom-sort-string/) — permute `s` so characters follow the relative order in `order`.

- **Inputs:** strings `order`, `s` (lowercase).
- **Output:** any valid permutation of `s`.
- **Edges:** chars in `s` not in `order`; duplicates.

## Intuition
Count frequencies in `s`, emit letters in `order` first, then remaining letters.

## Brute Force → Optimal
- **Brute:** custom comparator sort — O(N log N).
- **Optimal:** count array — O(N + |Σ|).

## Data Structure / Approach Justification
**Chosen:** freq[26] then build string.

## Logic Walkthrough
Count `s`. Append each `order` char `freq` times (zero after). Append leftover a–z.

## Dry Run
`order=cba`, `s=abcd` → `c b a` then `d` → `cbad`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** alphabet (plus output).

## Trade-offs & Alternatives
Stable sort with rank map also works.

## Common Mistakes / Edge Cases
Forgetting characters not in `order`.

## Interview Follow-ups / Variations
Unicode alphabet; preserve relative order of unordered chars.

## Tags
`hash-map`, `sorting`, `string`, `difficulty:medium`
