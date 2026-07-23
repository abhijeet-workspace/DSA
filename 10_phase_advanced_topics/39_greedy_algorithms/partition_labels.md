# Partition Labels

## Problem Statement
[LeetCode 763](https://leetcode.com/problems/partition-labels/) — split a string into as many parts as possible so each letter appears in at most one part; return part lengths.

- **Inputs:** string `s` of lowercase letters.
- **Output:** list of partition lengths (in order).
- **Valid answer:** the unique maximal-part partition lengths.
- **Edges:** all unique letters; one letter repeated; entire string one part.

## Intuition
Precompute each letter’s last index. Grow a window’s `end` to cover every letter seen so far; when `i == end`, cut a partition.

## Brute Force → Optimal
- **Brute:** try all cut positions with set checks — worse.
- **Optimal:** last-occurrence array + one greedy pass — O(N).

## Data Structure / Approach Justification
**Chosen:** `last[26]` + scanning `start`/`end`.

- **vs interval merging of [first,last] per char:** same idea, more code.
- **vs recursion:** unnecessary.

## Logic Walkthrough
Fill `last`. Scan `i`: `end = max(end, last[s[i]])`; if `i==end`, push `end-start+1`, set `start=i+1`.

## Dry Run
`"ababcbacadefegdehijhklij"` → partitions of lengths **9, 7, 8**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** for 26 letters (+ output). Why: each cut is forced by last occurrences (section 4).

## Trade-offs & Alternatives
Interval-merge formulation is clearer to some interviewers; same complexity.

## Common Mistakes / Edge Cases
Using first occurrence instead of last; forgetting to update `end` for every char in the window.

## Interview Follow-ups / Variations
Return the substrings; Unicode / larger alphabet → hash map.

## Tags
`greedy`, `string`, `two-pointers`, `difficulty:medium`
