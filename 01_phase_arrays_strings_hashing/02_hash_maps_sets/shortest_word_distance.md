# Shortest Word Distance

## Problem Statement
[LeetCode 243](https://leetcode.com/problems/shortest-word-distance/) — minimum distance between two different words in a list.

## Intuition
Track last seen indices of each word; update min distance whenever either is seen.

## Brute Force → Optimal
- **Brute:** all pairs of occurrences — O(N²).
- **Optimal:** one pass — O(N).

## Data Structure / Approach Justification
**Chosen:** two running indices.

## Logic Walkthrough
On match word1/word2 update index; if both set, `min(|i1-i2|)`.

## Dry Run
`makes` vs `coding` → distance 1.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**.

## Trade-offs & Alternatives
See intuition / follow-ups.

## Common Mistakes / Edge Cases
Updating both when word1==word2 (use II/III variants).

## Interview Follow-ups / Variations
Shortest Word Distance II / III.

## Tags
`array`, `string`, `difficulty:easy`
