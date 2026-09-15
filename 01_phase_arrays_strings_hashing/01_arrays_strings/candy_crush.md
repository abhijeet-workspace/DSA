# Candy Crush

## Problem Statement
[LeetCode 723](https://leetcode.com/problems/candy-crush/) — repeatedly mark 3+ equal candies in rows/cols, crush to 0, apply gravity, until stable.

- **Inputs:** `board` of candy ids (0 empty).
- **Output:** stable board after all crushes.
- **Valid answer:** simultaneous mark then crush each round.
- **Edges:** chains after gravity; overlapping matches.

## Intuition
Simulate rounds: mark with negatives (preserve value for multi-match), drop positives downward, clear tops to 0.

## Brute Force → Optimal
- **Brute / Optimal:** simulation is required; mark-then-gravity is the standard O(rounds · mn) approach.

## Data Structure / Approach Justification
**Chosen:** in-place board with negative marks.

- **vs boolean crush mask:** similar; negatives save an array.

## Logic Walkthrough
While something crushed: scan for length-3 windows; mark `-v`; per column compact positives to bottom.

## Dry Run
Bottom `2 2 2` marks and drops; may cascade.

## Time & Space Complexity
Time **O(R · m · n)** rounds until stable. Space **O(1)** extra.

## Trade-offs & Alternatives
Copy board each round for clarity vs in-place marks.

## Common Mistakes / Edge Cases
Crushing sequentially instead of simultaneously; not handling overlapping crosses.

## Interview Follow-ups / Variations
Match-3 with specials; gravity in 4 directions.

## Tags
`simulation`, `matrix`, `leetcode-723`, `difficulty:medium`
