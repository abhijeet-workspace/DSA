# Can I Win

## Problem Statement
[LeetCode 464](https://leetcode.com/problems/can-i-win/) — two players pick without replacement from 1..maxChoosableInteger; reach desiredTotal; first wins?

- **Inputs:** `maxChoosableInteger`, `desiredTotal`.
- **Output:** bool first player win with optimal play.
- **Valid answer:** true if first can force win.
- **Edges:** total sum < desired; desired <= max.

## Intuition
Bitmask of used numbers; memo whether current player can force win.

## Brute Force → Optimal
- **Brute:** game tree.
- **Optimal:** O(2^M * M) memo.

## Data Structure / Approach Justification
**Chosen:** memo[mask] = canCurrentWin.

## Logic Walkthrough
If remaining <=0 previous already won; try unused i if remaining-i<=0 or !opp.

## Dry Run
max=10, desired=11 -> **false**.

## Time & Space Complexity
Time **O(2^M*M)**. Space **O(2^M)**. Why: masks (section 4).

## Trade-offs & Alternatives
M<=20.

## Common Mistakes / Edge Cases
Not checking sum < desired early.

## Interview Follow-ups / Variations
Minimax bitmask games.

## Tags
`bitmask-dp`, `game`, `leetcode-464`, `difficulty:medium`
