# Palindromic Substrings

## Problem Statement
[LeetCode 647](https://leetcode.com/problems/palindromic-substrings/) — count palindromic substrings (single chars count).

- **Inputs:** string `s`.
- **Output:** count.
- **Valid answer:** number of palindrome substrings.
- **Edges:** empty; all same.

## Intuition
Expand around each center counting expansions.

## Brute Force → Optimal
- **Brute:** check all O(N^3).
- **Optimal:** O(N^2) expand.

## Data Structure / Approach Justification
**Chosen:** expand centers.

## Logic Walkthrough
For each center, expand while match; ++count each.

## Dry Run
abc -> **3**; aaa -> **6**.

## Time & Space Complexity
Time **O(N^2)**. Space **O(1)**. Why: centers (section 4).

## Trade-offs & Alternatives
DP table also fine.

## Common Mistakes / Edge Cases
Double-counting centers.

## Interview Follow-ups / Variations
Longest Palindromic Substring (5).

## Tags
`string-dp`, `leetcode-647`, `difficulty:medium`
