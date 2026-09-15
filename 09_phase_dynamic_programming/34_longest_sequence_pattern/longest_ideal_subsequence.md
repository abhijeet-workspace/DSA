# Longest Ideal Subsequence

## Problem Statement
[LeetCode 2370](https://leetcode.com/problems/longest-ideal-subsequence/) — longest subsequence with adjacent |ASCII| diff <= k.

- **Inputs:** `s`, `k`.
- **Output:** length.
- **Valid answer:** max under adjacent constraint in subsequence.
- **Edges:** k=0; k=25.

## Intuition
DP best length ending at each letter; for c take max over [c-k,c+k]+1.

## Brute Force → Optimal
- **Brute:** O(N^2).
- **Optimal:** O(N*26).

## Data Structure / Approach Justification
**Chosen:** best[26] ending letter lengths.

## Logic Walkthrough
Left-to-right: for each char update from window then write.

## Dry Run
s=abcd, k=3 -> **4**; s=acfg, k=2 -> **2**.

## Time & Space Complexity
Time **O(N*26)**. Space **O(26)**. Why: alphabet DP (section 4).

## Trade-offs & Alternatives
Careful in-place neighbor reads.

## Common Mistakes / Edge Cases
Updating before reading neighbors wrongly.

## Interview Follow-ups / Variations
LIS with constraint.

## Tags
`lis`, `leetcode-2370`, `difficulty:medium`
