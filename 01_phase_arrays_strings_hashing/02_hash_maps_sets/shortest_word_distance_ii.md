# Shortest Word Distance II

## Problem Statement
[LeetCode 244](https://leetcode.com/problems/shortest-word-distance-ii/) — preprocess words; answer many distance queries.

## Intuition
Map word→sorted indices; two-pointer merge for each query.

## Brute Force → Optimal
- **Brute:** scan list each query — O(N) per query.
- **Optimal:** preprocess O(N); query O(P+Q).

## Data Structure / Approach Justification
**Chosen:** hash map of index lists + two pointers.

## Logic Walkthrough
Advance smaller index; track min absolute difference.

## Dry Run
Same examples as I after construction.

## Time & Space Complexity
Preprocess **O(N)**. Query **O(P+Q)**. Space **O(N)**.

## Trade-offs & Alternatives
See intuition / follow-ups.

## Common Mistakes / Edge Cases
Assuming word1 != word2 (problem guarantee).

## Interview Follow-ups / Variations
Word Distance III when words may be equal.

## Tags
`design`, `hash-map`, `two-pointers`, `difficulty:medium`
