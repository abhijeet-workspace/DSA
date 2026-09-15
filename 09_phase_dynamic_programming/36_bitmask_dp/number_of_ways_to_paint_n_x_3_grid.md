# Number of Ways to Paint N x 3 Grid

## Problem Statement
[LeetCode 1411](https://leetcode.com/problems/number-of-ways-to-paint-n-x-3-grid/) — paint n x 3 grid with 3 colors; adjacent different; mod 1e9+7.

- **Inputs:** `n`.
- **Output:** ways mod 10^9+7.
- **Valid answer:** valid colorings count.
- **Edges:** n=1.

## Intuition
Classify row colorings into 121-type and 123-type; recurrence / bitmask over row states.

## Brute Force → Optimal
- **Brute:** 3^{3n}.
- **Optimal:** O(n) closed recurrence or O(n*S^2) state DP.

## Data Structure / Approach Justification
**Chosen:** two sequences a_n (121), b_n (123).

## Logic Walkthrough
a=6*121 + 0 initially patterns; LC recurrence.

## Dry Run
n=1 -> **12**; n=2 -> **54**.

## Time & Space Complexity
Time **O(n)**. Space **O(1)**. Why: fixed width (section 4).

## Trade-offs & Alternatives
Generalize to m columns with bitmask of colors.

## Common Mistakes / Edge Cases
Wrong adjacent constraints across rows.

## Interview Follow-ups / Variations
Paint House; grid coloring DP.

## Tags
`bitmask-dp`, `leetcode-1411`, `difficulty:hard`
