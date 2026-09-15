# Shortest Word Distance III

## Problem Statement
[LeetCode 245](https://leetcode.com/problems/shortest-word-distance-iii/) — shortest distance; word1 may equal word2.

## Intuition
One pass; when equal, distance between consecutive occurrences of that word.

## Brute Force → Optimal
- **Brute:** all pairs.
- **Optimal:** one pass tracking previous relevant index.

## Data Structure / Approach Justification
**Chosen:** single previous index with equality-aware update.

## Logic Walkthrough
If word1==word2, update best between consecutive matches. Else classic two-index logic.

## Dry Run
`makes`→`makes` distance 3 in sample.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**.

## Trade-offs & Alternatives
See intuition / follow-ups.

## Common Mistakes / Edge Cases
Double-counting when words differ; forgetting distinct indices when equal.

## Interview Follow-ups / Variations
—

## Tags
`array`, `string`, `difficulty:medium`
